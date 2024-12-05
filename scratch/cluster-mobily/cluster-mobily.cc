#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/mobility-module.h"
#include "ns3/ipv4-flow-classifier.h"
#include "ns3/applications-module.h"
#include "ns3/flow-monitor-helper.h"
#include "ns3/netanim-module.h"

#include <vector>
#include <ctime>    // Para o uso do rand

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("ClusteringExample");

// Define a Cluster Manager class to manage clusters
class ClusterManager{
public:
    ClusterManager ();
    void FormClusters (NodeContainer nodes);
    std::vector<NodeContainer> GetClusters () const;  // Método para acessar os clusters privados
    std::vector<Ptr<Node>> GetClusterHeads() const;  // Método para acessar os cluster heads privados
private:
    std::vector<NodeContainer> m_clusters; // Vector of clusters
    std::vector<Ptr<Node>> m_clusterHeads;     // Vector para armazenar os cluster heads como Ptr<Node>
};

ClusterManager::ClusterManager () {}

void ClusterManager::FormClusters (NodeContainer nodes) {
    int clusterSize = 10; // Define the size of each cluster
    int numClusters = nodes.GetN () / clusterSize;

    // Semente para o gerador de números aleatórios
    srand(time(0));

    for (int i = 0; i < numClusters; ++i) {
        NodeContainer cluster;
        for (int j = 0; j < clusterSize; ++j) {
            cluster.Add (nodes.Get (i * clusterSize + j));
        }

        m_clusters.push_back (cluster);
        NS_LOG_INFO ("Formed Cluster " << i << " with nodes:");

        for (uint32_t k = 0; k < cluster.GetN (); ++k) {
            NS_LOG_INFO ("Node " << cluster.Get (k)->GetId ());
        }

        // Escolher um cluster head aleatoriamente para o cluster
        int clusterHeadIndex = rand() % cluster.GetN();  // Seleciona um índice aleatório
        Ptr<Node> clusterHead = cluster.Get(clusterHeadIndex);
        m_clusterHeads.push_back(clusterHead);  // Adiciona o cluster head

        NS_LOG_INFO ("Cluster Head for Cluster " << i << ": Node " << clusterHead->GetId ());
    }
}

// Retorna os clusters formados
std::vector<NodeContainer> ClusterManager::GetClusters () const {
    return m_clusters;
}

// Retorna os cluster heads
std::vector<Ptr<Node>> ClusterManager::GetClusterHeads() const {
    return m_clusterHeads;
}

int main (int argc, char *argv[]) {
    CommandLine cmd;
    cmd.Parse (argc, argv);

    // Create nodes
    NodeContainer nodes;
    nodes.Create (100); // Create 40 nodes

   // Criando o MobilityHelper
        MobilityHelper mobileMobility;

        // Criando o PositionAllocator para distribuir os nós
        Ptr<PositionAllocator> positionAllocator = CreateObject<GridPositionAllocator>();
        positionAllocator->SetAttribute("MinX", DoubleValue(0.0));  // Posição inicial X
        positionAllocator->SetAttribute("MinY", DoubleValue(0.0));  // Posição inicial Y
        positionAllocator->SetAttribute("DeltaX", DoubleValue(20.0));  // Distância entre nós em X
        positionAllocator->SetAttribute("DeltaY", DoubleValue(20.0));  // Distância entre nós em Y
        positionAllocator->SetAttribute("GridWidth", UintegerValue(10));  // Número de nós por linha
        positionAllocator->SetAttribute("LayoutType", StringValue("RowFirst"));  // Layout de linha

        // Definindo o PositionAllocator no MobilityHelper
        mobileMobility.SetPositionAllocator(positionAllocator);

        // Definindo o modelo de mobilidade para cada nó
        mobileMobility.SetMobilityModel("ns3::RandomWaypointMobilityModel",
            "Speed", StringValue("ns3::UniformRandomVariable[Min=1.0|Max=5.0]"), // Velocidade aleatória entre 1 e 5
            "Pause", StringValue("ns3::UniformRandomVariable[Min=0.0|Max=2.0]"), // Pausa aleatória entre 0 e 2 segundos
            "PositionAllocator", PointerValue(positionAllocator));  // Usando o PositionAllocator configurado

        // Instalando o modelo de mobilidade nos nós
        mobileMobility.Install(nodes);

    // Install the Internet stack on the nodes
    InternetStackHelper stack;
    stack.Install (nodes);

    // Set up PointToPoint links for nodes in clusters
    PointToPointHelper pointToPoint;
    NetDeviceContainer devices;

    // Criando um link ponto a ponto entre pares de nós
    for (uint32_t i = 0; i < nodes.GetN(); i += 2) {
        if (i + 1 < nodes.GetN()) {
            NetDeviceContainer pairDevices = pointToPoint.Install (nodes.Get(i), nodes.Get(i+1));
            devices.Add(pairDevices);
        }
    }

    // Atribuindo endereços IP a esses dispositivos
    Ipv4AddressHelper address;
    address.SetBase ("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces = address.Assign(devices);

    // Initialize Cluster Manager
    ClusterManager clusterManager;
    clusterManager.FormClusters (nodes);

    // Acessa os clusters e imprime suas informações
    std::cout << "Clusters and their respective Cluster Heads:" << std::endl;
    int clusterId = 0;
    for (auto &cluster : clusterManager.GetClusters()) {
        std::cout << "Cluster " << clusterId << " com nós: ";
        for (uint32_t i = 0; i < cluster.GetN(); ++i) {
            // Obtém o endereço IP de cada nó
            Ipv4Address ip = interfaces.GetAddress (cluster.Get(i)->GetId());
            std::cout << ip << " ";
        }

        // Imprimir o IP do Cluster Head
        Ipv4Address chIp = interfaces.GetAddress (clusterManager.GetClusterHeads()[clusterId]->GetId());
        std::cout << " - Cluster Head: " << chIp << std::endl;
        clusterId++;
    }

    // Set up server applications on cluster heads
    uint16_t port = 9; // Port number
    UdpEchoServerHelper serverHelper (port);
    ApplicationContainer serverApps;

    // Adiciona servidores aos cluster heads
    for (auto &head : clusterManager.GetClusterHeads()) {
        serverApps.Add (serverHelper.Install (head));  // Instalando no cluster head
    }

    serverApps.Start (Seconds (1.0));
    serverApps.Stop (Seconds (10.0));

    // Set up client applications on cluster members
    UdpEchoClientHelper clientHelper (Ipv4Address ("10.1.1.1"), port);
    clientHelper.SetAttribute ("MaxPackets", UintegerValue (5));
    clientHelper.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    clientHelper.SetAttribute ("PacketSize", UintegerValue (1024));

    ApplicationContainer clientApps;

    // Instala clientes nos outros nós
    for (uint32_t i = 1; i < nodes.GetN (); ++i) {
        clientHelper.SetAttribute ("RemoteAddress", AddressValue (nodes.Get (i / 3 * 3)->GetObject<Ipv4> ()->GetAddress (1, 0).GetLocal ()));
        clientApps.Add (clientHelper.Install (nodes.Get (i)));
    }

    clientApps.Start (Seconds (2.0));
    clientApps.Stop (Seconds (10.0));

    // Enable Flow Monitor
    FlowMonitorHelper flowmonHelper;
    Ptr<FlowMonitor> monitor = flowmonHelper.InstallAll();

    // Configurar exportação para o NetAnim
    AnimationInterface anim ("cluster-mobily.xml");  // Arquivo de saída para o NetAnim

    // Ajustar o tamanho padrão de todos os nós
    for (uint32_t i = 0; i < nodes.GetN(); ++i) {
        anim.UpdateNodeSize(i, 5.0, 5.0); // Tamanho padrão (5x5)
        anim.SetMobilityPollInterval(Seconds(0.1));
    }

    // Obter os cluster heads
    auto clusterHeads = clusterManager.GetClusterHeads();

    // Definir os Cluster Heads como verdes
    for (auto& clusterHead : clusterHeads) {
        anim.UpdateNodeColor(clusterHead->GetId(), 0, 255, 0); // Verde (R=0, G=255, B=0)
        anim.UpdateNodeSize(clusterHead->GetId(), 5.0, 5.0); // Tamanho maior para os cluster heads
    }

    // Run simulation
    Simulator::Stop (Seconds (10.0));
    Simulator::Run ();

    // Print statistics
    monitor->CheckForLostPackets ();
    Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowmonHelper.GetClassifier ());
    std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats ();

    for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator i = stats.begin (); i != stats.end (); ++i) {
        Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (i->first);
        std::cout << "Flow ID: " << i->first << " Src Addr " << t.sourceAddress << " Dst Addr " << t.destinationAddress << std::endl;
        std::cout << "Tx Packets ="  << i->second.txPackets << std::endl;
        std::cout << "Rx Packets =" << i->second.rxPackets << std::endl;
        std::cout << "Throughput: " << i->second.rxBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds () - i->second.timeFirstTxPacket.GetSeconds ()) / 1024 / 1024 << "Mbps" << std::endl;
        std::cout << "Delay: " << i->second.delaySum.GetSeconds() / i->second.rxPackets << " s" << std::endl;
        std::cout << "Packet Loss Ratio: " << (i->second.txPackets - i->second.rxPackets) / static_cast<double>(i->second.txPackets) << std::endl;
    }

    Simulator::Destroy ();

    return 0;
}

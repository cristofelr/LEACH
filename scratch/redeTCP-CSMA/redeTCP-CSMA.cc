// Contruindo rede TCP/CSMA
//By Cristofe Rocha
 
//Biblioteca Essencial
#include "ns3/core-module.h"

//Biblioteca para criar os nos
#include "ns3/node-container.h" //Criar nos em container(grupos) 
#include "ns3/node.h"    // Para trabalhar com nós (Nodes)

//Mobilidade dos nos
#include "ns3/mobility-helper.h"
#include "ns3/mobility-model.h"
#include "ns3/position-allocator.h"

//Ptr cria ponteiros inteligente para os objetos criados
#include "ns3/ptr.h"

//Biblioteca padrão C++ 
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <time.h>  


//Habilitando o NetAnim
#include "ns3/netanim-module.h"

//Biblioteca de rede
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/csma-helper.h" //Configure os links da rede Configura e cria links ponto-a-ponto(enlace)
#include "ns3/csma-net-device.h"
#include "ns3/net-device-container.h" //permite criar um container de rede que abriga os nos

//Biblioteca dos protocolos
#include "ns3/internet-stack-helper.h" //responsavel para instalar o protocolo de ionternet

//Biblioteca para configurar os Ips dos nos
#include "ns3/ipv4-address-helper.h"

//Biblioteca para criar trafego UDP
#include "ns3/udp-echo-helper.h"
#include "ns3/udp-client-server-helper.h"

//Biblioteca para criar aplicacao
#include "ns3/applications-module.h"

/* Biblioteca é usada para configurar e gerenciar o roteamento global de pacotes
em uma rede IPv4.Ela oferece uma maneira prática de 
instalar e configurar o roteador global IPv4 nos nós da simulação, 
possibilitando que esses nós se comuniquem entre si, mesmo em redes mais complexas. */
#include "ns3/ipv4-global-routing-helper.h"

//Biblioteca para capturar informacoes dos dispositivos
#include "ns3/pcap-file.h" 

#define simTime 15 //Tempo de execução da simulação

/* 
Para evitar conflitos de nomes. 
Todas as funcionalidades do NS3 estão dentro do namespace ns3.
*/
using namespace ns3; //Declarando o namespace

//NS_LOG_COMPONENT_DEFINE ("redeTCP-CSMA");

int main (int argc, char * argv[]){

bool verbose = true;
uint32_t numNodes = 32;

CommandLine cmd;
cmd.AddValue("verbose", "Habilitando modo verbose", verbose);
cmd.AddValue("numNodes", "Numero de nos na rede", numNodes);

cmd.Parse(argc, argv);

if (verbose) {
    std::cout << "Modo verbose está ON." << std::endl;
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
}


//*************** Inicio da Topologia*************//
//Criandoum NodeContainer-coleção que gerencia múltiplos objetos Node de nos   
//Cria o container com os nos
ns3::NodeContainer nodeContainer;
nodeContainer.Create(numNodes);

 // Criando um MobilityHelper
  MobilityHelper mobility;

  // Configurando o modelo de mobilidade fixa
  mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");

  // Definindo a posição inicial fixa para os nós
  mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                "MinX", DoubleValue(0.0),
                                "MinY", DoubleValue(0.0),
                                "DeltaX", DoubleValue(100.0), // Espaço entre os nós ao longo do eixo X
                                "DeltaY", DoubleValue(100.0), // Espaço entre os nós ao longo do eixo Y
                                "GridWidth", UintegerValue(4), // Número de nós por linha
                                "LayoutType", StringValue("RowFirst"));

  // Aplicando a configuração de mobilidade aos nós
  mobility.Install(nodeContainer);


 //Configurando a conexão CSMA
 ns3::CsmaHelper csmaConfig;
 //csmaConfig.SetDeviceAttribute("DataRate", StringValue("100Mbps"));
 csmaConfig.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

// Instalando o dispositivo CSMA
ns3::NetDeviceContainer csmaDevices;
csmaDevices = csmaConfig.Install(nodeContainer);

//Criando a pilha de protocolos
ns3::InternetStackHelper stack; //Instancia a biblioteca
stack.Install(nodeContainer); //Chama o metodo install para Instalar a pilha de protocolos nos nós

//Configurando a rede Classe C
ns3::Ipv4AddressHelper redeIP;
redeIP.SetBase("192.168.0.0","255.255.255.0");

// Configura a tabela de roteamento
ns3::Ipv4GlobalRoutingHelper::PopulateRoutingTables (); 

Ipv4InterfaceContainer csmaInterface = redeIP.Assign(csmaDevices);
PacketSinkHelper packetSinkHelper (IpL4Protocol, Address (InetSocketAddress (Ipv4Address(), UdpClient)));

//*************** Fim da Topologia************* 

/*
A topologia posta busca introduzir o uso das classe para manipular inicialmente o Ns3.
Ela servira como recurso para evoluir nas configuracoes
*/

//Criando a aplicacao UDP servidor
ns3::UdpEchoServerHelper echoServer(9);

//Criando um container de ApplicationContainer serverApps;
ns3::ApplicationContainer serverApps; //Criando um container de aplicacoes
serverApps.Add(echoServer.Install(nodeContainer.Get(0))); // Instalando no primeiro servidor

//Setando Ip dos servidores
ns3::Ipv4Address ipServidor1 = csmaInterface.GetAddress(0);

//Mostrando o Ip dos servidores
std::cout << "Endereço IP do servidor 1: " << ipServidor1 << std::endl;

serverApps.Start(Seconds(1.0)); //Tempo para iniciar a aplicacao
serverApps.Stop(Seconds(10.0)); //Tempo para finalizar a aplicacao

// Criando a aplicação UDP cliente
ns3::UdpEchoClientHelper echoClient(csmaInterface.GetAddress(0), 9);  // Para o primeiro servidor
echoClient.SetAttribute("MaxPackets", UintegerValue(1));
echoClient.SetAttribute("Interval", TimeValue(Seconds(1.)));
echoClient.SetAttribute("PacketSize", UintegerValue(1024));

//Criando um container de ApplicationContainer clientApps;
ns3::ApplicationContainer clientApps;

// Instalando o aplicativo em todos os nós do NodeContainer
clientApps = echoClient.Install(nodeContainer);
clientApps.Start(Seconds(2.0));
clientApps.Stop(Seconds(10.0));

// Captura de pacotes para todos os dispositivos CSMA
csmaConfig.EnablePcapAll("redeTCP-csma");

ns3::LogComponentEnable("CsmaHelper", LOG_LEVEL_INFO);

// Configuração da animação
AnimationInterface anim("redeTCP-csma.xml");
anim.SetMaxPktsPerTraceFile(5000);  // Limita cada arquivo de trace a 1000 pacotes
anim.UpdateNodeDescription(nodeContainer.Get(0)->GetId(), "Servidor"); //Setando o nome do servidor
anim.UpdateNodeColor(nodeContainer.Get(0)->GetId(), 0, 255, 0);//Setando a cor do servidor

// Iterando sobre os nós e definindo a posição na animação
    for (uint32_t i = 0; i < numNodes; ++i) {
        Ptr<Node> node = nodeContainer.Get(i);  // Obtém cada nó individualmente
        anim.UpdateNodeSize(node, 15, 15);  // Tamanho do nó: largura 30px, altura 30px
        //anim.SetConstantPosition(node, 10.0 + i * 10.0, 10.0);  // Define uma posição diferente para cada nó
    }
//anim.EnablePacketMetadata();  // Habilita as informações do pacote

ns3::Simulator::Stop(Seconds(simTime)); // Configurando o tempo de execução da simulação

ns3::Simulator::Run(); // Rodando a simulação
ns3::Simulator::Destroy(); // Finalizando a simulação
return 0;
}
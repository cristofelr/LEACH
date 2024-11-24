/* Building network CSMA/TCP/Wifi
  By Cristofe Rocha
  Date: 2024/11/22
*/

// List Utilized Libraries 

// Essential libraries
#include "ns3/command-line.h" // Command line handling

// Core modules
#include "ns3/core-module.h" // Simulation control: exec, time, and events
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/wifi-module.h"
#include "ns3/applications-module.h"
#include "ns3/application-container.h"
#include "ns3/application-helper.h"


// Mobility libraries
#include "ns3/mobility-model.h"
#include "ns3/mobility-helper.h"
#include "ns3/position-allocator.h"

// Container libraries
#include "ns3/node-container.h"
#include "ns3/node.h"
#include "ns3/net-device-container.h"

// Network libraries
#include "ns3/net-device.h"
#include "ns3/wifi-net-device.h"
#include "ns3/net-device-container.h" // Container for network devices

// CSMA libraries
#include "ns3/csma-helper.h"
#include "ns3/csma-net-device.h"
#include "ns3/csma-channel.h"

// Wi-Fi libraries
#include "ns3/wifi-helper.h"
#include "ns3/wifi-mac-helper.h"
#include "ns3/wifi-mac.h"
#include "ns3/wifi-phy.h"


// Stack TCP/IPv4 libraries
#include "ns3/internet-stack-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/ipv4-global-routing-helper.h" // Router library

// Traffic generation libraries
#include "ns3/applications-module.h"

// Traffic libraries
#include "ns3/udp-echo-client.h"
#include "ns3/udp-echo-server.h"

// Capture libraries
#include "ns3/pcap-file.h"

// NetAnim library
#include "ns3/netanim-module.h"

// C++ libraries
#include <iostream> // For input and output operations
#include <stdio.h> // For basic operations
#include <string.h> // String operations
#include <time.h> // Time and date manipulation

// Pointer libraries (smart pointers for created objects)
#include "ns3/ptr.h"

// Logging library
#include "ns3/log.h"


#define SIM_TIME 30 // Simulation time in seconds

using namespace ns3;

// Error Logs 
//NS_LOG_COMPONENT_DEFINE("network-CSMA-TCP-Wifi");

int main(int argc, char *argv[]) {

    uint32_t numNodes = 25;
    bool verbose = true;

    CommandLine cmd;
    cmd.AddValue("Verbose", "Enable verbose mode", verbose);
    cmd.AddValue("NumberNodes", "Number of nodes", numNodes);
    cmd.Parse(argc, argv);

    if (verbose) {
        std::cout << "Verbose mode is ON!" << std::endl;
        LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
        LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
    }

    // Verification of number of nodes
    if (numNodes <= 0) {
        std::cout << "The number of nodes is zero!" << std::endl;
        return 1; // Exit if invalid number of nodes
    }

    // Create container for mobile nodes and fixed AP node
    NodeContainer mobileNodes;
    mobileNodes.Create(numNodes);

    NodeContainer fixedApNode;
    fixedApNode.Create(1);
    //mobileNodes.Add(fixedApNode);

  for (uint32_t i = 0; i < mobileNodes.GetN(); ++i) {
    // Acessa o nó móvel
    Ptr<Node> mobileN = mobileNodes.Get(i);
    if (!mobileN) {
        std::cout << "Erro ao obter o nó " << i << std::endl;
        return -1; // Interrompe se o nó não for encontrado
    }

    // Acessa o ponto de acesso (apenas um nó, então usamos Get(0))
    Ptr<Node> Ap = fixedApNode.Get(0); // Corrigido para acessar o único nó no container
    if (!Ap) {
        std::cout << "Erro ao obter o nó do ponto de acesso." << std::endl;
        return -1; // Interrompe se o nó do ponto de acesso não for encontrado
    }
}
    // CSMA (Carrier Sense Multiple Access) - protocol for access control
    CsmaHelper csma;
    std::cout << "CSMA configuration..." << std::endl;
    csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));
    std::cout << "Devices configured." << std::endl;
    
    // Network configuration
    ns3::NetDeviceContainer csmaDevices;
    std::cout << "Instaling CSMA on csmaDevices ..." << std::endl;
    csmaDevices = csma.Install(mobileNodes);
    std::cout << "Instalation finalized." << std::endl;

   // Wi-Fi channel configuration
    ns3::YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
    ns3::YansWifiPhyHelper phy;
    phy.Set("TxPowerStart", DoubleValue(20.0));  // Potência inicial (dBm)
    phy.Set("TxPowerEnd", DoubleValue(20.0));    // Potência final (dBm)
    phy.SetChannel(channel.Create());

    // MAC layer configuration for Wi-Fi
    ns3::WifiHelper wifiMac;
    wifiMac.SetStandard(WIFI_STANDARD_80211n);
    wifiMac.SetRemoteStationManager("ns3::ConstantRateWifiManager");

    ns3::WifiMacHelper mac;
    Ssid ssid = Ssid("CCLRFull");
    mac.SetType("ns3::StaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false));

    ns3::NetDeviceContainer apDevices;
    apDevices = wifiMac.Install(phy, mac, mobileNodes);
  
     /*
    Mobility model for mobile nodes in a limited area
    The MobilityHelper controls node positioning.
    */

    // Mobility configuration for mobile nodes
    ns3::MobilityHelper mobileMobility;

   // Set position allocator to grid
  mobileMobility.SetPositionAllocator("ns3::GridPositionAllocator",  // Use grid-based position allocator
                                    "MinX", DoubleValue(0.0),  // Minimum X-coordinate
                                    "MinY", DoubleValue(0.0),  // Minimum Y-coordinate
                                    "DeltaX", DoubleValue(10.0),  // Distance between nodes along the X-axis
                                    "DeltaY", DoubleValue(10.0),  // Distance between nodes along the Y-axis
                                    "GridWidth", UintegerValue(5),  // Number of nodes per row in the grid
                                    "LayoutType", StringValue("RowFirst"));  // Node placement layout (row first)


    // Set mobility model for mobile nodes
    mobileMobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
                                    "Bounds", RectangleValue(Rectangle(-50, 50, -50, 50)));

    // Install mobility model on mobile nodes
    mobileMobility.Install(mobileNodes);

    //Position Access Point
   // Position Access Point
    ns3::MobilityHelper fixedMobility;
    fixedMobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");  // Modelo de mobilidade fixa
    fixedMobility.Install(fixedApNode);  // Instala o modelo de mobilidade no nó do AP


    /*
    Fixed AP node configuration
    */

    /* Fixed AP configuration with constant position
    ns3::MobilityHelper fixedMobility;
    fixedMobility.SetPositionAllocator("ns3::ConstantPositionMobilityModel");
    fixedMobility.Install(fixedApNode);

    // Set fixed position for the AP (100, 100, 0)
    Ptr<ConstantPositionMobilityModel> apMobility = fixedApNode.Get(0)->GetObject<ConstantPositionMobilityModel>();
    apMobility->SetPosition(Vector(100.0, 100.0, 0.0)); // Position in X=100, Y=100, Z=0
*/
    // Network stack configuration
    ns3::InternetStackHelper stack;
    stack.Install(mobileNodes);
    
    // IP address configuration
    ns3::Ipv4AddressHelper address;
    address.SetBase("192.168.10.0", "255.255.255.0");

    ns3::Ipv4InterfaceContainer csmaInterfaces;
    csmaInterfaces = address.Assign(csmaDevices);

    address.Assign(apDevices);
    address.Assign(csmaDevices);

    ns3::Ipv4GlobalRoutingHelper::PopulateRoutingTables();
  
    // Setup UDP Echo server setup
    ns3::UdpEchoServerHelper echoServer(9);

    //Criando um container de ApplicationContainer serverApps;
    ns3::ApplicationContainer serverApps = echoServer.Install (mobileNodes.Get(1)); // Server is installed on the AP node
    serverApps.Start(Seconds(0.5));  // Server starts at time 1.0
    serverApps.Stop(Seconds(10.0));  // Server stops at time 10.0

    //Setando Ip dos servidores
    ns3::Ipv4Address ipServidor1 = csmaInterfaces.GetAddress(0);

    //Mostrando o Ip dos servidores
    std::cout << "Endereço IP do servidor 1: " << ipServidor1 << std::endl;

    // UDP Echo client setup
    ns3::UdpEchoClientHelper echoClient (InetSocketAddress (Ipv4Address ("192.168.10.1"), 9));  // IP do servidor
    echoClient.SetAttribute("MaxPackets", UintegerValue(10));
    echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient.SetAttribute("PacketSize", UintegerValue(1024));

   //Criando um container de ApplicationContainer clientApps;
    ns3::ApplicationContainer clientApps;

    // Instalando o aplicativo em todos os nós do NodeContainer
    clientApps = echoClient.Install(mobileNodes.Get(0));
    clientApps.Start(Seconds(2.0));
    clientApps.Stop(Seconds(100.0));

    // Enable packet capture for CSMA devices
    AsciiTraceHelper ascii;
    csma.EnablePcapAll("redeTCP-wifi");
    

    // Enable logging for CSMA helper
    LogComponentEnable("CsmaHelper", LOG_LEVEL_INFO);

    // Animation setup
    // Animation setup
    ns3::AnimationInterface anim("redeTCP-wifi.xml");
    anim.SetMaxPktsPerTraceFile(5000);  // Limit each trace file to 5000 packets

    // Update the node size (width and height) for the animation
    for (uint32_t i = 0; i < mobileNodes.GetN(); ++i) {
        Ptr<Node> node = mobileNodes.Get(i);  // Get each mobile node
        anim.UpdateNodeSize(node, 2, 2);  // Set node size (10x10 px) for the animation (smaller nodes)
    }

      // Update the fixed AP node size and color (optional)
      anim.UpdateNodeSize(fixedApNode.Get(0), 2, 2);  // Set fixed AP node size to (15x15 px)
      anim.UpdateNodeDescription(fixedApNode.Get(0)->GetId(), "Access Point");  // Label the AP as "Access Point"
      anim.UpdateNodeColor(fixedApNode.Get(0)->GetId(), 0, 255, 0);  // Set AP node color to green (RGB: 0, 255, 0)

      // Enable traffic between mobile nodes and the access point
      anim.EnablePacketMetadata(true);  // Enable packet metadata (visibility of the arrows)
      // Start the simulation
    ns3::Simulator::Stop(Seconds(SIM_TIME)); // Set simulation run time
    ns3::Simulator::Run(); // Run the simulation
    ns3::Simulator::Destroy(); // Destroy the simulator

    return 0;
}

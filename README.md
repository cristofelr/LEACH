# LEACH
#By Cristofe Rocha, Teacher Renato Moriz and Teacher Paulo
#Informatic center of federal university from Pernambuco estate of Brazil.

https://www.nsnam.org/releases/ns-3-43/

Wireless  sensor  network  (WSN)  is  the  group  of  sensing  computing  and  communication components that gives ability to sense a physical phenomenon in a specified environment. The sensor has small tiny OS having a capability of sensing physical phenomena and transfer to its base station. The main problem of WSN is energy consumption, to avoid such problems different type  of  routing  protocols  are  used.  LEACH  routing  protocol  used  to  reduce  the  energy consumption and enhance the network lifetime. LEACH is a homogeneous WSN protocol and it has  some limitations.  There  are  few versions  of  LEACH homogeneous  protocol  such as  A-LEACH, B-LEACH, T-LEACH and MOD-LEACH.  To overcome  limitation of homogeneous LEACH protocol heterogeneous  LEACH  protocol is used.  In heterogeneous LEACH different nodes with different battery power. Sensor nodes have two types, normal node used for sensing and advanced node used for transmitting the data to the sink node.  Sink node is a sensor node which  has  large  energy  capacity  and  it collects  data  from  other  node.  Sometime  sink  node affected by different type of attack such as sinkhole, black hole attack, when sink node suffered from  these  type of  attacks whole  network  will  get vulnerable.  Because  malicious  node alter routing  table  and  attracts all  traffic  hence,  destination  didn’t  get  any packet  which  is  coming from source because of malicious node.   To avoid these types of attack various technique are used such as intrusion detection, path rater and watchdog scenario. In intrusion detection one system is present in network which monitors the entire network if any illegal behavior observed it report to the sink node immediately. Path rater function  is used to  validate route.  When source node  send packet to  the destination via multiple  hope then  each node  automatically update  their  routing  table  and  route cache.  It is beneficial to sink node maintaining the data of all sensor nodes. Watchdog set the timer when it transmit packet. If the  packet  didn’t reach to the destination  within  allocated time then counter reaches the  threshold value and  source node identify malicious node  then source node  delete  route cache of that malicious node  and  stop working of that node. Hence it will  detects and prevent  the attack.


Low Energy Adaptive Clustering Hierarchy (LEACH) in ns3
#####What? A simulation in ns3 of the clustering and energy profiles of a Wireless sensor network WSN based on the LEACH , mainting a low energy footprint to extend the lifetime of the clusters and hence the lifetime of the network.

#####How? Download and extract the project into your ns3 root src directory and execute the build by running
Instalacao do NS2


sequencia:

cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43
./ns3 clean       # Limpa a compilação anterior, se necessário
./ns3 configure   # Configura novamente, se você não tiver certeza
./ns3 build      # Compila o projeto
./ns3 run scratch/Leach   # Ou outro arquivo que você tenha

baixar o arquivo 
instalr as bilbiotecas
buildar  com ./build.py --enable-examples --enable-tests no raiz 

Cristofe netanim-3.109 % qmake NetAnim.pro CONFIG+=sdk_no_version_check
(base) cristoferocha@MacBook-Air-de-Cristofe netanim-3.109 % make     


copiar um exemplo do example/tutorial/first.cc para o scratch
compilar o exemplo com o ./ns3 run scratch/first.cc

compilar o xml do exemplo no caminho  Documents/ns-allinone-3.43/ns-3.43/build/scratch em  com o Netamim

$ ./NetAnim  Documents/ns-allinone-3.43/ns-3.43/build/scratch.fisrt.xml

$./ns3 clean
$./ns3 configure --enable-examples --enable-tests
$./ns3 build
$./waf --run scratch/leach


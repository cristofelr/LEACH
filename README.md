Prezados pesquisadores,

Aqui apresento a voces um estudo focado no algoritimo de LEACH (Low-Energy Adaptive Clustering Hierarchy)em português protocolo de baixo consumo de energia para Agrupamento Adaptativo e hierárquico. É um protocolo de comunicação eficiente em termos de energia projetado para redes de sensores sem fio (WSN - Wireless Sensor Networks). Seu principal objetivo é prolongar a vida útil da rede, reduzindo o consumo de energia. A abordagem do LEACH é baseada na formação de clusters e na rotação dos “cluster heads” (cabeças de cluster), que são responsáveis pela coleta de dados dos sensores do cluster e pela comunicação direta com a base (sink). 

Para simular o protocolo utilizaremos o simulador NS3 cuja documentação pode ser encontrada no site https://www.nsnam.org/docs/tutorial-pt-br/html/index.html . O NS3 é um simulador de eventos discretos. As versões do ns-3 são lançadas duas ou três vezes por ano e são disponibilizadas principalmente como arquivos de origem compactados. Download (https://www.nsnam.org/releases/).

A ultima versão ja contem o NetAnim network animator, trata-se de uma interface gráfica para facilitar a visualização da simulação. Então vamos lá, baixe o ns3 e mãos a obra.

Para compila o projeto habilitando os exemplos entre na pasta raiz compile o ns3 (https://www.nsnam.org/docs/tutorial-pt-br/html/getting-started.html#obtendo-o-ns-3-compactado-tarball ):

ns-allinone-3.43$./build.py --enable-examples --enable-tests

Agora vamos contruir o ns3, fique atento as diferenças contidas nas ultimas versões. Ao invéz do “waf” utilize o comando “ns3”. Entre na pasta ns-3.43 e vamos construir o ns3: ):

ns-allinone-3.43/ns-3.43$./ns3 configure
ns-allinone-3.43/ns-3.43$./ns3 build

Agora realize o seu primeiro teste com o programa hello-simulator contido na pasta ns-3.43/Scratch/examples:

ns-allinone-3.43/ns-3.43$./ns3 --run scratch/example/hello-simulator

Obs.: O ns3 deve ser executado do local ns-allinone-3.43/ns-3.43.

Para executar qualquer programa use:
ns-allinone-3.43/ns-3.43$./ns3 --run <local/nome_programa>

Como disse o ns3 é um simulador de eventos discretos, ou seja, que alteram ao longo do tempo. Outrossim, é que ele usa contêineres. Para criar a rede, primeiro voce deverá criar um NodeContainer com os sensores(nodes) e em seguida criar outro NetDeviceContainer que será a rede onde colocará os sensores(nodes). A dinâmica é essa, um contêiner dentro do outro. Agora basta se familiarizar com o ns3 e simular suas primeiras redes (https://www.nsnam.org/docs/tutorial-pt-br/html/conceptual-overview.html
 ). Insira todos os seus programas na pasta scratch.

Depois de estar familiarizado com ns3, baixe os arquivos do leach do diretorio scratch/model e rode o ns-allinone-3.43/ns-3.43$./ns3 --run scratch/mode/leach.cc e vamos contribuir.

Em caso de contribuição, caso queira enviar para cclr@cin.ufpe.br.

Esta é uma iniciativa do Centro de Informática da Universidade Federal de Pernambuco Cin/UFPE. Professor Renato Mariz e Paulo Filipe.

Cristofe C Rocha
Doutorando Cin/UFPE.


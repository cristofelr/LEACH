Prezados pesquisadores,

Aqui apresento a voces um estudo focado no algoritimo de LEACH (Low-Energy Adaptive Clustering Hierarchy)em portugues protocolo de baixo consumo de energia para Agrupamento Adaptativo e hierarquico. Trata-se de um protocolo de comunicacao eficiente em termos de energia projetado para redes de sensores sem fio (WSN - Wireless Sensor Networks). Seu principal objetivo e prolongar a vida util da rede, reduzindo o consumo de energia. A abordagem do LEACH e baseada na formacao de cluster e na rotacao dos cluster heads (cabecas de cluster), que sao responsaveis pela coleta de dados dos sensores do cluster e pela comunicacao direta com a base (sink). 

Para simular o protocolo utilizaremos o simulador NS3 cuja documentacao pode ser encontrada no site https://www.nsnam.org/docs/tutorial-pt-br/html/index.html . O NS3 e um simulador de eventos discretos. As versoes do ns-3 sao lancadas duas ou tres vezes por ano e sao disponibilizadas principalmente como arquivos de origem compactados. Download (https://www.nsnam.org/releases/).

A ultima versao ja contem o NetAnim network animator, trata-se de uma interface grafica para facilitar a visualizacao da simulacao. Entao vamos la, baixe o ns3 e maos a obra.

Para compila o projeto habilitando os exemplos entre na pasta raiz compile o ns3 (https://www.nsnam.org/docs/tutorial-pt-br/html/getting-started.html#obtendo-o-ns-3-compactado-tarball ):

ns-allinone-3.43$./build.py --enable-examples --enable-tests

Agora vamos contruir o ns3, fique atento as diferencas contidas nas ultimas vers›es. Ao invez do waf utilize o comando ns3. Entre na pasta ns-3.43 e vamos construir o ns3: ):

ns-allinone-3.43/ns-3.43$./ns3 configure
ns-allinone-3.43/ns-3.43$./ns3 build

Agora realize o seu primeiro teste com o programa hello-simulator contido na pasta ns-3.43/Scratch/examples:

ns-allinone-3.43/ns-3.43$./ns3 --run scratch/example/hello-simulator

Obs.: O ns3 deve ser executado do local ns-allinone-3.43/ns-3.43.

Para executar qualquer programa use:
ns-allinone-3.43/ns-3.43$./ns3 --run <local/nome_programa>

Como disse o ns3 e um simulador de eventos discretos, ou seja, que alteram ao longo do tempo. Outrossim, e que ele usa conteineres. Para criar a rede, primeiro voce devera criar um NodeContainer com os sensores(nodes) e em seguida criar outro NetDeviceContainer que sera a rede onde colocara os sensores(nodes). A dinamica Ž essa, um conteiner dentro do outro. Agora basta se familiarizar com o ns3 e simular suas primeiras redes (https://www.nsnam.org/docs/tutorial-pt-br/html/conceptual-overview.html
 ). Insira todos os seus programas na pasta scratch.

Depois de se familiarizar com ns3, baixe os arquivos do leach do diretorio scratch/model e rode o ns-allinone-3.43/ns-3.43$./ns3 --run scratch/mode/leach.cc e vamos contribuir.

Em caso de contribuicao, caso queira enviar para cclr@cin.ufpe.br.

Esta e uma iniciativa do Centro de Informatica da Universidade Federal de Pernambuco Cin/UFPE. Professor Renato Mariz e Professor Paulo Filipe.

Cristofe C Rocha
Doutorando Cin/UFPE.


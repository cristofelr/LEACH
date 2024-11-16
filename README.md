Prezados pesquisadores,

Aqui apresento a voces um estudo focado no algoritimo de LEACH (Low-Energy Adaptive Clustering Hierarchy)em portugu�s protocolo de baixo consumo de energia para Agrupamento Adaptativo e hier�rquico. � um protocolo de comunica��o eficiente em termos de energia projetado para redes de sensores sem fio (WSN - Wireless Sensor Networks). Seu principal objetivo � prolongar a vida �til da rede, reduzindo o consumo de energia. A abordagem do LEACH � baseada na forma��o de clusters e na rota��o dos �cluster heads� (cabe�as de cluster), que s�o respons�veis pela coleta de dados dos sensores do cluster e pela comunica��o direta com a base (sink). 

Para simular o protocolo utilizaremos o simulador NS3 cuja documenta��o pode ser encontrada no site https://www.nsnam.org/docs/tutorial-pt-br/html/index.html . O NS3 � um simulador de eventos discretos. As vers�es do ns-3 s�o lan�adas duas ou tr�s vezes por ano e s�o disponibilizadas principalmente como arquivos de origem compactados. Download (https://www.nsnam.org/releases/).

A ultima vers�o ja contem o NetAnim network animator, trata-se de uma interface gr�fica para facilitar a visualiza��o da simula��o. Ent�o vamos l�, baixe o ns3 e m�os a obra.

Para compila o projeto habilitando os exemplos entre na pasta raiz compile o ns3 (https://www.nsnam.org/docs/tutorial-pt-br/html/getting-started.html#obtendo-o-ns-3-compactado-tarball ):

ns-allinone-3.43$./build.py --enable-examples --enable-tests

Agora vamos contruir o ns3, fique atento as diferen�as contidas nas ultimas vers�es. Ao inv�z do �waf� utilize o comando �ns3�. Entre na pasta ns-3.43 e vamos construir o ns3: ):

ns-allinone-3.43/ns-3.43$./ns3 configure
ns-allinone-3.43/ns-3.43$./ns3 build

Agora realize o seu primeiro teste com o programa hello-simulator contido na pasta ns-3.43/Scratch/examples:

ns-allinone-3.43/ns-3.43$./ns3 --run scratch/example/hello-simulator

Obs.: O ns3 deve ser executado do local ns-allinone-3.43/ns-3.43.

Para executar qualquer programa use:
ns-allinone-3.43/ns-3.43$./ns3 --run <local/nome_programa>

Como disse o ns3 � um simulador de eventos discretos, ou seja, que alteram ao longo do tempo. Outrossim, � que ele usa cont�ineres. Para criar a rede, primeiro voce dever� criar um NodeContainer com os sensores(nodes) e em seguida criar outro NetDeviceContainer que ser� a rede onde colocar� os sensores(nodes). A din�mica � essa, um cont�iner dentro do outro. Agora basta se familiarizar com o ns3 e simular suas primeiras redes (https://www.nsnam.org/docs/tutorial-pt-br/html/conceptual-overview.html
 ). Insira todos os seus programas na pasta scratch.

Depois de estar familiarizado com ns3, baixe os arquivos do leach do diretorio scratch/model e rode o ns-allinone-3.43/ns-3.43$./ns3 --run scratch/mode/leach.cc e vamos contribuir.

Em caso de contribui��o, caso queira enviar para cclr@cin.ufpe.br.

Esta � uma iniciativa do Centro de Inform�tica da Universidade Federal de Pernambuco Cin/UFPE. Professor Renato Mariz e Paulo Filipe.

Cristofe C Rocha
Doutorando Cin/UFPE.


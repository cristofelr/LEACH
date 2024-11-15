#include "ns3/core-module.h"
#include <fstream>

NS_LOG_COMPONENT_DEFINE("CriandoLog");

using namespace ns3;

int main(int argc, char *argv[])
{
    CommandLine cmd(__FILE__);  // Registra o nome do arquivo fonte
    cmd.Parse(argc, argv);

    // Criando ou abrindo um arquivo de log
    std::ofstream logFile;
    logFile.open("simulation_log.txt", std::ios::app);  // Abrindo o arquivo para append
    if (logFile.is_open())
    {
        logFile << "Script: " << __FILE__ << " executed." << std::endl;
        logFile << "Command-line arguments:" << std::endl;
        for (int i = 0; i < argc; i++)
        {
            logFile << argv[i] << " ";
        }
        logFile << std::endl;
        logFile.close();
    }
    
    NS_LOG_INFO("Simulation starting...");
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
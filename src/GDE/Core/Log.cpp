#include <GDE/Core/Log.hpp>

namespace GDE
{
    
bool Log::initialized = false;
time_t Log::rawtime;
std::string Log::logFileName;

    void Log::init(){
        if(!initialized){
            logFileName = "log.txt";
            initialized = true;
            std::cout << "Sistema de Log inicializado" << std::endl;
            Log::info("init", "Sistema de Log inicializado");
        }
    }

    void Log::info(std::string tag, std::string text)
    {
        if (!initialized)
        {
            std::cout << "El sistema de log no ha sido inicializado, por favor, inicielo mediante GDE::Log::init()" << std::endl;
            return;
        }
        std::ofstream logFile(logFileName.c_str(), std::ofstream::app);
        time (&rawtime);
        char buffer [20];
        struct tm * timeinfo;
        timeinfo = localtime (&rawtime);
        strftime (buffer,20,"%D %T ",timeinfo);
        logFile << buffer << "INFO: " << tag << ": " << text << std::endl;
        logFile.close();
    }
    
    void Log::debug(std::string tag, std::string text)
    {
        if (!initialized)
        {
            std::cout << "El sistema de log no ha sido inicializado, por favor, inicielo mediante GDE::Log::init()" << std::endl;
            return;
        }
        std::ofstream logFile(logFileName.c_str(), std::ofstream::app);
        time (&rawtime);
        char buffer [20];
        struct tm * timeinfo;
        timeinfo = localtime (&rawtime);
        strftime (buffer,20,"%D %T ",timeinfo);
        logFile << buffer << "DEBUG: " << tag << ": " << text << std::endl;
        logFile.close();
    }
    
    void Log::error(std::string tag, std::string text)
    {
        if (!initialized)
        {
            std::cout << "El sistema de log no ha sido inicializado, por favor, inicielo mediante GDE::Log::init()" << std::endl;
            return;
        }
        std::ofstream logFile(logFileName.c_str(), std::ofstream::app);
        time (&rawtime);
        char buffer [20];
        struct tm * timeinfo;
        timeinfo = localtime (&rawtime);
        strftime (buffer,20,"%D %T",timeinfo);
        logFile << buffer << "ERROR: " << tag << ": " << text << std::endl;
        logFile.close();
    }
}

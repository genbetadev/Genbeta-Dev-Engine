#include <GDE/Config.hpp>
#include <GDE/Core/Log.hpp>

namespace GDE
{
    
bool Log::initialized = false;
time_t Log::rawtime;
std::string Log::logFileName;
std::string Log::header[] = {"INF", "DBG", "ERR"};

void Log::init(std::string logFileName)
{
	if(!initialized)
	{
		Log::logFileName = logFileName;
		initialized = true;
		std::cout << "Sistema de Log inicializado" << std::endl;
		std::ofstream logFile(Log::logFileName.c_str(), std::ofstream::app);
		time (&rawtime);
		char buffer[20];
		struct tm * timeinfo;
		timeinfo = localtime(&rawtime);
		strftime(buffer, 20, "%d/%m/%y %X ", timeinfo);
		logFile << std::endl;
		logFile << "=====================================================================";
		logFile << std::endl;
		logFile << buffer << "SISTEMA DE LOG INICIALIZADO" << std::endl;
		logFile << "=====================================================================";
		logFile << std::endl;
		logFile.close();
	}
}

void Log::info(std::string tag, std::string text)
{
	Log::log(tag, text, GDE::infoLevel);
}

void Log::debug(std::string tag, std::string text)
{
#ifdef GDE_DEBUG
   Log::log(tag, text, GDE::debugLevel);
#endif // GDE_DEBUG
}

void Log::error(std::string tag, std::string text)
{
   Log::log(tag, text, GDE::errorLevel);
}

void Log::log(std::string tag, std::string text, int logType)
{
	if (!initialized)
	{
		std::cout << "El sistema de log no ha sido inicializado, por favor, inicielo mediante GDE::Log::init()" << std::endl;
		return;
	}
	std::ofstream logFile(Log::logFileName.c_str(), std::ofstream::app);
	time (&rawtime);
	char buffer [20];
	struct tm * timeinfo;
	timeinfo = localtime (&rawtime);
	strftime (buffer,20,"%d/%m/%y %X ",timeinfo);
	logFile << buffer << header[logType] << ": " << tag << ": " << text << std::endl;
	logFile.close();
  
}


} // namespace GDE

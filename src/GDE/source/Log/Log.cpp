//#include <GDE/Config.hpp>
#include "GDE/Log/Log.hpp"
#include <iostream>
#include <fstream>


static std::string headerStringList[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

// Controlador por defecto. Este método es llamado por el destructor de GDE::Log cada vez que
// un mensaje debe ser escrito al flujo. Si no se ha instalado un controlador personalizado
// se usará este.
static void defaultLogHandler (std::ostream &os,
							   GDE::Log::LogLevel level,
							   const std::string &message,
							   const std::string &date,
							   const std::string &time,
							   const GDE::Log::SourceContext &context
							  )
{
	os << time << " " << headerStringList[level] << ": ";
	if (level == GDE::Log::Error)
	{
		os << context.file << ":" << context.line << ": ";
	}
	os << message;
}

namespace GDE { namespace Log
{

bool Log::initialized = false;
time_t Log::rawtime;
std::ostream *Log::outputStream = NULL;
LogHandler Log::handler = defaultLogHandler;



Log::Log (LogLevel level, const char *file, int line, const char *function)
	: context(file, line, function)
{
	// Asume autoespaciado por defecto
	this->autoSpacing = true;
	this->level = level;
}


Log::~Log ()
{
	if (!initialized)
	{
		std::cerr << "El sistema de log no ha sido inicializado o ha sido cerrado.";
		std::cerr << "Por favor, inicielo mediante GDE::Log::init()" << std::endl;
		return;
	}

	// Se asegura que siempre exista un handler instalado o se use el handler por defecto
	if (!handler)
	{
		handler = defaultLogHandler;
	}

	// Llama al handler instalado pasando los parámetros necesarios.
	// TODO Separar la fecha de la hora.
	(*handler)(*outputStream, level, textStream.str(), "---", actualTimeToText(), context);
	*outputStream << std::endl;
}


void Log::init (std::ostream &stream)
{
	if (!initialized)
	{
		initialized = true;
		outputStream = &stream;
		std::cout << "Sistema de Log inicializado" << std::endl;

		*outputStream << std::endl;
		*outputStream << "=====================================================================";
		*outputStream << std::endl;
		*outputStream << actualTimeToText() << "SISTEMA DE LOG INICIALIZADO" << std::endl;
		*outputStream << "=====================================================================";
		*outputStream << std::endl;
	}
}

void Log::close ()
{
	initialized = false;
	outputStream = NULL;
	std::cout << "Sistema de Log cerrado" << std::endl;
}


Log& Log::operator<< (bool b)
{
	this->textStream << (b ? "true" : "false");
	return maybeSpace();
}

Log& Log::operator<< (const std::string &str)
{
	this->textStream << "\"" << str << "\"";
	return maybeSpace();
}


Log& Log::space (Log &o)
{
	o.autoSpacing = true;
	return o;
}

Log& Log::nospace (Log &o)
{
	o.autoSpacing = false;
	return o;
}


Log& Log::maybeSpace()
{
	if (this->autoSpacing)
	{
		textStream << ' ';
	}

	return *this;
}

std::string Log::actualTimeToText()
{
	time (&rawtime);
	char buffer[20];
	struct tm * timeinfo;
	timeinfo = localtime(&rawtime);
	strftime(buffer, 20, "%d/%m/%y %X ", timeinfo);

	return buffer;
}

} } // namespace GDE::Log

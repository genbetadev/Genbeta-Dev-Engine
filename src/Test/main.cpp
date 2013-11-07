#include <GDE/Core.hpp>
#include <iostream> // Quitar

int main(int argc, char** argv)
{
	GDE::ConfigCreate f;

	f.open("prueba.cfg");
	f.putSection("window");
	f.putValue("width", "640");
	f.putValue("height", "480");
	f.putValue("bpp", "32");
	f.putBlankLine();
	f.putSection("other");
	f.putValue("ecece", "kjefi");
	f.putValue("hhyy", "daasaf");
	f.putValue("efefe", "scjys");
	f.close();

	GDE::ConfigReader conf;
	conf.loadFromFile("window.cfg");

	std::cout << conf.GetUint32("window", "width", 0) << std::endl;

	GDE::App anApp;
	
	anApp.run();
	
	return 0;
}
#include <GDE/Core.hpp>
#include <iostream> // Quitar

int main(int argc, char** argv)
{
	GDE::ConfigCreate f;

	f.Open("prueba.cfg");
	f.PutSection("window");
	f.PutValue("width", "640");
	f.PutValue("height", "480");
	f.PutValue("bpp", "32");
	f.PutBlankLine();
	f.PutSection("other");
	f.PutValue("ecece", "kjefi");
	f.PutValue("hhyy", "daasaf");
	f.PutValue("efefe", "scjys");


	GDE::ConfigReader conf;
	conf.loadFromFile("window.cfg");

	std::cout << conf.GetUint32("window", "width", 0) << std::endl;

	GDE::App anApp;
	
	anApp.run();
	
	return 0;
}
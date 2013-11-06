#include <GDE/Core.hpp>
#include <iostream> // Quitar

int main(int argc, char** argv)
{
	GDE::ConfigReader conf;
	conf.loadFromFile("window.cfg");

	std::cout << conf.GetUint32("window", "width", 0);

	GDE::App anApp;
	
	anApp.run();
	
	return 0;
}
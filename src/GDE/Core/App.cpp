#include <GDE/Core/App.hpp>
#include <GDE/Core/Log.hpp>

namespace GDE
{

App::App()
	: window(sf::VideoMode(800, 480, 32), "Genbeta Dev Engine")
{
	// Se inicializa el sistema de loggin
	GDE::Log::init();
	
	GDE::Log::info("App::App()", "Constructor llamado");
}

App::~App()
{
	GDE::Log::info("App::~App()", "Destructor llamado");
}

void App::run()
{
	while(this->window.isOpen())
	{
		sf::Event event;
		while(this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->window.close();
			}
		}
		
		this->window.clear(sf::Color(180, 200, 255));
		this->window.display();
	}
}
	
} // namespace GDE
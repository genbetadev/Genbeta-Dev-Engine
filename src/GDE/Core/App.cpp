#include <GDE/Core/App.hpp>

#include <string>
#include <map>

namespace GDE
{

App::App()
	: window(sf::VideoMode(800, 480, 32), "Genbeta Dev Engine")
{	
}

App::~App()
{
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
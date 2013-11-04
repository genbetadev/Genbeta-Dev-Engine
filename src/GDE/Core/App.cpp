#include <GDE/Core/App.hpp>

namespace GDE
{

App::App()
	: mWindow(sf::VideoMode(800, 480, 32), "Genbeta Dev Engine")
{	
}

App::~App()
{
}

void App::run()
{
	while(mWindow.isOpen())
	{
		sf::Event event;
		while(mWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				mWindow.close();
		}
		
		mWindow.clear(sf::Color(180, 200, 255));
		mWindow.display();
	}
}
	
} // namespace GDE
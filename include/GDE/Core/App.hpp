#ifndef GDE_CORE_APP_HPP
#define GDE_CORE_APP_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Config.hpp>

namespace GDE
{
	
class GDE_API App
{
public:
	App();
	~App();
	
	void run();
	
private:
	sf::RenderWindow mWindow;
}; // class App
	
} // namespace GDE

#endif // GDE_CORE_APP_HPP
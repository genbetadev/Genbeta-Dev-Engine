#ifndef SCENE_MAIN_HPP
#define SCENE_MAIN_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Core/Core.hpp>

class SceneMain : public GDE::Core::Scene
{
public:
	SceneMain(GDE::Core::sceneID theID);
	
	~SceneMain();

	void init();

	void active();

	void desactive();

	void update();

	void event(sf::Event theEvent);

	void resume();

	void pause();

	void draw();

	void cleanup();
	
private:
	// Referencia a la ventana
	sf::RenderWindow& window;
	// Puntero al SceneManager
	GDE::Core::SceneManager* sm;
	sf::Text text;
	sf::Font font;
};

#endif // SCENE_MAIN_HPP

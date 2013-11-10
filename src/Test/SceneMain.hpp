#ifndef SCENE_MAIN_HPP
#define SCENE_MAIN_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Core.hpp>

class SceneMain : public GDE::Scene
{
public:
	SceneMain(GDE::sceneID theID);
	
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
	GDE::SceneManager* sm;
	sf::Text text;
	sf::Font font;
};

#endif // SCENE_MAIN_HPP

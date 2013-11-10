#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Core.hpp>

class SceneGame : public GDE::Scene
{
public:
	SceneGame(GDE::sceneID theID);
	
	~SceneGame();
	
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
	sf::RenderWindow& window;
	sf::Text text;
	sf::Font font;
};

#endif // SCENE_GAME_HPP

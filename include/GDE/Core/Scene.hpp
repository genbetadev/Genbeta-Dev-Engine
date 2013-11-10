#ifndef GDE_CORE_SCENE_HPP
#define GDE_CORE_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Core/CoreTypes.hpp>

namespace GDE
{
	
class Scene : sf::NonCopyable
{
public:
	virtual ~Scene();
	
	const sceneID& getID() const;
	
	void setBackgroundColor(const sf::Color& theColor);
	
	const sf::Color& getBackgroundColor() const;

	virtual void init() = 0;

	virtual void active() = 0;

	virtual void desactive() = 0;

	virtual void update() = 0;

	virtual void event(sf::Event theEvent) = 0;

	virtual void resume() = 0;

	virtual void pause() = 0;

	virtual void draw() = 0;

	virtual void cleanup() = 0;
	
protected:
	Scene(sceneID theID);

private:
	/// ID único de la escena
	sceneID id;
	/// Color de fondo de la escena
	sf::Color colorBack;
	
}; // class Scene
	
} // namespace GDE

#endif // GDE_CORE_SCENE_HPP
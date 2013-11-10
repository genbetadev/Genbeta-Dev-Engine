#ifndef GDE_CORE_SCENE_HPP
#define GDE_CORE_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Config.hpp>
#include <GDE/Core/CoreTypes.hpp>

namespace GDE
{
	
class GDE_API Scene : sf::NonCopyable
{
public:
	/**
	 * Destructor de la escena
	 */

	virtual ~Scene();
	
	/**
	 * Devuelve el ID único de la escena
	 */

	const sceneID& getID() const;

	/**
	 * Esablece el color de fondo de la escena
	 *
	 * @param Nuevo color de fondo de la escena
	 */

	void setBackgroundColor(const sf::Color& theColor);

	/**
	 * @brief	Gets background color.
	 *
	 * @return	The background color.
	 */

	const sf::Color& getBackgroundColor() const;

	/**
	 * @fn	virtual void Scene::init() = 0;
	 *
	 * @brief	Initialises this object.
	 */

	virtual void init() = 0;

	/**
	 * @fn	virtual void Scene::active() = 0;
	 *
	 * @brief	Actives this object.
	 */

	virtual void active() = 0;

	/**
	 * @fn	virtual void Scene::desactive() = 0;
	 *
	 * @brief	Desactives this object.
	 */

	virtual void desactive() = 0;

	/**
	 * @fn	virtual void Scene::update() = 0;
	 *
	 * @brief	Updates this object.
	 */

	virtual void update() = 0;

	/**
	 * @brief	.
	 */

	virtual void event(sf::Event theEvent) = 0;

	/**
	 * @fn	virtual void Scene::resume() = 0;
	 *
	 * @brief	Resumes this object.
	 */

	virtual void resume() = 0;

	/**
	 * @fn	virtual void Scene::pause() = 0;
	 *
	 * @brief	Pauses this object.
	 */

	virtual void pause() = 0;

	/**
	 * @fn	virtual void Scene::draw() = 0;
	 *
	 * @brief	Draws this object.
	 */

	virtual void draw() = 0;

	/**
	 * @fn	virtual void Scene::cleanup() = 0;
	 *
	 * @brief	Cleanups this object.
	 */

	virtual void cleanup() = 0;
	
protected:

	/**
	 * @fn	Scene::Scene(sceneID theID);
	 *
	 * @brief	Constructor.
	 *
	 * @param	theID	Identifier for the.
	 */

	Scene(sceneID theID);

private:
	/// ID único de la escena
	sceneID id;
	/// Color de fondo de la escena
	sf::Color colorBack;
	
}; // class Scene
	
} // namespace GDE

#endif // GDE_CORE_SCENE_HPP
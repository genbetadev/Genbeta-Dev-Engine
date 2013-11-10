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
	 * @brief	Obtiene el color de fonde de la escena.
	 *
	 * @return	Color de fondo de la escena.
	 */

	const sf::Color& getBackgroundColor() const;

	/**
	 * @brief Inicializa la escena, es llamado al añadirse al SceneManager.
	 */

	virtual void init() = 0;

	/**
	 * @brief Activa la escena, es llamado cuando la escena pasa a estar activa.
	 */

	virtual void active() = 0;

	/**
	 * @brief Es llamado cuando deja de ser la escena activa.
	 */
	virtual void desactive() = 0;

	/**
	 * @brief Actualiza la lógica de la escena, se llama una vez por ciclo
	 * en el game loop.
	 */

	virtual void update() = 0;

	/**
	 * @brief Recibe un evento de la aplicación, es llamado una vez por
	 * cada evento.
	 */

	virtual void event(sf::Event theEvent) = 0;

	/**
	 * @brief	Se llama a este método cuando la ventana recupera el foco.
	 */

	virtual void resume() = 0;

	/**
	 * @brief Se llama a este método cuando la ventana pierde el foco.
	 */

	virtual void pause() = 0;

	/**
	 * @brief	Dibuja la escena, llamado una vez por ciclo en el game loop.
	 */

	virtual void draw() = 0;

	/**
	 * @brief Se ejecuta antes de eliminar la escena, acciones de limpieza
	 * deben ir aquí.
	 */

	virtual void cleanup() = 0;
	
protected:

	/**
	 * @brief Constructor de Scene.
	 *
	 * @param theID	Identificador único de la escena.
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
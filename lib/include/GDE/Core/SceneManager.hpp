#ifndef GDE_CORE_SCENE_MANAGER_HPP
#define GDE_CORE_SCENE_MANAGER_HPP

#include <map>
#include <SFML/System.hpp>
#include "GDE/Config.hpp"
// #include "GDE/Core/Types.hpp"
#include "Scene.hpp"

namespace GDE { namespace Core
{

class GDE_API SceneManager : sf::NonCopyable
{
	static SceneManager* uniqueInstance;
	
public:
	static SceneManager* instance();

	static void release();
	
	/**
	 * Añade una escena a la pila de escenas inactivas
	 *
	 * Solo añade una escena a la pila y la inicializa
	 *
	 * @param theScene Puntero a la escena que vamos a añadir
	 */
	void addScene(Scene* theScene);


	/**
	 * Establece la escena indicada como activa
	 *
	 * Establece la escena como activa si se encuentra en la pila y llama a su
	 * Init() si no ha sido llamado. Cambia la escena al final del ciclo
	 *
	 * @param theSceneID Cadena única que identifica a la escena
	 */
	void setActiveScene(sceneID theSceneID);

	/**
	 * Elimina una escena de la pila, no puede ser la escena activa
	 *
	 * Se encarga de llamar a su método Cleanup y de eliminarla de la memoria
	 *
	 * @param theSceneID Cadena única que identifica a la escena
	 */
	void removeScene(sceneID theSceneID);

	/**
	 * Elimina todas las escenas inactivas
	 */
	void removeAllInactiveScene();
	
	/**
	 * Devuelve un puntero a la escena Activa actual
	 * 
	 * @return puntero constante a la escena activa
	 */
	const Scene* getActiveScene() const;
	
private:
	// Declaramos la clase App friend
	friend class App;
	/// Escena actualmente activa
	Scene* activeScene;
	/// Próxima escena activa
	sceneID nextScene;
	// Lista de escenas inacticas
	std::map<sceneID, Scene*> inactivesScenes;

	SceneManager();
	
	~SceneManager();

	/**
	 * Cambia la escena activa inmediatamente. USAR SetActiveScene() para
	 * cambiar de escena
	 *
	 * @param id_scene ID de la escena a cambiar
	 */
	void changeScene(sceneID theSceneID);

	/**
	 * Elimina todas las escenas de la pila.
	 *
	 * Elimina todas las escenas incluso la escena activa, se encarga de llamar
	 * a los métodos Cleanup() de las escenas y de eleminarlas de la memoria
	 */
	void removeAllScene();

	/**
	 * Llama el método Event() de la escena activa
	 *
	 * @param theEvent representa a un evento del sistema
	 */
	void eventScene(sf::Event theEvent);

	/**
	 * Llama el método Draw() de la escena activa
	 */
	void drawScene();

	/**
	 * Llama al método Update() de la escena activa
	 */
	void updateScene();

	/**
	 * Llama al método Resume de la escena activa
	 */
	void resumeScene();

	/**
	 * Llama al método Pause de la escena activa
	 */
	void pauseScene();


	bool handleChangeScene();
	
	
}; // class SceneManager	

} } // namespace GDE::Core

#endif // GDE_CORE_SCENE_MANAGER_HPP
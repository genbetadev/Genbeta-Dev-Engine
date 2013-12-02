#ifndef GDE_CORE_APP_HPP
#define GDE_CORE_APP_HPP

#include <SFML/Graphics.hpp>
#include "GDE/Config.hpp"

#include "SceneManager.hpp"

namespace GDE { namespace Core
{
    
/// Enumaración con los posibles valores de retorno de la Aplicación
enum StatusType
{
    // Values from -99 to 99 are common Error and Good status responses
    StatusAppMissingAsset = -4,  ///< Application failed due to missing asset file
    StatusAppStackEmpty = -3,  ///< Application States stack is empty
    StatusAppInitFailed = -2,  ///< Application initialization failed
    StatusError = -1,  ///< General error status response
    StatusAppOK = 0,  ///< Application quit without error
    StatusNoError = 0,  ///< General no error status response
    StatusFalse = 0,  ///< False status response
    StatusTrue = 1,  ///< True status response
    StatusOK = 1   ///< OK status response
    
    // Values from +-100 to +-199 are reserved for File status responses
};
	
class GDE_API App : sf::NonCopyable
{
	static App* uniqueInstance;

public:
	/// Constante width por defecto
	static const unsigned int DEFAULT_VIDEO_WIDTH = 640;
	/// Constante height por defecto
	static const unsigned int DEFAULT_VIDEO_HEIGHT = 480;
	/// Constante bpp por defecto
	static const unsigned int DEFAULT_VIDEO_BPP = 32;

	static App* instance();

	static void release();

	sf::RenderWindow& getWindow();

	bool isRunning() const;

	void quit(sf::Int16 theExitCode);
	
	void setFirstScene(Scene* scene);

	sf::Int16 run();
	
private:
	/// Ventana principal de la aplicación
	sf::RenderWindow window;
	/// Verdadero si la aplicación se está ejecutando
	bool running;
	/// Código de salida de la aplicación
	sf::Int16 exitCode;
	/// Puntero al SceneManager
	SceneManager* sceneManager;
	/// Escena inicial. Punto de entrada de la aplicación
	Scene* initialScene;

	App();

	~App();

	void createWindow();

	void init();

	void gameLoop();

	void cleanup();
}; // class App
	
} } // namespace GDE::Core

#endif // GDE_CORE_APP_HPP
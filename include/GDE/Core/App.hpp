#ifndef GDE_CORE_APP_HPP
#define GDE_CORE_APP_HPP

#include <SFML/Graphics.hpp>
#include <GDE/Config.hpp>
#include <GDE/Core/CoreTypes.hpp>

namespace GDE
{
	
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

	sf::Int16 run();
	
private:
	/// Ventana principal de la aplicación
	sf::RenderWindow window;
	/// Verdadero si la aplicación se está ejecutando
	bool running;
	/// Código de salida de la aplicación
	sf::Int16 exitCode;

	App();

	~App();

	void createWindow();

	void init();

	void gameLoop();

	void cleanup();
}; // class App
	
} // namespace GDE

#endif // GDE_CORE_APP_HPP
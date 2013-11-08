#include <GDE/Core/App.hpp>
#include <GDE/Core/Log.hpp>
#include <GDE/Core/StringsUtil.hpp>
#include <GDE/Core/ConfigReader.hpp>
#include <GDE/Core/ConfigCreate.hpp>

namespace GDE
{

App* App::uniqueInstance = 0;

App::App()
	: window()
	, exitCode(GDE::StatusNoError)
	, running(false)
{
	// Se inicializa el sistema de loggin
	GDE::Log::init("log.txt");
	
	GDE::Log::info("App::App()", "Constructor llamado");
}

App::~App()
{
	GDE::Log::info("App::~App()", "Destructor llamado");
}

App* App::instance()
{
	if (uniqueInstance == 0)
	{
		uniqueInstance = new App();
	}
	return uniqueInstance;
}

void App::release()
{
	if (uniqueInstance)
	{
		delete uniqueInstance;
	}
	uniqueInstance = 0;
}

sf::RenderWindow& App::getWindow()
{
	return this->window;
}

bool App::isRunning() const
{
	return this->running;
}

void App::quit(sf::Int16 theExitCode)
{
	this->exitCode = theExitCode;
	this->running = false;
}

sf::Int16 App::run()
{
	// Establecemos running a true para arrancar la aplicaci�n
	this->running = true;
	// Crea la ventana de la aplicaci�n
	this->createWindow();
	// Arranca todos los subsistemas necesarios
	this->init();
	// Entra en el Bucle del juego hasta que runnig sea false
	this->gameLoop();
	// Se encarga de la limpieza y cerrar todos los subsistemas
	this->cleanup();
	// Salimos con el c�digo de salida generado
	return this->exitCode;
}

void App::createWindow()
{
	// Creamos un modo de video con los valores por defecto
	sf::VideoMode videoMode(this->DEFAULT_VIDEO_WIDTH, this->DEFAULT_VIDEO_HEIGHT, this->DEFAULT_VIDEO_BPP);
	// Creamos un estilo por defecto
	sf::Int32 style = sf::Style::Default;
	// Establecemos fullscreen a false
	bool fullscreen = false;
	// Valor inicial del redisionamiento de la ventana
	bool resize = true;
	// Activamos la sincronizaci�n vertical por defecto
	bool vsync = true;

	GDE::ConfigReader conf;
	// Si existe un archivo de configuraci�n lo usamos para cargar los datos
	if(conf.loadFromFile("window.cfg")) // FIX: Deber� ser argado con el gestor de recursos
	{
		// Comprobamos si esta activado el modo fullscreen
		if (conf.getBool("window", "fullscreen", false))
		{
			fullscreen = true;
			// Si esta en modo fullscreen obtenemos la resoluci�n del escritorio
			videoMode = sf::VideoMode::getDesktopMode();
			// Establecemos el estilo de fullScreen
			style = sf::Style::Fullscreen;
		}
		else
		{
			// Establecemos la configuraci�n obtenida del archivo
			videoMode.width = conf.getUint32("window", "width", this->DEFAULT_VIDEO_WIDTH);
			videoMode.height = conf.getUint32("window", "height", this->DEFAULT_VIDEO_HEIGHT);
			videoMode.bitsPerPixel = conf.getUint32("window", "bpp", this->DEFAULT_VIDEO_BPP);
			// Comprobamos si la ventana se puede redimensionar
			if (!conf.getBool("window", "resize", true))
			{
				resize = false;
				style = sf::Style::Close | sf::Style::Titlebar;
			}
		}

		// Comprobamos si vsync est� activado
		vsync = (conf.getBool("m_window", "vsync", true));
	}

	// Creamos la ventana con los valores resulantes
	this->window.create(videoMode, "Genbeta Dev Engine", style);
	// FIX: Hay que dar opci�n tambi�n a usar setFrameLimit
	this->window.setVerticalSyncEnabled(vsync);

	// Escribimos la configuraci�n en el archivo
	GDE::ConfigCreate newConf;
	newConf.open("window.cfg");
	newConf.putSection("window");
	newConf.putValue("width", GDE::convertInt32(videoMode.width));
	newConf.putValue("height", GDE::convertInt32(videoMode.height));
	newConf.putValue("bpp", GDE::convertInt32(videoMode.bitsPerPixel));
	newConf.putValue("fullscreen", GDE::convertBool(fullscreen));
	newConf.putValue("resize", GDE::convertBool(resize));
	newConf.putValue("vsync", GDE::convertBool(vsync));
	newConf.close();

	// Escribimos en el log
	GDE::Log::info("App::createWindow", "Ventana creada");
	GDE::Log::info("Modo de Video", GDE::convertInt32(videoMode.width) + 
		"x" + GDE::convertInt32(videoMode.height) + 
		"x" + GDE::convertInt32(videoMode.bitsPerPixel));
	GDE::Log::info("Vsync", GDE::convertBool(vsync));
	GDE::Log::info("Fullscreen", GDE::convertBool(fullscreen));
}

void App::init()
{
	// Aqui se han de inicializar todos los subsistemas necesarios
}

void App::gameLoop()
{
	// Bucle mientras se est� ejecutando y la ventana est� abierta
	while (this->isRunning() && this->window.isOpen())
	{
		// Gestionamos los eventos de la aplicaci�n
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:                        // La ventana es cerrada
				quit(StatusAppOK); // FIX: Dar la opci�n de parar el evento a la escena
				break;
			case sf::Event::GainedFocus:        // La ventana obtiene el foco
				// Pasar al m�todo resumeScene()
				break;
			case sf::Event::LostFocus:                // La ventana pierde el foco
				// Pasar al m�todo pauseScene()
				break;
			default:        // Otros eventos se los pasamos a la ecena activa
				// pasar el resto de eventos al m�todo event() de la escena
				break;
			} // switch (event.Type)
		} // while (window.GetEvent(event))

		// Fix: Colo provisional de fondo
		this->window.clear(sf::Color(180, 200, 255));

		// Actualizamos la ventana
		this->window.display();

		// FIX: PROVISIONAL, falta integrar gestor de escenas
	}
}

void App::cleanup()
{
	// Liberar todo lo creado en init
}
	
} // namespace GDE

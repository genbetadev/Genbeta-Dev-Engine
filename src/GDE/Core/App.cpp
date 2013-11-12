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
	, initialScene(NULL)
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

void App::setFirstScene(Scene* scene)
{
	if (this->initialScene == NULL)
	{
		initialScene = scene;
		GDE::Log::info("App::setFirstScene()", "Establecida escena inicial ID=" + scene->getID());
	}
	else
	{
		GDE::Log::warning("App::setFirstScene()", "Ya se ha establecido una escena inicial");
	}
}

sf::Int16 App::run()
{
	// Establecemos running a true para arrancar la aplicación
	this->running = true;
	// Crea la ventana de la aplicación
	this->createWindow();
	// Arranca todos los subsistemas necesarios
	this->init();
	// Entra en el Bucle del juego hasta que runnig sea false
	this->gameLoop();
	// Se encarga de la limpieza y cerrar todos los subsistemas
	this->cleanup();
	// Escribimos en el log el código de salida
	GDE::Log::debug("Código de salida", GDE::StringFormat("%d", this->exitCode));
	// Salimos con el código de salida generado
	return this->exitCode;
}

void App::init()
{
	// Se crea la instancia única del SceneManager
	sceneManager = GDE::SceneManager::instance();
	
	// Establecemos la escene inicial
	if (initialScene != 0)
	{
		// Añadimos la primera escena
		this->sceneManager->addScene(this->initialScene);
		// La establecemos como escena activa
		this->sceneManager->setActiveScene(this->initialScene->getID());
		this->sceneManager->changeScene(this->sceneManager->nextScene);
	}
	else
	{
		GDE::Log::error("App::Init()", "No se ha establecido escena inicial. LLamar a App::SetFirstScene() primero");
		// Salimos con código -2
		quit(GDE::StatusAppInitFailed);
	}

	GDE::Log::info("App::Init()", "Completado");
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
	// Activamos la sincronización vertical por defecto
	bool vsync = true;

	GDE::ConfigReader conf;
	// Si existe un archivo de configuración lo usamos para cargar los datos
	if(conf.loadFromFile("window.cfg")) // FIX: Deberá ser argado con el gestor de recursos
	{
		// Comprobamos si esta activado el modo fullscreen
		if (conf.getBool("window", "fullscreen", false))
		{
			fullscreen = true;
			// Si esta en modo fullscreen obtenemos la resolución del escritorio
			videoMode = sf::VideoMode::getDesktopMode();
			// Establecemos el estilo de fullScreen
			style = sf::Style::Fullscreen;
		}
		else
		{
			// Establecemos la configuración obtenida del archivo
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

		// Comprobamos si vsync está activado
		vsync = (conf.getBool("this->window", "vsync", true));
	}

	// Creamos la ventana con los valores resulantes
	this->window.create(videoMode, "Genbeta Dev Engine", style);
	// FIX: Hay que dar opción también a usar setFrameLimit
	this->window.setVerticalSyncEnabled(vsync);

	// Escribimos la configuración en el archivo
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

void App::gameLoop()
{
	// Bucle mientras se está ejecutando y la ventana está abierta
	while (this->isRunning() && this->window.isOpen())
	{
		
		// Gestionamos los eventos de la aplicación
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:                        // La ventana es cerrada
				quit(StatusAppOK); // FIX: Dar la opción de parar el evento a la escena
				break;
			case sf::Event::GainedFocus:        // La ventana obtiene el foco
				this->sceneManager->resumeScene();
				break;
			case sf::Event::LostFocus:                // La ventana pierde el foco
				this->sceneManager->pauseScene();
				break;
			default:        // Otros eventos se los pasamos a la ecena activa
				 this->sceneManager->eventScene(event);
			} // switch (event.Type)
		} // while (window.GetEvent(event))
		
		// Llamamos al método Update() de la escena activa
		this->sceneManager->updateScene();
		
		// Establecemos el color de fondo de limpieza
		this->window.clear(sceneManager->getActiveScene()->getBackgroundColor());
		
		// Llamamos al método Draw() de la escena activa
		this->sceneManager->drawScene();
		
		// Actualizamos la ventana
		this->window.display();
		
		// Comprobamos cambios de escena
		if (this->sceneManager->handleChangeScene())
		{
			// Cambiamos el puntero de la escena activa
			this->sceneManager->changeScene(this->sceneManager->nextScene);
		}
	}
}

void App::cleanup()
{
	// Se elimina todas las escenas
	sceneManager->removeAllScene();
	
	// Eliminamos el SceneManager
	sceneManager->release();
	sceneManager = NULL;
	
	GDE::Log::info("App::cleanup()", "Completado");
}
	
} // namespace GDE

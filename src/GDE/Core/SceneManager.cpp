#include <GDE/Core/SceneManager.hpp>
#include <GDE/Core/Log.hpp>

namespace GDE
{
	
SceneManager* SceneManager::uniqueInstance = 0;
	
SceneManager::SceneManager()
	: activeScene(NULL)
	, inactivesScenes()
	, nextScene("")
{
	GDE::Log::debug("SceneManager", "Constructor llamado");
}

SceneManager::~SceneManager()
{
	GDE::Log::debug("SceneManager", "Destructor llamado");
}

SceneManager* SceneManager::instance()
{
	if (uniqueInstance == 0)
	{
		uniqueInstance = new SceneManager();
	}
	return uniqueInstance;
}

void SceneManager::release()
{
	if (uniqueInstance)
	{
		delete uniqueInstance;
	}
	uniqueInstance = 0;
}

void SceneManager::addScene(Scene* theScene)
{
	std::map<sceneID, Scene*>::const_iterator it = this->inactivesScenes.find(theScene->getID());
	
	if (it != this->inactivesScenes.end())
	{
		// Si ya existe la escena salimos sin cambios
		GDE::Log::warning("SceneManager::AddScene", "ya existe una escena con ID=" + theScene->getID() + " se omite");
		return;
	}

	// Si no existe la añadimos a la lista
	this->inactivesScenes[theScene->getID()] = theScene;

	// Inicializamos la escena
	theScene->init();
	
	GDE::Log::info("SceneManager::AddScene", "Añadida escena con ID=" + theScene->getID());
}

void SceneManager::setActiveScene(sceneID thesceneID)
{
	// Comprobamos si la escena solicitada está en la lista de inactivas
	std::map<sceneID, Scene*>::const_iterator it = this->inactivesScenes.find(thesceneID);
	if (it != this->inactivesScenes.end())
	{
		this->nextScene = thesceneID;
		return;
	}
	
	// Comprobamos si es la escena activa
	if (thesceneID == this->activeScene->getID())
	{
		GDE::Log::info("SceneManager::SetActiveScene()", "la escena con ID=" + thesceneID + "ya esta activa");
		return;
	}

	GDE::Log::warning("SceneManager::SetActiveScene()",  "No existe ninguna escena con ID=" + thesceneID);
}

void SceneManager::removeScene(sceneID thesceneID)
{
	// Buscamos en la lista de escenas inactivas
	std::map<sceneID, Scene*>::iterator it = this->inactivesScenes.find(thesceneID);
	if (it != this->inactivesScenes.end())
	{
		GDE::Log::info("SceneManager::RemoveScene()", "Eliminada escena con ID=" + thesceneID);
		it->second->cleanup();
		delete it->second;
		this->inactivesScenes.erase(it);
		return;
	}
	
	// Comprobamos si está intentando eliminar la escena activa
	if (thesceneID == this->activeScene->getID())
	{
		GDE::Log::warning("SceneManager::RemoveScene()", "La escena con ID=" + thesceneID + "esta activa y no se puede eliminar");
		return;
	}

	GDE::Log::warning("SceneManager::RemoveScene()",  "No existe ninguna escena con ID=" + thesceneID);
}

void SceneManager::removeAllInactiveScene()
{
	// Recorremos la lista de escenas inactivas
	std::map<sceneID, Scene*>::iterator it = this->inactivesScenes.begin();
	while(it != this->inactivesScenes.end())
	{
		GDE::Log::info("SceneManager::RemoveAllInactiveScene()", "Eliminada escena con ID=" + it->first);
		it->second->cleanup();
		delete it->second;
		this->inactivesScenes.erase(it++);
	}
}

const Scene* SceneManager::getActiveScene() const
{
	return this->activeScene;
}

void SceneManager::changeScene(sceneID thesceneID)
{
	this->nextScene = "";
	if (this->activeScene != NULL)
	{
		this->activeScene->desactive();
		this->inactivesScenes[this->activeScene->getID()] = this->activeScene;
	}
	
	this->activeScene = this->inactivesScenes[thesceneID];
	this->inactivesScenes.erase(thesceneID);
	this->activeScene->active();

	GDE::Log::info("SceneManager::ChangeScene()", "Activa escena con ID=" + thesceneID);
}

void SceneManager::removeAllScene()
{
	// Eliminamos todas las escenas inactivas
	removeAllInactiveScene();

	if (this->activeScene != NULL)
	{
		// Eliminamos la escena activa
		GDE::Log::info("SceneManager::RemoveAllScene()", "Eliminada escena con ID=" + this->activeScene->getID());
		this->activeScene->cleanup();
		delete this->activeScene;
		this->activeScene = NULL;
	}
}

void SceneManager::eventScene(sf::Event theEvent)
{
	this->activeScene->event(theEvent);
}

void SceneManager::drawScene()
{
	this->activeScene->draw();
}

void SceneManager::updateScene()
{
	this->activeScene->update();
}

void SceneManager::resumeScene()
{
	this->activeScene->resume();
}

void SceneManager::pauseScene()
{
	this->activeScene->pause();
}

bool SceneManager::handleChangeScene()
{
	if (this->nextScene == "")
	{
		return false;
	}
	return true;
}
	
} // namespace GDE
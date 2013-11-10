#include "SceneMain.hpp"
#include "SceneGame.hpp"

#include <iostream> // Quitar

SceneMain::SceneMain(GDE::sceneID theID)
	: Scene(theID)
	, window(GDE::App::instance()->getWindow())
	, sm(GDE::SceneManager::instance())
{
	this->setBackgroundColor(sf::Color(180, 200, 255));
}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{	
	// FIX: Asset Manager necesario
	this->font.loadFromFile("data/Roboto.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(30);
	this->text.setString("Pulsa Espacio para cambiar de escena");
	this->text.setOrigin(text.getLocalBounds().width/2.0f, text.getLocalBounds().height/2.0);
	this->text.setPosition(window.getSize().x/2.0, window.getSize().y/2.0);
	
	sm->addScene(new SceneGame("Game"));
}

void SceneMain::active()
{
}

void SceneMain::desactive()
{
	
}

void SceneMain::update()
{
	
}

void SceneMain::event(sf::Event theEvent)
{
	// Prueba de cambi de escena
	if (theEvent.type == sf::Event::KeyPressed)
	{
		sm->setActiveScene("Game");
	}
}

void SceneMain::resume()
{
	std::cout << "Escena reanudada\n";
}

void SceneMain::pause()
{
	std::cout << "Escena pausada\n";
}

void SceneMain::draw()
{
	// FIX hace falta una forma de dibujado más eficiente.
	window.draw(text);
}

void SceneMain::cleanup()
{
}
#include "SceneGame.hpp"

SceneGame::SceneGame(GDE::sceneID theID)
	: Scene(theID)
	, window(GDE::App::instance()->getWindow())
{
	this->setBackgroundColor(sf::Color(255, 200, 180));
}

SceneGame::~SceneGame()
{
}

void SceneGame::init()
{	
	// FIX: Asset Manager necesario
	this->font.loadFromFile("data/Roboto.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(30);
	this->text.setString("Otra Escena");
	this->text.setOrigin(text.getLocalBounds().width/2.0f, text.getLocalBounds().height/2.0);
	this->text.setPosition(window.getSize().x/2.0, window.getSize().y/2.0);
}

void SceneGame::active()
{
	
}

void SceneGame::desactive()
{
	
}

void SceneGame::update()
{
	
}

void SceneGame::event(sf::Event theEvent)
{
	// Prueba de cambi de escena
	if (theEvent.type == sf::Event::KeyPressed && 
		theEvent.key.code == sf::Keyboard::Space)
	{
		// Otra forma de acceder al SceneManager quizás se deban proporcionar otros métodos
		GDE::SceneManager::instance()->setActiveScene("Main");
	}
}

void SceneGame::resume()
{
	
}

void SceneGame::pause()
{
	
}

void SceneGame::draw()
{
	// FIX hace falta una forma de dibujado más eficiente.
	window.draw(text);
}

void SceneGame::cleanup()
{
}

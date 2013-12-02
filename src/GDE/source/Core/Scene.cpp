#include "GDE/Core/Scene.hpp"

namespace GDE { namespace Core
{
	
Scene::Scene(sceneID theID)
{
        this->id = theID;
}

Scene::~Scene()
{
}

const sceneID& Scene::getID() const
{
        return this->id;
}

void Scene::setBackgroundColor(const sf::Color& theColor)
{
        this->colorBack = theColor;
}

const sf::Color& Scene::getBackgroundColor() const
{
	return this->colorBack;
}
	
} } // namespace GDE::Core
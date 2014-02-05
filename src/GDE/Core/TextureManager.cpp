#include <GDE/Core/TextureManager.hpp>

namespace GDE 
{


TextureManager::TextureManager( ) 
    : ResourceManager<sf::Texture>( 100 )
{

}

TextureManager::TextureManager( const int initialSize ) 
    : ResourceManager<sf::Texture>( initialSize )
{

}

TextureManager::~TextureManager()
{

}

    
TextureManager::TextureManager( const TextureManager& tM ) 
    : ResourceManager<sf::Texture>( 1 ) 
{

}

void TextureManager::operator= ( const TextureManager& tM )
{

}

bool TextureManager::initResource( sf::Texture* resource, const std::string& fileName )
{
    return resource->loadFromFile( fileName );
}

void TextureManager::cleanUpResource( sf::Texture* resource ) 
{
}

}

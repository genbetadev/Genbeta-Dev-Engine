#ifndef GDE_TEXTURE_MANAGER_HPP
#define GDE_TEXTURE_MANAGER_HPP

#include <GDE/Core/ResourceManager.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace GDE
{

class GDE_API TextureManager : public ResourceManager<sf::Texture> 
{
public:

    TextureManager( );
    TextureManager( const int initialSize );
    virtual ~TextureManager();

protected:

    TextureManager( const TextureManager& tM );
    void operator= ( const TextureManager& tM );

    virtual bool initResource( sf::Texture* resource, const std::string& fileName );
    virtual void deinitResource( sf::Texture* resource );
}; 

}

#endif //GDE_TEXTURE_MANAGER_HPP


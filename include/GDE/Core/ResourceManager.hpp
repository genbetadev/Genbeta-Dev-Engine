#ifndef GDE_RESOURCE_MANAGER_HPP
#define GDE_RESOURCE_MANAGER_HPP

#include <GDE/Config.hpp>
#include <GDE/Core/Log.hpp>
#include <vector>
#include <map>
#include <string>
#include <malloc.h>

namespace GDE
{

/** 
* @brief La classe ResourceManager se encarga de gestionar la carga de un tipo
* de recurso.
**/
template < typename T >
class GDE_API ResourceManager
{
public:
    /** 
    * @param initialSize Tamaño inicial de la pool de recursos ( actualmente sin uso ). 
    **/
    ResourceManager( const int initialSize ) 
    {
    }

    virtual ~ResourceManager ()
    {
    }

    /** 
    * @brief Inicializa el gestor de recursos. 
    **/
    void init()
    {
    }

    /** 
    * @brief deinicializa el gestor de recursos. 
    **/
    void deinit() 
    {
        int size = this->resources.size();
        for( typename std::map< std::string, T* >::iterator it = resources.begin(); it != resources.end(); it++ ) 
        {
            deinitResource( (*it).second );
            delete (*it).second;
        }
        this->resources.clear();
    }

    /** 
    *   @brief Carga un recurso.
    *   @param fileName El nombre del recurso a cargar.
    *   @return La referencia al recurso cargado. 
    **/
    const T& getResource( const std::string& fileName )  
    {
        T* resource = NULL;
        typename std::map< std::string, T* >::iterator it = this->resources.find( fileName );
        if ( it != resources.end() ) //Comprobamos si el recurso ya existe
        {
            resource = (*it).second;
        }    
        else  
        {
            resource = new T();
            bool res = initResource( resource, fileName );  
            this->resources[ fileName ] = resource; 
            if( !res ) 
            { 
                Log::error("ResourceManager",std::string("Error al cargar el recurso ").append( fileName ));
            }
        }
        return static_cast<const T&>(*resource);
    }

    /** 
    * @brief Borra un recurso.
    * @param fileName El nombre del recurso a borrar.
    **/
    void freeResource( const std::string& fileName )  
    {
        typename std::map< std::string, T* >::iterator it = this->resources.find( fileName );
        if ( it != this->resources.end() ) //Comprobamos si el recurso ya existe
        {
            T* resource = (*it).second;
            deinitResource( resource );
            delete resource;
            this->resources.erase(it);
        }    
    }

protected:

    /** 
    * @brief Inicializa el recurso.
    * @param resource Puntero a la dirección de memória donde reside la estructura del recurso.
    * @param fileName Ruta del archivo a cargar.
    * @return true si el recurso cargór correctamente. falso si no.
    **/
    virtual bool initResource( T* resource, const std::string& fileName ) = 0;

    /** 
    * @brief deinicializa el recurso.
    * @param resource Puntero a la dirección de memória donde reside la estructura del recurso.
    **/
    virtual void deinitResource( T* resource ) = 0;

private:

    std::map< std::string, T* >  resources;    /**< @brief Mapa que mapea strings a recursos. */ 
};
}

#endif //GDE_RESOURCE_MANAGER_HPP

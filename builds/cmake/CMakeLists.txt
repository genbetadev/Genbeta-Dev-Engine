# Se define la versión mínima del CMake
cmake_minimum_required(VERSION 2.8)

project(GDE)

macro(set_option variable default type docstring)
	if(NOT DEFINED ${variable})
		set(${variable} ${default})
	endif()
	set(${variable} ${${variable}} CACHE ${type} ${docstring} FORCE)
endmacro()

# Establece la versión del proyecto
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set_option(CMAKE_BUILD_TYPE Release STRING "Escoje el tipo de build (Debug o Release)") 
set_option(BUILD_SHARED_LIBS FALSE BOOL "TRUE para construir GDE como librería compartida, FALSE para construir GDE como librería estática" )
set_option(SFML_STATIC_LIBRARIES FALSE BOOL "TRUE para Linkear SFML estaticamente")

# Carga el archivo de Configuración
include(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake)
# Le dice a CMake donde van a estar los Módulos
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

# Directorio base del proyecto
set(GDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(GDE_SOURCE_DIR ${GDE_DIR}/src/GDE)
set(GDE_TEST_SOURCE_DIR ${GDE_DIR}/src/Test)
set(GDE_INCLUDE_DIR ${GDE_DIR}/include)

# Le dice a CMake donde buscar los Headers
include_directories(${GDE_INCLUDE_DIR})

# Habilita los directorios en los proyectos
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

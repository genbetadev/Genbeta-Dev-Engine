# Se define la version mínima del CMake
cmake_minimum_required(VERSION 2.8)

project(GDE)

macro(set_option variable default type docstring)
	if(NOT DEFINED ${variable})
		set(${variable} ${default})
	endif()
	set(${variable} ${${variable}} CACHE ${type} ${docstring} FORCE)
endmacro()

set_option(GDE_BUILD_TYPE Release STRING "Escoje el tipo de build (Debug o Release)") 
set_option(SFML_STATIC_LIBRARIES FALSE BOOL "TRUE para Linkear SFML estaticamente")

set(CMAKE_BUILD_TYPE ${GDE_BUILD_TYPE})

# Carga el archivo de Configuracion
include(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake)
# Le dice a CMake donde van a estar los Modulos
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

# Directorio base del proyecto
set(GDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(GDE_SOURCE_DIR ${GDE_DIR}/src/GDE)
set(GDE_TEST_SOURCE_DIR ${GDE_DIR}/src/Test)
set(GDE_INCLUDE_DIR ${GDE_DIR}/include)

# Le dice a CMake donde buscar los Headers
include_directories(${GDE_INCLUDE_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

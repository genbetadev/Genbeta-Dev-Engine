# Se define la versión mínima del CMake
cmake_minimum_required(VERSION 2.8)

# Forza la configuración si no se ha definido (antes del comando project())
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(GDE)

# Carga el archivo de Configuración
include(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake)

# Establece la versión del proyecto
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configuraciones limitadas" FORCE)
	mark_as_advanced(CMAKE_CONFIGURATION_TYPES)
endif()

set(BUILD_SHARED_LIBS FALSE CACHE BOOL "TRUE para construir GDE como librería compartida, FALSE para construir GDE como librería estática")
set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "TRUE para Linkear SFML estaticamente")
set(BUILD_DOCS FALSE CACHE BOOL "TRUE para contruir la documentación")

if(OS_WINDOWS)
	set(BUILD_GUI_TESTS FALSE CACHE BOOL "TRUE para construir los TESTS sin símbolo del sistema (CMD)")
endif()

# Define la macro para linkeo estático
if(NOT BUILD_SHARED_LIBS)
    add_definitions(-DGDE_STATIC)
endif()

# Le dice a CMake donde van a estar los Módulos
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

# Directorio base del proyecto
set(GDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(GDE_SOURCE_DIR ${GDE_DIR}/src/GDE/source)
set(GDE_TEST_SOURCE_DIR ${GDE_DIR}/src/Test)
set(GDE_INCLUDE_DIR ${GDE_DIR}/src/GDE/include)

# Le dice a CMake donde buscar los Headers
include_directories(${GDE_INCLUDE_DIR})

# Habilita los directorios en los proyectos
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

if(BUILD_DOCS)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/doc)
endif()

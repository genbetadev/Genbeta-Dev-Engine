# Se define la version mínima del CMake
cmake_minimum_required(VERSION 2.8)

project(GDE)

# Carga el archivo de Configuracion
include(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake)
# Le dice a CMake donde van a estar los Modulos
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

# Directorio base del proyecto
set(GDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(GDE_SOURCE_DIR ${GDE_DIR}/src)
set(GDE_INCLUDE_DIR ${GDE_DIR}/include)

# Le dice a CMake donde buscar los Headers
include_directories(${GDE_INCLUDE_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

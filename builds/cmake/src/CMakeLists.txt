# Agrega algunos directorios para que CMake busque librerias allí dependiendo del OS
if (OS_WINDOWS)
	set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${GDE_DIR}/extlibs/headers")
	if(COMPILER_GCC)
		if(ARCH_32BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-mingw/x86")
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/bin/x86")
		elseif(ARCH_64BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-mingw/x64")
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/bin/x64")
		endif()
	elseif(COMPILER_MSVC)
		if(ARCH_32BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-vc20${MSVC_VERSION}/x86")
		elseif(ARCH_64BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-vc20${MSVC_VERSION}/x64")
		endif()
	endif()
elseif(OS_MACOSX)
	set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${GDE_DIR}/extlibs/headers")
	set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-osx/lib/")
endif()

file(GLOB_RECURSE GDE_SOURCE
	"${GDE_SOURCE_DIR}/*.cpp"
)

file(GLOB_RECURSE GDE_INCLUDES
	"${GDE_INCLUDE_DIR}/*.hpp"
)

file(GLOB_RECURSE GDE_TEST_SOURCE
	"${GDE_TEST_SOURCE_DIR}/*.cpp"
)

# Define en que lugar se guardan las librerias y ejecutables
set(LIBRARY_OUTPUT_PATH ${GDE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GDE_DIR}/bin)

# Crea la libreria GDE
add_library(GDE_LIB STATIC ${GDE_SOURCE} ${GDE_INCLUDES})
# Crea los tests
add_executable(GDE_TEST ${GDE_TEST_SOURCE})

# Agrega propiedades a cada target
set_target_properties(GDE_LIB 
					  PROPERTIES 
						OUTPUT_NAME_RELEASE "GDE"
						OUTPUT_NAME_DEBUG "GDE-d"
						PROJECT_LABEL "GDE"
)
set_target_properties(GDE_TEST
					  PROPERTIES 
						OUTPUT_NAME_RELEASE "Test"
						OUTPUT_NAME_DEBUG "Test-d"
						PROJECT_LABEL "TEST"
)

# Busca las librerias de SFML
find_package(SFML 2.1 COMPONENTS audio network graphics window system REQUIRED)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(GDE_LIB ${SFML_LIBRARIES})
endif(SFML_FOUND)

target_link_libraries(GDE_TEST GDE_LIB)

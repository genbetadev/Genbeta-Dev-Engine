# Agrega algunos directorios para que CMake busque librerías allí dependiendo del OS
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
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-vc${VISUAL_VERSION}/x86")
		elseif(ARCH_64BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-vc${VISUAL_VERSION}/x64")
		endif()
	endif()
elseif(OS_MACOSX)
	set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${GDE_DIR}/extlibs/headers")
	set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-osx/lib/")
elseif(OS_LINUX)
	if(COMPILER_GCC)
		if(ARCH_32BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-gcc/x86")
		elseif(ARCH_64BITS)
			set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${GDE_DIR}/extlibs/libs-gcc/x64")
		endif()
	endif()
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

# Define en que lugar se guardan las librerías y ejecutables
set(LIBRARY_OUTPUT_PATH ${GDE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GDE_DIR}/bin)

# Crea la librería GDE
add_library(GDE_LIB ${GDE_SOURCE} ${GDE_INCLUDES})
# Crea los tests
add_executable(GDE_TEST ${GDE_TEST_SOURCE})


## Agrega propiedades a cada target

set_target_properties(GDE_LIB PROPERTIES OUTPUT_NAME "GDE")
# Opciones para la generación de proyectos en algunos IDEs
set_target_properties(GDE_LIB PROPERTIES PROJECT_LABEL "GDE")
set_target_properties(GDE_LIB PROPERTIES FOLDER "GDE")

if(BUILD_SHARED_LIBS)
	set_target_properties(GDE_LIB PROPERTIES DEBUG_POSTFIX -d)
else()
	set_target_properties(GDE_LIB PROPERTIES DEBUG_POSTFIX -s-d)	
	set_target_properties(GDE_LIB PROPERTIES RELEASE_POSTFIX -s)
	set_target_properties(GDE_LIB PROPERTIES MINSIZEREL_POSTFIX -s)
endif()

# Establece la version y soversion para algunos OS
set_target_properties(GDE_LIB PROPERTIES SOVERSION ${VERSION_MAJOR})
set_target_properties(GDE_LIB PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR})

set_target_properties(GDE_TEST PROPERTIES OUTPUT_NAME "Test")
set_target_properties(GDE_TEST PROPERTIES PROJECT_LABEL "TEST")
set_target_properties(GDE_TEST PROPERTIES FOLDER "GDE")
set_target_properties(GDE_TEST PROPERTIES DEBUG_POSTFIX -d)


## Busca las librerías de SFML
find_package(SFML 2.1 COMPONENTS audio network graphics window system REQUIRED)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(GDE_LIB ${SFML_LIBRARIES})
endif(SFML_FOUND)

target_link_libraries(GDE_TEST GDE_LIB)


## Reglas de instalación

# Instala los include de GDE
install(DIRECTORY ${GDE_INCLUDE_DIR}
		DESTINATION .
		COMPONENT development)
# Instala la librería GDE
install(TARGETS GDE_LIB
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)
# Instala los tests de GDE
# install(TARGETS GDE_TEST
# 		DESTINATION share/GDE/Test
# 		COMPONENT test)

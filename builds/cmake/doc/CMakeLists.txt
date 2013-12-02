if(OS_MACOSX)
    # Agrega algunos directorios para buscar el ejecutable de doxygen
    set(ADDITIONAL_PATHS 
        /Developer/Applications/Doxygen.app/Contents/Resources 
        /Developer/Applications/Doxygen.app/Contents/MacOS 
        $ENV{HOME}/Applications/Doxygen.app/Contents/Resources 
        $ENV{HOME}/Applications/Doxygen.app/Contents/MacOS 
        $ENV{HOME}/Applications/Developer/Doxygen.app/Contents/Resources 
        $ENV{HOME}/Applications/Developer/Doxygen.app/Contents/MacOS)
 
    set(CMAKE_PROGRAM_PATH ${CMAKE_PROGRAM_PATH} ${ADDITIONAL_PATHS})
endif()

find_package(Doxygen REQUIRED)

# Establece los directorios de entrada y salida de doxygen
set(DOXYGEN_INPUT_DIR ${GDE_DIR})
set(DOXYGEN_OUTPUT_DIR ${GDE_DIR}/doc)

# Configura el archivo Doxyfile copiandolo y remplazando todas las @variables@
set(DOXYGEN_CONFIGURED_INPUT ${DOXYGEN_OUTPUT_DIR}/doxyfile)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doxyfile.in ${DOXYGEN_CONFIGURED_INPUT} @ONLY)

# Crea el target
add_custom_target(doc ALL
                  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIGURED_INPUT}
                  WORKING_DIRECTORY ${DOXYGEN_INPUT_DIR})

set_target_properties(doc PROPERTIES FOLDER "DOC")

# Establece la regla de instalación
install(DIRECTORY ${DOXYGEN_OUTPUT_DIR}/html
        DESTINATION ${INSTALL_MISC_DIR}/doc
        COMPONENT doc)

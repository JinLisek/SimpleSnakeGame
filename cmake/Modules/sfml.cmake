set(SFML_DIR "deps/sfml/"
    CACHE PATH "The path to the SFML framework.")

SET(OpenGL_GL_PREFERENCE "LEGACY")

add_subdirectory(${SFML_DIR} ${CMAKE_BINARY_DIR}/sfml)
include_directories(SYSTEM ${SFML_DIR}/sfml/include
                           ${SFML_DIR}/sfml/include)

set_target_properties(sfml-audio PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CMAKE_CXX_EXTENSIONS NO)


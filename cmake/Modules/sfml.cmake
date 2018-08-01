set(SFML_DIR "deps/sfml/"
    CACHE PATH "The path to the SFML test framework.")

add_subdirectory(${SFML_DIR} ${CMAKE_BINARY_DIR}/sfml)
include_directories(SYSTEM ${SFML_DIR}/sfml/include
                           ${SFML_DIR}/sfml/include)


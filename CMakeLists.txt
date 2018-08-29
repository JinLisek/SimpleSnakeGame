cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project("Snake With A Twist")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()

include(gmock)
include(sfml)
include(cached_config)
include(config)

add_subdirectory(app)


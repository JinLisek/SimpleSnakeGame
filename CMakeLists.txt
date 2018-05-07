cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("Snake With A Twist")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()
include(gmock)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /wd4512 /WX /EHsc")
    # Disabled Warnings:
    #   4512 "assignment operator could not be generated"
    #           This warning provides no useful info"
endif()

if(NOT CONFIGURED_AT_LEAST_ONCE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(app)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CONFIGURED_AT_LEAST_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")

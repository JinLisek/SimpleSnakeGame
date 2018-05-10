set(CMAKE_CXX_STANDARD 14)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /wd4512 /WX /EHsc")
    # Disabled Warnings:
    #   4512 "assignment operator could not be generated"
    #           This warning provides no useful info"
endif()


if(NOT CONFIGURED_AT_LEAST_ONCE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON
        CACHE STRING "If cmake should generate compile_commands.json" FORCE)
endif()

set(CONFIGURED_AT_LEAST_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")


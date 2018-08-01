add_library(Game "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(Game
    PUBLIC include)

target_link_libraries(Game
    PUBLIC Map
    PRIVATE MapReader
)


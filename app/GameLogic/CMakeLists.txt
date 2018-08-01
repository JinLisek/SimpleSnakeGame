add_library(GameLogic "")

add_subdirectory(Map)
add_subdirectory(MapReader)
add_subdirectory(Game)

target_include_directories(GameLogic
    PUBLIC include)

target_link_libraries(GameLogic
    PUBLIC Game
)


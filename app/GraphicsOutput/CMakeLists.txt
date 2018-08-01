add_library(GraphicsOutput "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(GraphicsOutput
    PUBLIC include)

target_link_libraries(GraphicsOutput
    PRIVATE ConsoleInterface
    PRIVATE GameLogic
)


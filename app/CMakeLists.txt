add_subdirectory(Utilities)
add_subdirectory(GameLogic)
add_subdirectory(ConsoleInterface)
add_subdirectory(GraphicsOutput)
add_subdirectory(UserInput)
add_executable(SnakeWithATwist main.cpp)

target_link_libraries(SnakeWithATwist
    PRIVATE Game
    PRIVATE GraphicsOutput
    PRIVATE UserInput
    PRIVATE pthread
)

target_compile_options(SnakeWithATwist PRIVATE -Wall -Wextra -Werror)

target_compile_features(SnakeWithATwist PRIVATE cxx_std_14)
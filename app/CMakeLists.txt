add_subdirectory(Utilities)
add_subdirectory(Map)
add_subdirectory(ConsoleInterface)
add_subdirectory(MapReader)
add_executable(SnakeWithATwist main.cpp)

target_link_libraries(SnakeWithATwist
    PRIVATE Map
    PRIVATE ConsoleInterface
    PRIVATE MapReader
    PRIVATE pthread
)

target_compile_options(SnakeWithATwist PRIVATE -Wall -Wextra -Werror)

target_compile_features(SnakeWithATwist PRIVATE cxx_std_14)
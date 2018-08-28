add_library(UserInput "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(UserInput
    PUBLIC include)

target_link_libraries(UserInput
    PRIVATE Game
    PRIVATE sfml-window
)


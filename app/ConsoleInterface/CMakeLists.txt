add_library(ConsoleInterface "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(ConsoleInterface 
    PUBLIC include
)

target_link_libraries(ConsoleInterface
    PRIVATE Map
)

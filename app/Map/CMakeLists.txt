add_library(Map "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(Map
    PUBLIC include)

target_link_libraries(Map
    PUBLIC Utilities
)


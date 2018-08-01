add_library(MapReader "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(MapReader
    PUBLIC include)

target_link_libraries(MapReader
    PUBLIC Map
)


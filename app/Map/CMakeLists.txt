add_library(Map "")

add_subdirectory(source)
add_subdirectory(tests)

target_include_directories(Map PUBLIC include)


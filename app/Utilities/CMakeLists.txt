add_library(Utilities "")

add_subdirectory(source)

target_include_directories(Utilities 
    PUBLIC include
)

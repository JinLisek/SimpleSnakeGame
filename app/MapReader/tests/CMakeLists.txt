add_gmock_test(MapReaderTests MapReaderTest.cpp)

add_custom_command(
    TARGET MapReaderTests PRE_LINK
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/test_input
            ${CMAKE_CURRENT_BINARY_DIR}/test_input
)

target_link_libraries(MapReaderTests 
    PRIVATE MapReader
)

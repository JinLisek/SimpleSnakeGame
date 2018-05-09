add_gmock_test(MapTests MapTest.cpp TileTest.cpp)

target_link_libraries(MapTests 
    PRIVATE Map
)

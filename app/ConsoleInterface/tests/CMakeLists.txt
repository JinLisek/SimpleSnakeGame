add_gmock_test(
    ConsoleInterfaceTests
    TileRepresentationTest.cpp 
    TileRepresentationFactoryTest.cpp
    MapRepresentationTest.cpp)

target_link_libraries(ConsoleInterfaceTests 
    PRIVATE Map
    PRIVATE ConsoleInterface
)

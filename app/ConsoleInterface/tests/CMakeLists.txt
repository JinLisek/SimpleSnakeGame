add_gmock_test(ConsoleInterfaceTests
    TileRepresentationTest.cpp 
    TileRepresentationFactoryTest.cpp)

target_link_libraries(ConsoleInterfaceTests 
    PRIVATE Map
    PRIVATE ConsoleInterface
)

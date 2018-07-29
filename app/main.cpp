#include <iostream>
#include "TileRepresentation.hpp"
#include "TileRepresentationFactory.hpp"
#include "Map.hpp"
#include "MapRepresentation.hpp"
#include "TxtMapReader.hpp"

int main()
{
    TxtMapReader mapReader{};
    auto map = mapReader.readMapFromFile("../Maps/DefaultMap.txt");

    MapRepresentation mapRepresentation {*map};

    std::cout << mapRepresentation.draw() << std::endl;

    return 0;
}

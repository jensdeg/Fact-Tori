#include <SFML/Graphics.hpp>
#include <iostream>
#include "camera.h"
#include "world.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;



void World::LoadMap(){
    std::ifstream file("../resources/world.json");
    map = json::parse(file)["map"];
}

void World::SaveMap(){
    std::ofstream file("../resources/world.json");

    if (!file.is_open()) {
        std::cerr << "Failed to save map: " << std::endl;
        return;
    }

    json mapdata;
    mapdata["map"] = map;

    file << mapdata.dump();
    file.close();
}


int World::Draw(sf::RenderWindow *window){
    int x,y;
    
    size_t width = map[0].size();
    size_t height = map.size();

    int tilesrendered = 0;

    for (x=0;x<width;x++){
        for(y=0;y<height;y++){
            sf::Vector2f tilelocation(x * Tile_Size, y * Tile_Size);

            sf::RectangleShape tile(sf::Vector2(Tile_Size, Tile_Size));
            if(map[x][y] == 1 || map[x][y] == -1){
                tile.setFillColor(sf::Color(105,105,105));
            }
            else if(map[x][y] == 2 || map[x][y] == -2){
                tile.setFillColor(sf::Color::Red);
            }
            else{
                tile.setFillColor(sf::Color::Black);
            }

            if(map[x][y] < 0){
                tile.setOutlineThickness(-10.f);
                tile.setOutlineColor(sf::Color::White);  
            }
            tile.setPosition(tilelocation);
            window->draw(tile);
            tilesrendered++;
        }
    }

    //std::cout << "tilesRendered: " << tilesrendered << std::endl;
    return EXIT_SUCCESS;
};

#include <SFML/Graphics.hpp>
#include <iostream>
#include "camera.h"
#include "world.h"
#include "placement.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void World::LoadMap(){
    std::ifstream file(world_path);
    map = json::parse(file)["map"];
}

void World::SaveMap(){
    std::ofstream file(world_path);

    if (!file.is_open()) {
        std::cerr << "Failed to save map: " << std::endl;
        return;
    }

    json mapdata;
    mapdata["map"] = map;

    file << mapdata.dump();
    file.close();
}

int World::Draw(sf::RenderWindow *window, Camera &Camera){    
    size_t width = map[0].size();
    size_t height = map.size();

    int tilesrendered = 0;

    for (int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            sf::Vector2f tilelocation(x * Tile_Size, y * Tile_Size);
            if(!Camera.IsInFrame(tilelocation, Tile_Size)){
                continue;
            }
            sf::RectangleShape tile(sf::Vector2(Tile_Size, Tile_Size));
            if(map[x][y] == empty || map[x][y] == empty * -1){
                tile.setFillColor(sf::Color(105,105,105));
            }
            else if(map[x][y] == generator || map[x][y] == generator *-1){
                tile.setFillColor(sf::Color::Red);
            }
            else{
                tile.setFillColor(sf::Color::Black);
            }
            if(MouseIsOnTile(x, y, Tile_Size)){
                tile.setOutlineThickness(-10.f);
                tile.setOutlineColor(sf::Color::White);  
            }
            tile.setPosition(tilelocation);
            window->draw(tile);
            tilesrendered++;
        }
    }
    return EXIT_SUCCESS;
};

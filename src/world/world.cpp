#include <SFML/Graphics.hpp>
#include <iostream>
#include "camera.h"
#include <fstream>
#include <nlohmann/json.hpp>

float tile_size = 100.f;

using json = nlohmann::json;



json LoadMap(){
    std::ifstream file("../resources/world.json");
    return json::parse(file)["map"];
}

void SaveMap(json &map){
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


float GetTileSize(){
    return tile_size;
}


int DrawWorld(sf::RenderWindow *window, const json &map){
    int x,y;
    sf::View view = GetCam();
    
    size_t width = map[0].size();
    size_t height = map.size();

    int tilesrendered = 0;

    for (x=0;x<width;x++){
        for(y=0;y<height;y++){
            sf::Vector2f tilelocation(x * tile_size, y * tile_size);

            sf::RectangleShape tile(sf::Vector2(tile_size, tile_size));
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

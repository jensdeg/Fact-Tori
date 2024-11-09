#include <SFML/Graphics.hpp>
#include <iostream>
#include "camera.h"
#include <fstream>
#include <nlohmann/json.hpp>

float tile_size = 100.f;

using json = nlohmann::json;
json map;

void LoadMap(){
    std::ifstream file("../resources/world.json");
    map = json::parse(file)["map"];
    //std::cout << map.size() << std::endl;
}


int DrawWorld(sf::RenderWindow *window){
    int x,y;
    sf::View view = GetCam();
    
    size_t width = map[0].size();
    size_t height = map.size();

    int tilesrendered = 0;

    for (x=0;x<width;x++){
        for(y=0;y<height;y++){
            sf::Vector2f tilelocation(x * tile_size, y * tile_size);

            if(!IsInFrame(tilelocation)){
                continue;
            }

            sf::RectangleShape tile(sf::Vector2(tile_size, tile_size));
            if(map[x][y] == 0){
                tile.setFillColor(sf::Color::White);
            }
            else if(map[x][y] == 1){
                tile.setFillColor(sf::Color::Red);
            }
            else{
                tile.setFillColor(sf::Color::Black);
            }
            tile.setPosition(tilelocation);
            window->draw(tile);
            tilesrendered++;
        }
    }

    //std::cout << "tilesRendered: " << tilesrendered << std::endl;
    return EXIT_SUCCESS;
};

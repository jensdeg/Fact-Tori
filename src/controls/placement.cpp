#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "world.h"

sf::Vector2f mousepos;
using json = nlohmann::json;

int tempx,tempy,tempvalue = NULL;

void setMousePosition(sf::RenderWindow *window){
    sf::Vector2f position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    mousepos = position;

    //std::cout << position.x  << std::endl;
}

void checkPlacement(json &map){
    int x,y;
    

    float Tile_size = GetTileSize();
    
    size_t width = map[0].size();
    size_t height = map.size();

    //BUG: coordinate 0,0 is always 0 and cant be changed any way because o this
    if(map[tempx][tempy] < 0){
        map[tempx][tempy] = tempvalue;
    }
    
    
    for (x=0;x<width;x++){
        for(y=0;y<height;y++){
            if(map[x][y] < 0){
                int newvalue = map[x][y] *-1;
                map[x][y] = newvalue;
            }
            if(x * Tile_size < mousepos.x && (x * Tile_size) + Tile_size > mousepos.x){
                if(y * Tile_size < mousepos.y && (y * Tile_size) + Tile_size > mousepos.y){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                        map[x][y] = 2;
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
                        map[x][y] = 1;
                    }
                    tempvalue = map[x][y];
                    tempx = x;
                    tempy = y;
                    int newvalue = map[x][y] *-1;
                    map[x][y] = newvalue;
                } 
            }
        }
    }
}


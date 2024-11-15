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

void checkPlacement(World &world){
    int x,y;
    
    float Tile_size = world.Tile_Size;

    size_t width =  world.map[0].size();
    size_t height = world.map.size();

    if(world.map[tempx][tempy] < 0){
        world.map[tempx][tempy] = tempvalue;
    }
    
    
    for (x=0;x<width;x++){
        for(y=0;y<height;y++){
            if(world.map[x][y] < 0){
                int newvalue = world.map[x][y] *-1;
                world.map[x][y] = newvalue;
            }
            if(x * Tile_size < mousepos.x && (x * Tile_size) + Tile_size > mousepos.x){
                if(y * Tile_size < mousepos.y && (y * Tile_size) + Tile_size > mousepos.y){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                        world.map[x][y] = 2;
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
                        world.map[x][y] = 1;
                    }
                    tempvalue = world.map[x][y];
                    tempx = x;
                    tempy = y;
                    int newvalue = world.map[x][y] *-1;
                    world.map[x][y] = newvalue;
                } 
            }
        }
    }
}


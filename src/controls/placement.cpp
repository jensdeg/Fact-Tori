#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "world.h"

sf::Vector2f mousepos;
using json = nlohmann::json;

int tempx,tempy,tempvalue = NULL;

int selectedbuilding = generator;

void setMousePosition(sf::RenderWindow *window){
    sf::Vector2f position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    mousepos = position;
}
sf::Vector2f getMousePosition(sf::RenderWindow *window){
    if(mousepos.x == NULL || mousepos.y == NULL){
        setMousePosition(window);
    }
    return mousepos;
}
bool MouseIsOnTile(int x,int y, float tilesize){
    if(x * tilesize < mousepos.x && (x * tilesize) + tilesize > mousepos.x){
        if(y * tilesize < mousepos.y && (y * tilesize) + tilesize > mousepos.y){
            return true;
        }
    }
    return false;
}

void checkPlacement(World &world){
    int x,y;

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
            if(MouseIsOnTile(x, y, world.Tile_Size)){
                //placing
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                    world.map[x][y] = generator;
                }
                //removing
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
                    world.map[x][y] = empty;
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



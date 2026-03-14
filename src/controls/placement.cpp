#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "world.h"

sf::Vector2f mousepos;
using json = nlohmann::json;

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
    size_t width =  world.map[0].size();
    size_t height = world.map.size();
 
    for (int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            if(MouseIsOnTile(x, y, world.Tile_Size)){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                    world.map[x][y] = generator;
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
                    world.map[x][y] = empty;
                }
            } 
        }
    } 
}



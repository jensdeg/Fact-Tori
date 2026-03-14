#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include "camera.h"

using json = nlohmann::json;

enum Buildings{
        empty = 1,
        generator = 2
    };
class World{
public:
    float Tile_Size = 100.f;
    json map;
    

    // Draws world
    int Draw(sf::RenderWindow *window, Camera &Camera);

    // saves map to the world file
    void SaveMap();

    // loads map from the world file
    void LoadMap();
private:
    char* world_path = "../debug/resources/world";
};
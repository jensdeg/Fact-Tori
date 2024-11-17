#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


class World{
public:
    float Tile_Size = 100.f;
    json map;

    // Draws world
    int Draw(sf::RenderWindow *window);

    // saves map to the world file
    void SaveMap();

    // loads map from the world file
    void LoadMap();
private:
    char* world_path = "../debug/resources/world";
};
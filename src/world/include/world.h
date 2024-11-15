#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


class World{
public:
    float Tile_Size = 100.f;
    json map;

    int Draw(sf::RenderWindow *window);
    void SaveMap();
    void LoadMap();
private:
    char* world_path = "../resources/world";
};
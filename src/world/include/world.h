#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


int DrawWorld(sf::RenderWindow *window, const json &map);

void colorrandomizer();

json LoadMap();

float GetTileSize();

void SaveMap(json &map);
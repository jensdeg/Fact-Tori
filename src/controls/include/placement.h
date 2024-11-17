#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Sets Mouse position relative to the map
void setMousePosition(sf::RenderWindow *window);

// checks mouse postition for placements
void checkPlacement(World &world);
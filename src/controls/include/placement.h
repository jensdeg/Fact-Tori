#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void setMousePosition(sf::RenderWindow *window);

void checkPlacement(json &map);
#pragma once
#include <SFML/Graphics.hpp>

void CameraControls();

void CameraZoom(sf::Event *event);

sf::View GetView();
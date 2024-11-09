#pragma once
#include <SFML/Graphics.hpp>

void CameraControls();

void CameraZoom(sf::Event *event);

sf::View GetCam();

bool IsInFrame(sf::Vector2f location);

unsigned int GetResolution();
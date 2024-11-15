#pragma once
#include <SFML/Graphics.hpp>


class Camera{
public:
    float width = 1280.f;
    float height = 720.f;

    float origin_x = (width / 2) + 100;
    float origin_y = (height / 2) + 100;
    
    sf::View view = sf::View(sf::FloatRect(origin_x, origin_y, width, height));

    void ControlMovement();
    void ControlZoom(sf::Event *event);

private:
    float movespeed = 100;
    float zoomfactor = 0.1f;
};
#include <SFML/Graphics.hpp>
#include <iostream>
#include "camera.h"


void Camera::ControlMovement(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        view.move(-movespeed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        view.move(movespeed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        view.move(0, -movespeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        view.move(0, movespeed);
    }    
}

void Camera::ControlZoom(sf::Event *event){
    if(event->type == sf::Event::MouseWheelMoved){
        if(event->mouseWheel.delta == -1){
            view.zoom(1 + zoomfactor);
        }
        if(event->mouseWheel.delta == 1){
            view.zoom(1 - zoomfactor);
        }  
    }
}

bool Camera::IsInFrame(sf::Vector2f location, float margin){
    float left_bound = view.getCenter().x - (view.getSize().x / 2) - margin;
    float right_bound = view.getCenter().x + (view.getSize().x / 2) + margin;
    float top_bound = view.getCenter().y - (view.getSize().y / 2) - margin;
    float bottom_bound = view.getCenter().y + (view.getSize().y / 2) + margin;

    if(location.x > left_bound && location.x < right_bound){
        if(location.y > top_bound && location.y < bottom_bound){
            return true;
        }
    }
    return false;
}


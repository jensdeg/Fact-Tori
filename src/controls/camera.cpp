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

// bool IsInFrame(sf::Vector2f location){
//     float camborder_x = view.getSize().x;
//     float camborder_y = view.getSize().y;
//     if(location.y < view.getCenter().y + camborder_y && location.y > view.getCenter().y - camborder_y){
//         if(location.x < view.getCenter().x + camborder_x && location.x > view.getCenter().x - camborder_x)
//         return true;
//     }
//     return false;
// }


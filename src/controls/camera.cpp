#include <SFML/Graphics.hpp>
#include <iostream>


float movespeed = 100;
float zoomfactor = 0.1f;

//cam settings
float width = 1280.f;
float height = 720.f;

float origin_x = (width / 2) + 100;
float origin_y = (height / 2) + 100;

sf::View cam(sf::FloatRect(origin_x, origin_y, width, height));

sf::View GetCam(){
    return cam;
}

void CameraControls(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        cam.move(-movespeed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        cam.move(movespeed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        cam.move(0, -movespeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        cam.move(0, movespeed);
    }    
}

void CameraZoom(sf::Event *event){
    if(event->type == sf::Event::MouseWheelMoved){
        if(event->mouseWheel.delta == -1){
            cam.zoom(1 + zoomfactor);
        }
        if(event->mouseWheel.delta == 1){
            cam.zoom(1 - zoomfactor);
        }  
    }
}

bool IsInFrame(sf::Vector2f location){
    float camborder_x = cam.getSize().x;
    float camborder_y = cam.getSize().y;
    if(location.y < cam.getCenter().y + camborder_y && location.y > cam.getCenter().y - camborder_y){
        if(location.x < cam.getCenter().x + camborder_x && location.x > cam.getCenter().x - camborder_x)
        return true;
    }
    return false;
}


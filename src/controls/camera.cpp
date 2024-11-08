#include <SFML/Graphics.hpp>
#include <iostream>

sf::View cam(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));

sf::View GetView(){
    return cam;
}

void CameraControls(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        cam.move(-1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        cam.move(1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        cam.move(0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        cam.move(0.f, 1.f);
    }    
}

void CameraZoom(sf::Event *event){
    if(event->type == sf::Event::MouseWheelMoved){
        if(event->mouseWheel.delta == -1){
            cam.zoom(1.1f);
        }
        if(event->mouseWheel.delta == 1){
            cam.zoom(0.9f);
        }  
    }
}


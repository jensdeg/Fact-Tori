#include <iostream>
#include <SFML/Graphics.hpp>

#include "world.h"
#include "camera.h"
#include <chrono>


int main()
{
    //Window Settings
    auto window = sf::RenderWindow{ { 1280, 720 }, "Fact-Tori" };
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(340,10)); //So i can see the terminal when the window opens
    
    //Initialize world
    LoadMap();

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            CameraZoom(&event);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)){
                window.close();
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }            
        }
        
        CameraControls();
        
        window.clear();

        window.setView(GetCam());
        DrawWorld(&window);
             
        window.display();
    }
}
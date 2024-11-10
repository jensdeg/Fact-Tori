#include <iostream>
#include <SFML/Graphics.hpp>

#include "world.h"
#include "camera.h"
#include "placement.h"

#include <chrono>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


int main()
{
    //Window Settings
    auto window = sf::RenderWindow{ { 1280, 720 }, "Fact-Tori" };
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(340,10)); //So i can see the terminal when the window opens
    
    //Initialize world
    json map = LoadMap();

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            CameraZoom(&event);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)){
                SaveMap(map);
                window.close();
            }
            if (event.type == sf::Event::Closed)
            {
                SaveMap(map);
                window.close();
            }            
        }
        
        CameraControls();
        setMousePosition(&window);
        checkPlacement(map);

        window.clear();

        window.setView(GetCam());
        DrawWorld(&window, map);
        
        window.display();
    }
}
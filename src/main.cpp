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

    World world;
    Camera Camera;

    //Window Settings
    auto window = sf::RenderWindow{ { 1280, 720 }, "Fact-Tori" };
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(340,0)); //So i can see the terminal when the window opens
    
    //Initialize world
    world.LoadMap();
    json map = world.map;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            Camera.ControlZoom(&event); // enables zoom controls

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)){
                world.SaveMap();
                window.close();
            }
            if (event.type == sf::Event::Closed)
            {
                world.SaveMap();
                window.close();
            }            
        }
        
        Camera.ControlMovement();
        setMousePosition(&window);


        // ================ GAME LOGIC ====================== //
        checkPlacement(world);
        // ================================================== //


        // ================ WINDOW DRAWING ================== //
        window.clear();

        window.setView(Camera.view);
        world.Draw(&window);
        
        window.display();
        // ================================================== //
    }
}
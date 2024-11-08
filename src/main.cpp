#include <iostream>
#include <SFML/Graphics.hpp>

#include "world.h"
#include "camera.h"

int main()
{
    auto window = sf::RenderWindow{ { 1440u, 800u }, "Fact-Tori" };
    window.setFramerateLimit(144);

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
        window.setView(GetView());
        DrawWorld(&window);
        window.display();
    }
}
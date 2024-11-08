#include <SFML/Graphics.hpp>
#include <iostream>

int width = 100;
int height = 100;

int DrawWorld(sf::RenderWindow *window){
    int x,y;
    for (x=0;x<width;x++){
        for(y=0;y<height;y++){
            sf::RectangleShape block(sf::Vector2(10.f, 10.f));
            block.setFillColor(sf::Color(x,y,y));
            block.setOrigin(x * -10.f, y * -10.f);
            window->draw(block);
        }
    }
    return EXIT_SUCCESS;
};

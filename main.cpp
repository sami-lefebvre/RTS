#include <iostream>
#include <SFML/Graphics.hpp>

#include "Entity.h"

int main()
{
    sf::RenderWindow fenetre(sf::VideoMode(800, 600), "Wow");

    sf::Texture text;
    text.loadFromFile("cb.bmp");

    Entity entity;
    entity.setTexture(text);
    entity.setPosition(sf::Vector2f(0, 0));

    while (fenetre.isOpen())
    {
        sf::Event event;
        while (fenetre.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        fenetre.clear(sf::Color::White);
        fenetre.draw(entity);
        fenetre.display();
    }

    return 0;
}

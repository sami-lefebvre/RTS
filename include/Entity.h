#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
    public:
        Entity();
    private:
        unsigned int m_life;


};

#endif // ENTITY_H

#ifndef MAP_H
#define MAP_H

#include<SFML/Graphics.hpp>

/** \brief classe Map
 *
 * Une classe qui permet simplement de gérer une tileMap (voir https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array-fr.php)
 *
 *
 */

enum Tile {VIDE, HERBE};

class Map : public sf::Drawable, public sf::Transformable
{
    public:
        Map(unsigned int width, unsigned int height);
        Map(const std::string& texture, Tile* tiles, unsigned int tileSize, unsigned int width, unsigned int height);

        bool loadTileset(std::string& texture);
        bool load(const std::string& texture, Tile* tiles, unsigned int tileSize);

        void setTiles(Tile *tiles, unsigned int tileSize);

        sf::Vector2u getSize() const;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = &m_tileset;
            target.draw(m_vertices, states);
        }

        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        unsigned int m_width;
        unsigned int m_height;
};

#endif // MAP_H

#include "Map.h"

Map::Map(unsigned int width, unsigned int height)
{
    m_width = width;
    m_height = height;
}

Map::Map(const std::string& texture, Tile* tiles, unsigned int tileSize, unsigned int width, unsigned int height)
{
    m_width = width;
    m_height = height;
    load(texture, tiles, tileSize);
}

bool Map::load(const std::string& texture, Tile* tiles, unsigned int tileSize)
{
    //le code vient du tuto SFML

    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(texture))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(m_width * m_height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < m_width; ++i)
        for (unsigned int j = 0; j < m_height; ++j)
        {
            // on récupère le numéro de tuile courant
            int tileNumber = tiles[i + j * m_width];

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (m_tileset.getSize().x / tileSize);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
            quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
            quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
            quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
            quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
        }

    return true;
}

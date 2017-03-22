#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "Map.h"


class MapEditor
{
    public:
        MapEditor();

        void mainLoop();

        Map getMap();

    private:
        Map m_map;
};

#endif // MAPEDITOR_H

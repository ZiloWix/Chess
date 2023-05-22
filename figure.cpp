#include "figure.h"

Figure::Figure(Color color, int x, int y)
{
    this->x = x;
    this->y = y;
    this->color = color;
}

bool Figure::isItOccupiedCell(QVector<QPair<int, int> > &occupiedCells, int x, int y)
{
    for(auto coords : occupiedCells)
    {
        if (coords.first == x && coords.second == y) return true;
    }
    return false;
}

Figure::~Figure()
{
    delete pixmap;
}



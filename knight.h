#ifndef KNIGHT_H
#define KNIGHT_H
#include "figure.h"


class Knight: public Figure
{
private:


public:
    Knight(Color color, int x, int y);
    void getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating);


    //void move(int new_x, int new_y)
    //{

    //}
};

#endif // KNIGHT_H

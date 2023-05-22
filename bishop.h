#ifndef BISHOP_H
#define BISHOP_H
#include "figure.h"


class Bishop: public Figure
{
private:

public:
    Bishop(Color color, int x, int y);
    void getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating);


    //void move(int new_x, int new_y)
    //{

    //}
};


#endif // BISHOP_H

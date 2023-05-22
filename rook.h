#ifndef ROOK_H
#define ROOK_H
#include "figure.h"


class Rook: public Figure
{
private:


public:
    Rook(Color color, int x, int y);
    void getPossibleMoves(QVector <QPair <int, int>>& coords,QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating);




    //void move(int new_x, int new_y)
    //{

    //}
};


#endif // ROOK_H

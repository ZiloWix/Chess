#ifndef KING_H
#define KING_H
#include "figure.h"


class King: public Figure
{
private:


public:
    King(Color color, int x, int y);
    void getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating);



    //void move(int new_x, int new_y)
    //{

    //}
};

#endif // KING_H

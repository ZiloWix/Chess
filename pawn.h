#ifndef PAWN_H
#define PAWN_H
#include "figure.h"


class Pawn: public Figure
{
private:
    int start_x;
    int start_y;


public:
    Pawn(Color color, int x, int y);
    void getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating);


};

#endif // PAWN_H

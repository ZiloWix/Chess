#ifndef QUEEN_H
#define QUEEN_H
#include "figure.h"

class Queen: public Figure
{
private:


public:
    Queen(Color color, int x, int y);
    void getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating);

    //void move(int new_x, int new_y)
    //{

    //}
};
#endif // QUEEN_H*/

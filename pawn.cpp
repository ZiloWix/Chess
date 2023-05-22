#include "pawn.h"

Pawn::Pawn(Color color, int x, int y): Figure(color, x, y)
{
    if(color == Color::White)
    {
        pixmap = new QPixmap(":/ing/img/White_pawn.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }
    else
    {
        pixmap = new QPixmap(":/ing/img/Black_pawn.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }
    start_x = x;
    start_y = y;

}

void Pawn::getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating)
{
    coords.clear();
    moveEating.clear();
    if(color == Color::Black)
    {
        if(y + 1 <= 7)
        {
            if(!isItOccupiedCell(occupiedCells, x, y + 1))
                coords.append(QPair <int, int>(x, y + 1));
            if (x - 1 >= 0)
            {
                if (isItOccupiedCell(occupiedCells, x - 1, y + 1))
                    moveEating.append(QPair <int, int>(x - 1, y + 1));
            }
            if (x + 1 <= 7)
            {
                if (isItOccupiedCell(occupiedCells, x + 1, y + 1))
                    moveEating.append(QPair <int, int>(x + 1, y + 1));
            }
        }

    }
    else
    {
        if(y - 1 >= 0)
        {
            if(!isItOccupiedCell(occupiedCells, x, y - 1))
                coords.append(QPair <int, int>(x, y - 1));
            if (x - 1 >= 0)
            {
                if (isItOccupiedCell(occupiedCells, x - 1, y - 1))
                    moveEating.append(QPair <int, int>(x - 1, y - 1));
            }
            if (x + 1 <= 7)
            {
                if (isItOccupiedCell(occupiedCells, x + 1, y - 1))
                    moveEating.append(QPair <int, int>(x + 1, y - 1));
            }
        }
    }

    if(start_x == x && start_y == y && !coords.empty())
    {
        if(this->color == Color::Black)
        {
            if(!isItOccupiedCell(occupiedCells, x, y + 2))
                coords.append(QPair <int, int>(x, y + 2));
        }
        else
        {
            if(!isItOccupiedCell(occupiedCells, x, y - 2))
                coords.append(QPair <int, int>(x, y - 2));
        }
    }

}

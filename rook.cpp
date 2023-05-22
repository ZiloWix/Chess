#include "rook.h"

Rook::Rook(Color color, int x, int y): Figure(color, x, y)
{
    if(color == Color::White)
    {
        pixmap = new QPixmap(":/ing/img/White_rook.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }
    else
    {
        pixmap = new QPixmap(":/ing/img/Black_rook.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }

}

void Rook::getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating)
{
    coords.clear();//вектор возможных ходов
    moveEating.clear(); // вектор возможных съедений (здесь и белые, и чёрные фигуры)
    for(int i = 1; y - i >= 0; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x, y - i))
            coords.append(QPair <int, int>(x, y - i));
        else
        {
            moveEating.append(QPair <int, int>(x, y - i));
            break;
        }
    }
    for(int i = 1; x + i <= 7; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x + i, y))
            coords.append(QPair <int, int>(x + i, y));
        else
        {
            moveEating.append(QPair <int, int>(x + i, y));
            break;
        }
    }
    for(int i = 1; y + i <= 7; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x, y + i))
            coords.append(QPair <int, int>(x, y + i));
        else
        {
            moveEating.append(QPair <int, int>(x, y + i));
            break;
        }
    }
    for(int i = 1; x - i >= 0; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x - i, y))
            coords.append(QPair <int, int>(x - i, y));
        else
        {
            moveEating.append(QPair <int, int>(x - i, y));
            break;
        }
    }


}


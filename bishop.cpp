#include "bishop.h"

Bishop::Bishop(Color color, int x, int y) : Figure(color, x, y)
{

    if(color == Color::White)
    {
        pixmap = new QPixmap(":/ing/img/White_bishop.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }
    else
    {
        pixmap = new QPixmap(":/ing/img/Black_bishop.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }


}

void Bishop::getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating)
{
    coords.clear();
    moveEating.clear();
    for(int i = 1; x + i <= 7 && y + i <= 7; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x + i, y + i))
            coords.append(QPair <int, int>(x + i, y + i));
        else
        {
            moveEating.append(QPair <int, int>(x + i, y + i));
            break;
        }
    }
    for(int i = 1; x - i >= 0 && y + i <= 7; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x - i, y + i))
            coords.append(QPair <int, int>(x - i, y + i));
        else
        {
            moveEating.append(QPair <int, int>(x - i, y + i));
            break;
        }
    }
    for(int i = 1; x + i <= 7 && y - i >= 0; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x + i, y - i))
            coords.append(QPair <int, int>(x + i, y - i));
        else
        {
            moveEating.append(QPair <int, int>(x + i, y - i));
            break;
        }
    }
    for(int i = 1; x - i >= 0 && y - i >= 0; i++)
    {
        if(!isItOccupiedCell(occupiedCells, x - i, y - i))
            coords.append(QPair <int, int>(x - i, y - i));
        else
        {
            moveEating.append(QPair <int, int>(x - i, y - i));
            break;
        }
    }
}




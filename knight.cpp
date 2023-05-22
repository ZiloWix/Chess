#include "knight.h"

Knight::Knight(Color color, int x, int y) : Figure(color, x, y)
{
    if(color == Color::White)
    {
        pixmap = new QPixmap(":/ing/img/White_knight.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }
    else
    {
        pixmap = new QPixmap(":/ing/img/Black_knight.png");
        setPixmap(pixmap->scaled(figure_width, figure_height));
    }

}

void Knight::getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating)
{
    coords.clear();
    moveEating.clear();
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7)
        {
            if(!isItOccupiedCell(occupiedCells, nx, ny))
                coords.append(QPair <int, int>(nx, ny));
            else
            {
                moveEating.append(QPair <int, int>(nx, ny));
            }
        }
    }
}


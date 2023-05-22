#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

enum class Color {White, Black};

class Figure: public QGraphicsPixmapItem
{
public:
   Figure();
   Figure(Color color, int x, int y);

protected:
   int x;
   int y;
   Color color;
   QPixmap* pixmap;
   const int figure_width = 50;
   const int figure_height = 70;

public:
    inline int getX() const
    {
        return x;
    }

    inline int getY() const
    {
       return y;
    }
    inline Color getColor()
    {
        return this->color;
    }
    void setNewXY(int new_x, int new_y)
    {
       this->x = new_x;
       this->y = new_y;
    }

    ~Figure();


    bool isItOccupiedCell(QVector <QPair <int, int>>& occupiedCells, int x, int y);

    virtual void getPossibleMoves(QVector <QPair <int, int>>& coords, QVector <QPair <int, int>>& occupiedCells, QVector <QPair <int, int>>& moveEating) = 0;



  //  void mousePressEvent(QMouseEvent* event) override;

};

#endif // FIGURE_H

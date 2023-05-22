#ifndef CELL_H
#define CELL_H
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class Cell : public QGraphicsRectItem
{
private:
    bool isSelected;
    QColor color;
public:
    Cell();
    Cell(QColor color): color(color)
    {
        isSelected = false;
        this->setBrush(color);
    }
    QColor getColor() { return color;}
    void setColor(QColor color) { this->color = color;}
    bool getSelection()
    {
        return isSelected;
    }

    void setSelection(bool selection)
    {
        isSelected = selection;
    }
//protected:
   // void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // CELL_H

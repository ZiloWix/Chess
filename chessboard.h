#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsScene>
#include "queen.h"
#include "pawn.h"
#include "king.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "cell.h"

class ChessBoard: public QGraphicsScene
{
private:
    const int cell_size = 75;
    const int cell_number = 8;
    QVector <Figure*> Black_figures;
    QVector <Figure*> White_figures;
    QVector <Cell*> cells;
    Color whoWalks = Color::White;
    Cell* selectedCell = nullptr;
    Figure* perFigure = nullptr;
    Figure* blackKing = nullptr;
    Figure* whiteKing = nullptr;
    QVector <QPair <int, int>> possibleMoves;
    QVector <QPair <int, int>> occupiedCells;
    QVector <QPair <int, int>> moveEating;


public:
    ChessBoard();
    void fullBoard();
    void addFigure(Figure* figure);
    void moveFigure(Figure* figure, int x, int y);

    Cell* getCell(QPointF point);
    Figure* findFigure(int x, int y);
    bool findFigureIn(QVector <QPair <int, int>>& vector, int x, int y);
    int getPairIndex(QVector <QPair <int, int>>& vector, int x, int y);
    int getPtrIndex(QVector <Figure*>& figures, Figure* figure);
    int isItEating();
    void rotateTurn()
    {
        whoWalks == Color::Black ? whoWalks = Color::White : whoWalks = Color::Black;
    }

    void returnTheOriginalColor(QVector <QPair <int, int>>& vector);
    void setColorForSelectedCells(QVector <QPair <int, int>>& vector, QColor color);
    void returnTheOriginalColor();
    void setColorForSelectedCells(QColor color);
    void eraseFigure(Figure* figure);



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CHESSBOARD_H

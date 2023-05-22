#include "chessboard.h"
#include <QPointF>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <mainwindow.h>


ChessBoard::ChessBoard()
{

    for(int i = 0; i < cell_number; i++)
    {
        for(int j = 0; j < cell_number; j++)
        {

            QColor color = (i + j) % 2 == 0 ? QColor("#F5F5DC") : QColor("#654321");
            Cell* cell = new Cell(color);
            cells.push_back(cell);
            cell->setRect(i * cell_size, j * cell_size, cell_size, cell_size);
            QPen pen(Qt::black);
            cell->setPen(pen);

            this->addItem(cell);
        }
    }

    this->setFocus();
}

void ChessBoard::fullBoard()
{
    for(int i = 0; i < 8; i++)
    {
        Black_figures.push_back(new Pawn(Color::Black, i, 1));
        this->addFigure(Black_figures[i]);
        occupiedCells.append(QPair <int, int>(i, 0));
        occupiedCells.append(QPair <int, int>(i, 1));

        White_figures.push_back(new Pawn(Color::White, i, 6));
        this->addFigure(White_figures[i]);
        occupiedCells.append(QPair <int, int>(i, 6));
        occupiedCells.append(QPair <int, int>(i, 7));
    }

    Black_figures.push_back(new King(Color::Black, 4, 0));
    White_figures.push_back(new King(Color::White, 4, 7));

    Black_figures.push_back(new Queen(Color::Black, 3, 0));
    White_figures.push_back(new Queen(Color::White, 3, 7));

    Black_figures.push_back(new Bishop(Color::Black, 2, 0));
    Black_figures.push_back(new Bishop(Color::Black, 5, 0));
    White_figures.push_back(new Bishop(Color::White, 2, 7)); // 2, 7
    White_figures.push_back(new Bishop(Color::White, 5, 7));

    Black_figures.push_back(new Knight(Color::Black, 1, 0));
    Black_figures.push_back(new Knight(Color::Black, 6, 0));
    White_figures.push_back(new Knight(Color::White, 1, 7));
    White_figures.push_back(new Knight(Color::White, 6, 7));

    Black_figures.push_back(new Rook(Color::Black, 0, 0));
    Black_figures.push_back(new Rook(Color::Black, 7, 0));
    White_figures.push_back(new Rook(Color::White, 0, 7));
    White_figures.push_back(new Rook(Color::White, 7, 7));

    for(int i = 8; i < 16; i++)
    {
        this->addFigure(Black_figures[i]);
        this->addFigure(White_figures[i]);
    }
    blackKing = Black_figures[8];
    whiteKing = White_figures[8];
}

void ChessBoard::addFigure(Figure* figure)
{
    this->addItem(figure);
    figure->setPos(figure->getX() * cell_size + 10, figure->getY() * cell_size + 5);
}

void ChessBoard::moveFigure(Figure *figure, int x, int y)
{
    if(typeid(*figure) == typeid(Pawn) && (y == 0 || y == 7))
    {

        Color colorForNewFigure = figure->getColor();

        rotateTurn();
        eraseFigure(findFigure(figure->getX(),figure->getY()));
        rotateTurn();
        int index = getPairIndex(occupiedCells, figure->getX(), figure->getY());
        occupiedCells.remove(index);

        (colorForNewFigure == Color::Black) ? Black_figures.push_back(new Queen(Color::Black, x, y)) :
                                              White_figures.push_back(new Queen(Color::White, x, y));

        colorForNewFigure == Color::Black ? this->addFigure(Black_figures.back()) : this->addFigure(White_figures.back());
        occupiedCells.append(QPair <int, int>(x, y));

    }
    else
    {
    figure->setNewXY(x,y);
    figure->setPos(figure->getX() * cell_size + 10, figure->getY() * cell_size+5);
    }
}

Cell* ChessBoard::getCell(QPointF point)
{
    for(auto cell : cells) {
        if (cell->contains(point)) return cell;
    }
    return nullptr;
}

Figure* ChessBoard::findFigure(int x, int y)
{
    if(whoWalks == Color::Black)
    {
        for (auto figure : Black_figures)
        {
            if (figure->getX() == x && figure->getY() == y) return figure;
        }
    }
    else
    {
        for (auto figure : White_figures)
        {
            if (figure->getX() == x && figure->getY() == y) return figure;
        }
    }
    return nullptr;
}

int ChessBoard::isItEating()
{
    for(auto coords : moveEating)
    {
        Figure* theFoundFigure = findFigure(coords.first, coords.second);
        if (theFoundFigure != nullptr)
        {
            int index = getPairIndex(moveEating, coords.first, coords.second);
            moveEating.remove(index);
            return -1;

        }
    }
    return 0;
}

bool ChessBoard::findFigureIn(QVector <QPair <int, int>>& vector, int x, int y)
{
    for(auto coords : vector)
    {
        if (x == coords.first && y == coords.second) return true;
    }
    return false;
}

void ChessBoard::returnTheOriginalColor(QVector<QPair<int, int> > &vector)
{
    for(auto coords : vector)
    {
        QPointF point((coords.first+1) * cell_size, (coords.second+1) * cell_size);
        Cell* cell = getCell(point);
        cell->setBrush(cell->getColor());
        cell->update();

    }
}

void ChessBoard::returnTheOriginalColor()
{
    selectedCell->setBrush(selectedCell->getColor());
    selectedCell->update();
    selectedCell->setSelection(false);
}

void ChessBoard::setColorForSelectedCells(QVector<QPair<int, int> > &vector, QColor color)
{
    for(auto coords : vector)
    {

        QPointF point((coords.first+1) * cell_size, (coords.second+1) * cell_size);
        Cell* cell = getCell(point);
        cell->setBrush(color);
        cell->update();

    }
}
void ChessBoard::setColorForSelectedCells(QColor color)
{
    selectedCell->setBrush(color);
    selectedCell->update();
    selectedCell->setSelection(true);

}

int ChessBoard::getPairIndex(QVector<QPair<int, int>>& vector, int x, int y)
{
    int index = 0;
    for (auto pair : vector)
    {
        if (pair.first == x && pair.second == y) return index;
        index++;
    }

    return 0;
}

int ChessBoard::getPtrIndex(QVector<Figure*>& figures, Figure* figure)
{
    int index = 0;
    for (auto el : figures)
    {
        if (el->getX() == figure->getX() && el->getY() == figure->getY()) return index;
        index++;
    }

    return 0;
}

void ChessBoard::eraseFigure(Figure *figure)
{

    if (whoWalks == Color::Black)
    {
        int index = getPtrIndex(Black_figures, figure);
        Black_figures.remove(index);
    }
    if (whoWalks == Color::White)
    {
        int index = getPtrIndex(White_figures, figure);
        White_figures.remove(index);
    }
    this->removeItem(figure);
    delete figure;
}



void ChessBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        int x = event->scenePos().x() / cell_size;
        int y = event->scenePos().y() / cell_size;
        Figure* figure = findFigure(x, y);
        if(findFigureIn(possibleMoves, x, y) || findFigureIn(moveEating, x, y))
        {

            returnTheOriginalColor();
            returnTheOriginalColor(possibleMoves);
            returnTheOriginalColor(moveEating);

            rotateTurn();


            if(findFigureIn(moveEating, x, y))
            {

               eraseFigure(findFigure(x,y));
               int index = getPairIndex(occupiedCells, perFigure->getX(), perFigure->getY());
               occupiedCells.remove(index);

               moveFigure(perFigure, x, y);
            }
            else
            {

                int index = getPairIndex(occupiedCells, perFigure->getX(), perFigure->getY());
                occupiedCells.remove(index);
                occupiedCells.append(QPair<int,int>(x, y));

                moveFigure(perFigure, x, y);

            }
            moveEating.clear();
            possibleMoves.clear();
        }



        if(figure == nullptr) return;

        if (selectedCell != nullptr)
        {
            returnTheOriginalColor();

            if (possibleMoves.isEmpty() == false)
            {
                returnTheOriginalColor(possibleMoves);
            }

            if (moveEating.isEmpty() == false)
            {
                returnTheOriginalColor(moveEating);
            }
        }

        selectedCell = getCell(event->scenePos());

        figure->getPossibleMoves(possibleMoves, occupiedCells, moveEating);

        if (!moveEating.empty())
        {
            while (isItEating() != 0);
        }
        if (findFigureIn(moveEating, whiteKing->getX(), whiteKing->getY()))
        {
           QMessageBox::about(nullptr, "ПОБЕДА", "Чёрные победили!!!");
        }
        else if(findFigureIn(moveEating, blackKing->getX(), blackKing->getY()))
        {
           QMessageBox::about(nullptr, "ПОБЕДА", "Белые победили!!!");
        }


        perFigure = figure;

        setColorForSelectedCells(possibleMoves, QColor("#50C878"));
        setColorForSelectedCells(moveEating, QColor("#A52A2A"));

        if(selectedCell->getSelection() == false)
            setColorForSelectedCells(QColor("#013220"));
        else
            returnTheOriginalColor();

    }
}



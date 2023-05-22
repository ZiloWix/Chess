#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "chessboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   // const int width = 1200;
    //const int height = 800;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawBoard() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
    ChessBoard *chessboard;
   // Figure *figure;
};
#endif // ШАХМАТЫ_H

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Шахматы");
    chessboard = new ChessBoard();

    ui->graphicsView->setScene(chessboard);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


MainWindow::~MainWindow()
{

    delete chessboard;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    chessboard->fullBoard();
    QPushButton *button = findChild<QPushButton*>("pushButton");
    if (button) button->lower();


}


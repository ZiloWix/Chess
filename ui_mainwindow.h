/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(873, 757);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(130, 60, 600, 600));
        graphicsView->setLineWidth(0);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -80, 1021, 881));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ing/img/Board.jpg")));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 330, 161, 61));
        pushButton->setStyleSheet(QString::fromUtf8("float: right;\n"
"	margin-right: 3%;\n"
"	margin-top: 5px;\n"
"	border-radius: 5px;\n"
"	-moz-border-radius: 5px;\n"
"	-webkit-border-radius: 5px;\n"
"	padding: 5px 9px;\n"
"	font-size: 1.2em;\n"
"	background-color: rgba(236, 101, 80, 1);\n"
"	text-shadow: #454545 0 0 2px;\n"
"	border-bottom: 4px solid rgba(217, 91, 72, 1);\n"
"	color: white;\n"
"font-family: 'Roboto Slab', serif;"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        graphicsView->raise();
        pushButton->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 873, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

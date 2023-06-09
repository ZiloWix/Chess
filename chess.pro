QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    cell.cpp \
    chessboard.cpp \
    figure.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    pawn.cpp \
    queen.cpp \
    rook.cpp \


HEADERS += \
    bishop.h \
    cell.h \
    chessboard.h \
    figure.h \
    king.h \
    knight.h \
    mainwindow.h \
    pawn.h \
    queen.h \
    rook.h \


FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Figure.qrc \
    allFigures.qrc

DISTFILES += \
    img/Black_king.png \
    img/Black_left_knight.png \
    img/Black_pawn.png \
    img/Black_queen.png \
    img/Black_right_knight.png \
    img/Black_rook.png \
    img/Board.jpg \
    img/White_bishop.png \
    img/White_left_knight.png \
    img/White_pawn.png \
    img/White_queen.png \
    img/White_right_knight.png \
    img/White_rook.png \
    img/emptyCell.jpg \
    img/white_king.png \
    img/Доска.jpg \
    img/Доска.jpg \
    img/Доска.jpg



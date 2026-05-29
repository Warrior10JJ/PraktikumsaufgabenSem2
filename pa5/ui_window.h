#ifndef PRAKTIKUM_UI_WINDOW_H
#define PRAKTIKUM_UI_WINDOW_H

#include <QMainWindow>
#include "ui_widget.h"



//classe bekommt qmainwindow + die widgests welche in uiwidget definiert

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    MainWidget *mainwidget;
public:
    MainWindow() {
        QIcon icon("../pa5/thi_icon.png");
        setWindowTitle("UFO");
        setWindowIcon(icon);
        mainwidget = new MainWidget(this);
        setCentralWidget(mainwidget);
        this->setStyleSheet("background-color: black;");
        this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        //this->showFullScreen();
        resize(600, 500);
    }

    ~MainWindow()
    {
        delete mainwidget;
    }












    /*
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        QIcon icon("../pa5/thi_icon.png");
        setWindowTitle("UFO");
        setWindowIcon(icon);
        // MainWidget instanziieren und als zentrales Widget setzen
        MainWidget *centralWidget = new MainWidget(this);
        setCentralWidget(centralWidget);

        // Optionale feste Größe oder Mindestgröße, damit es wie in den Abbildungen aussieht
        resize(400, 300);
    }
*/


};





#endif

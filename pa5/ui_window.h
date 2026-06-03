#ifndef PRAKTIKUM_UI_WINDOW_H
#define PRAKTIKUM_UI_WINDOW_H
#include "ui_widget.h"

//klasse bekommt qmainwindow + die widgests welche in uiwidget definiert

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    MainWidget *mainwidget;
public:
    MainWindow() {
        int dark = 0;
        int type = 0;
        QIcon icon("../pa5/thi_icon.png");
        setWindowTitle("UFO");
        setWindowIcon(icon);
        if (dark == 1) {//kleine spielerei
            this->setStyleSheet("background-color: black;");
            this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            resize(600, 500);
        } else {
            resize(300, 250);
        }
        mainwidget = new MainWidget(this,type,dark);
        setCentralWidget(mainwidget);
    }

    ~MainWindow()
    {
        //delete mainwidget;, muss durch qt aber nicht sein
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

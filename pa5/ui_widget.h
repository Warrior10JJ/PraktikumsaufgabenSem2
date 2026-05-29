#ifndef PRAKTIKUM_UI_WIDGET_H
#define PRAKTIKUM_UI_WIDGET_H
#include "ufo_thread.h"
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>



//class mainwidget
class MainWidget : public QWidget {
    Q_OBJECT
private:
    QFormLayout *formlayout;
    QLineEdit *xedit;
    QLineEdit *yedit;
    QLineEdit *heightedit;
    QLineEdit *speededit;
    QPushButton *launchbutton;
    std::string text;
    QLabel *xlabel;
    QLabel *ylabel;
    QLabel *heightlabel;
    QLabel *speedlabel;
    QLabel *outputlabel;
public:
    //constructor
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
    {
        if (parent) {
            // Teilt Windows mit, dass die Titelleiste dieses Fensters das dunkle System-Design nutzen soll
            parent->setWindowFlag(Qt::Window);

            // Hinweis: Ab Qt 6.5 erkennt Qt das Windows-Dark-Theme oft automatisch,
            // wenn die Palette des Hauptfensters dunkel gesetzt ist:
            QPalette windowPal = parent->palette();
            windowPal.setColor(QPalette::Window, QColor("#2b2b2b"));
            parent->setPalette(windowPal);
        }





        xedit = new QLineEdit();
        xedit->setStyleSheet("background-color: black; color: green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        yedit = new QLineEdit();
        yedit->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        heightedit = new QLineEdit();
        heightedit->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        speededit = new QLineEdit();
        speededit->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        xlabel = new QLabel("X-COORDINATE:");
        xlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        ylabel = new QLabel("Y-COORDINATE:");
        ylabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        heightlabel = new QLabel("HEIGHT:");
        heightlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        speedlabel = new QLabel("SPEED:");
        speedlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        launchbutton = new QPushButton("LAUNCH");
        launchbutton->setStyleSheet("background-color: black; color:green; font-size: 45px;font-weight: bold;");

        outputlabel = new QLabel("OUTPUT   eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee eeeeeeeeeeeeeeeeeeeeeeeeeeeee eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
        outputlabel->setWordWrap(true);
        outputlabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        outputlabel->setMinimumHeight(90);
        outputlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray; padding 5p ;");
        outputlabel->setFrameShape(QFrame::Box);
        outputlabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        outputlabel->setText("\n\n\n");

        connect(launchbutton, SIGNAL(clicked()), this, SLOT(changeText()));

        formlayout = new QFormLayout();//formlayout annstatt grid für bessere/ einafache lesbarkeit
        formlayout->addRow(xlabel, xedit);
        formlayout->addRow(ylabel, yedit);
        formlayout->addRow(heightlabel, heightedit);
        formlayout->addRow(speedlabel, speededit);
        formlayout->addRow(launchbutton);
        formlayout->addRow(outputlabel);
        setLayout(formlayout);
        //connect(startbutton, SIGNAL(clicked()), this, SLOT(changeText()));
    }
    //Deconstructor
    ~MainWidget()
    {
    }

private slots:
    void changeText()
    {
        outputlabel->setText("xedit->text()\n\n");
    }


};












#endif

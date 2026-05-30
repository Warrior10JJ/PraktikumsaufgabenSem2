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
    QLabel *outputlabel1;
    QLabel *outputlabel2;
    QLabel *outputlabel3;
public:
    //constructor
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
    {




        xedit = new QLineEdit();
        //xedit->setStyleSheet("background-color: black; color: green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        yedit = new QLineEdit();
        //yedit->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        heightedit = new QLineEdit();
        //heightedit->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        speededit = new QLineEdit();
       //speededit->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;border: 1px solid gray;");

        xlabel = new QLabel("X-COORDINATE:");
        //xlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        ylabel = new QLabel("Y-COORDINATE:");
        //ylabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        heightlabel = new QLabel("HEIGHT:");
        //heightlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        speedlabel = new QLabel("SPEED:");
        //speedlabel->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold;");

        launchbutton = new QPushButton("LAUNCH");
        launchbutton->setStyleSheet("background-color:rgba(225, 225, 225,1);border-radius: 0px;");

        outputlabel1 = new QLabel("\n\n");
        //outputlabel1->setStyleSheet("background-color: black; color:green; font-size: 30px;font-weight: bold; border: 1px solid gray;");
        outputlabel1->setFrameShape(QFrame::Box);
        outputlabel1->setFrameShadow(QFrame::Plain);




        connect(launchbutton, SIGNAL(clicked()), this, SLOT(changeText()));

        formlayout = new QFormLayout();//formlayout annstatt grid für bessere/ einafache lesbarkeit
        formlayout->addRow(xlabel, xedit);
        formlayout->addRow(ylabel, yedit);
        formlayout->addRow(heightlabel, heightedit);
        formlayout->addRow(speedlabel, speededit);
        formlayout->addRow(launchbutton);
        formlayout->addRow(outputlabel1);
        //formlayout->addRow(outputlabel3);
        //formlayout
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
        launchbutton->setText("LAUNCHING...");
        outputlabel1->setText(xedit->text() + "\n3\n3");
        //outputlabel1->setText(yedit->text());
        //outputlabel1->setText(speededit->text());
    }


};












#endif

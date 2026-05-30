#ifndef PRAKTIKUM_UI_WIDGET_H
#define PRAKTIKUM_UI_WIDGET_H
#include "ufo_thread.h"
#include "ufo.h"
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>

#include "vertical.h"


//class mainwidget
class MainWidget : public QWidget {
    Q_OBJECT
private:
   //layout
    QFormLayout *formlayout;
    QLineEdit *xedit;
    QLineEdit *yedit;
    QLineEdit *heightedit;
    QLineEdit *speededit;
    QPushButton *launchbutton;
    //std::string text;
    QLabel *xlabel;
    QLabel *ylabel;
    QLabel *heightlabel;
    QLabel *speedlabel;
    QLabel *outputlabel1;
    QLabel *outputlabel2;
    QLabel *outputlabel3;
    //attribute
    Ufo *ufo;
    UfoThread *uthread;




public:
    //constructor
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent),ufo(nullptr),uthread(nullptr)
    {
        uthread = new UfoThread(ufo);
        ufo = new Vertical();





        int fontsize = 15;
        QString editstyle = QString::asprintf("QLineEdit {border: 1px solid gray; border-radius: 0px; font-size: %dpx;} QLineEdit:focus {border: 1px solid #0078d4;}",fontsize);
        QString labelstyle = QString::asprintf("font-size: %dpx;",fontsize);
        QString buttonstyle = QString::asprintf("background-color:rgba(225, 225, 225,1);border-radius: 0px;font-size: %dpx;",fontsize);
        QString outputstyle = QString::asprintf("border: 1px solid black; border-radius: 0px;font-size: %dpx;",fontsize);


        xedit = new QLineEdit();
        xedit->setStyleSheet(editstyle);

        yedit = new QLineEdit();
        yedit->setStyleSheet(editstyle);

        heightedit = new QLineEdit();
        heightedit->setStyleSheet(editstyle);

        speededit = new QLineEdit();
       speededit->setStyleSheet(editstyle);

        xlabel = new QLabel("X-COORDINATE:");
        xlabel->setStyleSheet(labelstyle);

        ylabel = new QLabel("Y-COORDINATE:");
        ylabel->setStyleSheet(labelstyle);

        heightlabel = new QLabel("HEIGHT:");
        heightlabel->setStyleSheet(labelstyle);

        speedlabel = new QLabel("SPEED:");
        speedlabel->setStyleSheet(labelstyle);

        launchbutton = new QPushButton("LAUNCH");
        launchbutton->setStyleSheet(buttonstyle);

        outputlabel1 = new QLabel("\n\n\n\n\n");
        outputlabel1->setStyleSheet(outputstyle);
        //outputlabel1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        //outputlabel1->setFrameShadow(QFrame::Plain);




        connect(launchbutton, SIGNAL(clicked()), this, SLOT(changeText()));

        formlayout = new QFormLayout();//formlayout annstatt grid für bessere/ einafache lesbarkeit
        formlayout->addRow(xlabel, xedit);
        formlayout->addRow(ylabel, yedit);
        formlayout->addRow(heightlabel, heightedit);
        formlayout->addRow(speedlabel, speededit);
        formlayout->addRow(launchbutton);
        formlayout->addRow(outputlabel1);
        formlayout->setVerticalSpacing(10);
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

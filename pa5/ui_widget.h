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
#include <QThread>
#include <QApplication>

#include "ballistic.h"
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
    QLabel *outputlabel;
    //attribute
    Ufo *ufo;
    UfoThread *uthread;




public:
    //constructor
    MainWidget(QMainWindow *parent = nullptr, int type =0,int dark =0): QWidget(parent),ufo(nullptr),uthread(nullptr)
    {




        std::string pid = "ID1";
        if (type == 0) {
            ufo = new Vertical(pid);
            printf("Ufo started Vertical");
        } else {
            if (type == 1) {
                ufo = new Ballistic(pid,45,45);
                printf("Ufo started Ballistic");
            } else {
                printf("UNVALID TYPE");
                exit(1);
            }
        }
        uthread = new UfoThread(ufo);
        QString editstyle;
        QString labelstyle;
        QString buttonstyle;
        QString outputstyle;
        QString buttonstyle2;





        if (dark == 1) {
            editstyle = QString::asprintf("background-color: black; color: green; font-size: 30px;font-weight: bold;border: 1px solid gray;");
            labelstyle = QString::asprintf("background-color: black; color:green; font-size: 30px;font-weight: bold;");
            buttonstyle = QString::asprintf("background-color: black; color:green; font-size: 45px;font-weight: bold;");
            buttonstyle2 = QString::asprintf("background-color: black; color:green; font-size: 45px;font-weight: bold;");
            outputstyle = QString::asprintf("background-color: black; color:green; font-size: 30px;font-weight: bold; border: 1px solid gray;");
        }else{
            int fontsize = 15;
            editstyle = QString::asprintf("QLineEdit {border: 1px solid gray; border-radius: 0px; font-size: %dpx;} QLineEdit:focus {border: 1px solid #0078d4;}",fontsize);
            labelstyle = QString::asprintf("font-size: %dpx;",fontsize);
            buttonstyle = QString::asprintf("background-color:rgba(175, 175, 175,1);border-radius: 0px;font-size: %dpx;",fontsize);
            buttonstyle2 = QString::asprintf("background-color:rgba(225, 225, 225,1);border-radius: 0px;font-size: %dpx;",fontsize);
            outputstyle = QString::asprintf("border: 1px solid black; border-radius: 0px;font-size: %dpx;",fontsize);
        }




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

        outputlabel = new QLabel("3\n3\n3\n");
        outputlabel->setStyleSheet(outputstyle);
        outputlabel->setAlignment( Qt::AlignCenter);

        connect(launchbutton, SIGNAL(clicked()), this, SLOT(startUfo()));

        formlayout = new QFormLayout();//formlayout annstatt grid für bessere/ einafache lesbarkeit
        formlayout->addRow(xlabel, xedit);
        formlayout->addRow(ylabel, yedit);
        formlayout->addRow(heightlabel, heightedit);
        formlayout->addRow(speedlabel, speededit);
        formlayout->addRow(launchbutton);
        formlayout->addRow(outputlabel);
        formlayout->setVerticalSpacing(10);
        setLayout(formlayout);
    }
    //Deconstructor
    ~MainWidget()
    {
    }

private slots:
    void startUfo()
    {
        launchbutton->setText("LAUNCHING...");
        launchbutton->setEnabled(false);
        outputlabel->setText( "STARTING UFO\n\n\n");
        bool error = false;
        bool okx,oky,okh,oks;

        QString xold = xedit->text();
        float x = xedit->text().toFloat(&okx);
        if (!okx) {
            xedit->setText("ERROR: MUST BE FLOAT");
            error = true;
        }
        QString yold = yedit->text();
        float y = yedit->text().toFloat(&oky);
        if (!oky) {
            yedit->setText("ERROR: MUST BE FLOAT");
            error = true;
        }
        QString heightold = heightedit->text();
        float height = heightedit->text().toFloat(&okh);
        if (!okh) {
            heightedit->setText("ERROR: MUST BE FLOAT");
            error = true;
        }
        QString speedold = speededit->text();
        int speed = speededit->text().toInt(&oks);
        if (!oks) {
            speededit->setText("ERROR: MUST BE INT");
            error = true;
        }
        if (error == false) {
            std::vector<float> pos = ufo->getPosition();
            float currentx = pos[0];
            float currenty = pos[1];
            float currentheight = pos[2];
            QString text = QString::asprintf("STARTED AT\n POSITION:\n %.2f | %.2f | %.2f meter\n ");
            outputlabel->setText(text);
            uthread->startUfo(x,y,height,speed);

        } else {
            outputlabel->setText( "\nWRONG INPUTS\nLAUNCH ABORTED\n");
            launchbutton->setText("ERROR");
            qApp->processEvents();              //schreibt die Errormessages in die qedits
            QThread::msleep(2000);              //wartet 2 sek
            xedit->setText(xold);                  //setzt alte werte wieder ein
            yedit->setText(yold);
            heightedit->setText(heightold);
            speededit->setText(speedold);
            outputlabel->setText( "\n\n\n");
            launchbutton->setEnabled(true);
            launchbutton->setText("LAUNCH");
        }

    }


};












#endif

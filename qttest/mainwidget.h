#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <string>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
    {
        xedit = new QLineEdit();
        launchbutton = new QPushButton("Click");
        xlabel = new QLabel();
        xlabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        formlayout = new QGridLayout();
        formlayout->addWidget(xedit, 0, 0);
        formlayout->addWidget(launchbutton, 1, 0);
        formlayout->addWidget(xlabel, 2, 0);
        setLayout(formlayout);
        connect(launchbutton, SIGNAL(clicked()), this, SLOT(changeText()));
    }

    ~MainWidget()
    {
        delete formlayout;
        delete xedit;
        delete launchbutton;
        delete xlabel;
    }

private slots:
    void changeText()
    {
        xlabel->setText(xedit->text());
    }

private:
    QGridLayout *formlayout;
    QLineEdit *xedit;
    QPushButton *launchbutton;
    QLabel *xlabel;
    std::string text;
};

#endif // MAINWIDGET_H

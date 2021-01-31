#ifndef MAINWINDOWO_H
#define MAINWINDOWO_H

#include <QMainWindow>
#include <QVector>
#include <QThread>
#include <QTimer>
#include <QDebug>

#include "TCanvas.h"
#include "TH1.h"
//github works???

namespace Ui {
class MainWindowo;
}

class MainWindowo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowo(QWidget *parent = 0);
    ~MainWindowo();
    void startRootUpdate();  // starts timer which in regular intervals process Root events
    void stopRootUpdate();   // stops timer which in regular intervals process Root events
    TCanvas c1;
    TH1F source;
    TH1F final;


private:
    Ui::MainWindowo *ui;
    //int divX = 1;
    //int divY = 1;
    //QVector<> pads;
    enum addLocation { bellow, right, above, left };
    addLocation location = bellow;
    int divX = 1;
    int divY = 1;
    int hei = 231;
    int X1;
    int Y1;
    int X2;
    int Y2;

    QTimer *RootUpdateTimer = 0; //root update timer

private slots:
    void timerTimeout(); //timer-based update of Root events

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOWO_H

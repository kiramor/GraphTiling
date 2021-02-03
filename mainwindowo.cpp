#include "mainwindowo.h"
#include "ui_mainwindowo.h"

//Root
#include "TApplication.h"
#include "TGeoMatrix.h"
#include "TSystem.h"
#include "TVirtualGeoTrack.h"//TGeoTrack
#include "TH1D.h"
#include "TH1I.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TColor.h"
#include "TROOT.h"
#include "TRandom2.h"
#include "TGeoTrack.h"
#include "TGeoManager.h"

#include "TCanvas.h"
#include "TPad.h"
#include "TVirtualPad.h"

MainWindowo::MainWindowo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowo)
{
    ui->setupUi(this);
    //root update cycle
    RootUpdateTimer = new QTimer(this);
    RootUpdateTimer->setInterval(100);
    QObject::connect(RootUpdateTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    RootUpdateTimer->start();
    qDebug()<<">Timer to refresh Root events started";

    source = TH1F("source","source hist",100,-3,3);
    source.FillRandom("gaus",1000);
    final = TH1F("final","final hist",100,-3,3);
    c1.SetCanvasSize(1000, 1000);


    // continued...

    for (Int_t i=0;i<10000;i++) {
        final.Fill(source.GetRandom());
    }


    QListWidget * lw = ui->padLayoutlw;
    lw->setMaximumHeight(150);
    //lw->verticalHeader()->setSectionsMovable(true);
    lw->setDropIndicatorShown(true);
    //lw->setColumnCount(1);
    //lw->setRowCount(1);
    //lw->setHorizontalHeaderLabels(QStringList("a1"));
    //lw->verticalHeader()->setSectionsMovable(true);
    lw->setDropIndicatorShown(true);
    lw->setSelectionMode(QAbstractItemView::SingleSelection);
    lw->setMovement(QListView::Free);
    lw->setDragEnabled(true);
    lw->viewport()->setAcceptDrops(true);
    lw->setDragDropMode(QAbstractItemView::InternalMove);
    //QListWidgetItem::flags(Qt::ItemIsDragEnabled);
    //Qt::ItemIsDragEnabled;


    updatelw();
}


MainWindowo::~MainWindowo()
{
    delete ui;
}

void MainWindowo::startRootUpdate()
{
    if (RootUpdateTimer) RootUpdateTimer->start();
}

void MainWindowo::stopRootUpdate()
{
    if (RootUpdateTimer) RootUpdateTimer->stop();
}

void MainWindowo::timerTimeout()
{
    gSystem->ProcessEvents();
}

void MainWindowo::updatelw()
{
    QListWidget * lw = ui->padLayoutlw;

    qDebug() << "lenght" <<padLayoutv.length();

    for (int i = 0; i<padLayoutv.length(); i++ )
    {
        int npad = padLayoutv[i];

        qDebug() << "npad" << npad;

        QSpinBox *sb = new QSpinBox;
        sb->setValue(npad);
        QListWidgetItem *newItem = new QListWidgetItem;
        //newItem->setText(QString::number(npad));
        lw->addItem(newItem);
         lw->setItemWidget(newItem, sb);

    }
}

void MainWindowo::on_pushButton_clicked()
{
    c1.Clear();

    switch(location)
    {
    case bellow: ++divY; break;
    case right:  ++divX; break;
    case above:  ++divY; break;
    case left:   ++divX; break;
    }
    qDebug() <<"divX " <<divX <<"divY " <<divY;

    c1.Divide(1, 2);


//    /*TCanvas *c1 = new TCanvas("c1","c1",800,1000);
//    c1->Update();*/
//    /*source->Draw();*/
//    /*TH1F *source = new TH1F("source","source hist",100,-3,3);
//    source->FillRandom("gaus",1000);
//    TH1F *final = new TH1F("final","final hist",100,-3,3);


    /*
    // continued...

    for (Int_t i=0;i<10000;i++) {
        final->Fill(source->GetRandom());
    }
    //divX +=1;
    //divY = 3;
    c1.Divide(divX,2);
    //c1.SetBorderMode(1);
    c1.cd(1)->Divide(2,1);
    //int n = divX*divY+1;
    //c1.cd(2)->GetPad();
    for (int i = 1; i<5 ; i++)
    {
        qDebug() <<"aaaa" <<i;
        c1.cd(i)->cd(2);
        source.Draw();
    }

    c1.cd(3);
    final.Draw();
    //c1.cd(2)->cd(2);
    c1.cd(1)->cd(1);c1.cd(1);
    final.Draw();
    c1.cd(2);
    final.Draw();
    final.Draw();
    c1.cd(1)->cd(2);
    final.Draw();
    c1.cd(2);
    final.Draw();*/

    /*if (c1.cd(1)) {qDebug() <<"yes";}
    if (c1.cd(2)) {qDebug() <<"yess";}
    if (c1.cd(3)) {qDebug() <<"yesss";}
    if (c1.cd(4)) {qDebug() <<"yessss";}
    if (c1.cd(500)) {qDebug() <<"yesssss";}
*/

    TList* list = c1.GetListOfPrimitives();
    c1.cd(1)->SetTopMargin(0.25);
    qDebug() <<"toooooooooooooooooooooooooooop" <<c1.cd(2)->GetTopMargin();

    TVirtualPad *pad2 = c1.cd(2);
    TPad* tpad2 = dynamic_cast<TPad*>(pad2);

    int centerY = tpad2->GetBBoxCenter().GetY();
    qDebug() <<"centerY" <<centerY;
    int halfHeight = hei*0.5;
    qDebug() <<"halfHeight" <<halfHeight;
    int resultY = centerY - halfHeight;
    qDebug() <<"resultY" <<resultY;

    int height2 = tpad2->GetBBox().fHeight;

    tpad2->SetBBoxY1(resultY-50);
    height2 = tpad2->GetBBox().fHeight;


    TVirtualPad *pad1 = c1.cd(1);
    TPad* tpad1 = dynamic_cast<TPad*>(pad1);

    qDebug() <<tpad1;
    int height1 = tpad1->GetBBox().fHeight;

    centerY = tpad1->GetBBoxCenter().GetY();
    qDebug() <<"centerY" <<centerY;
    halfHeight = hei*0.5;
    qDebug() <<"halfHeight" <<halfHeight;
    resultY = centerY - halfHeight;
    qDebug() <<"resultY" <<resultY;

    tpad1->SetBBoxY1(resultY);
    height1 = tpad1->GetBBox().fHeight;



    /*for (TObject*o : list)
    {qDebug() <<"aa";}*/

    c1.cd(1);
    source.Draw();
    c1.cd(2);
    final.Draw();
    /*c1.cd(2);
    final.Draw();
    c1.cd(3);
    final.Draw();
    c1.cd(4);
    final.Draw();*/

    c1.cd();
    c1.Update();
}

void MainWindowo::on_pushButton_2_clicked()
{
    TVirtualPad *pad = c1.cd(1);
    TPad* tpad = dynamic_cast<TPad*>(pad);
    X1 = tpad->GetX1();
    X2 = tpad->GetX2();
    Y1 = tpad->GetX1();
    Y2 = tpad->GetX2();

    hei = tpad->GetBBox().fHeight;
    qDebug() <<"toooooooooooooooooooooooooooop" << hei;
}


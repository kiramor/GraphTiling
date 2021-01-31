#include "mainwindowo.h"
#include <QApplication>
#include <QDebug>
#include "TCanvas.h"


//Root
#include "TApplication.h"
#include "TObject.h"
#include "TH1.h"
#include "RVersion.h"
#if ROOT_VERSION_CODE < ROOT_VERSION(6,11,1)
#include "TThread.h"
#endif

int main(int argc, char *argv[])
{
    //starting cern ROOT application
    int rootargc=1;
    char *rootargv[] = {(char*)"qqq"};
    TApplication RootApp("My ROOT", &rootargc, rootargv);
    qDebug() << "Cern Root application created";
#if ROOT_VERSION_CODE < ROOT_VERSION(6,11,1)
    TThread::Initialize();
    qDebug() << ">TThread initialized";
#endif

    QApplication a(argc, argv);

    MainWindowo w;

    /*TH1F *source = new TH1F("source","source hist",100,-3,3);
    source->FillRandom("gaus",1000);
    TH1F *final = new TH1F("final","final hist",100,-3,3);


    // continued...

    for (Int_t i=0;i<10000;i++) {
        final->Fill(source->GetRandom());
    }
    w.c1.Divide(2,3);
    w.c1.cd(1);
    source->Draw();
    w.c1.cd(2);
    final->Draw();
    w.c1.cd();
    w.c1.Update();*/

    /*TH1* h1 = new TH1I("h1", "h1 title", 100, 0.0, 4.0);
    h1->FillRandom("gaus",10000);
    h1->Draw();*/

    w.show();
    return a.exec();
}

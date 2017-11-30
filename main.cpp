#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    //hämtat från minimal
//    QWidget *window = new QWidget;              //skapar en widget
//    window->setWindowTitle("Träningsdagbok");           //skapar titeln


    //Från Dirs, deklarerat i workouts.cpp
    //QString mFilename = "C:\Qt\Projektet\TraniningsDagbok\myfile.txt";

    //Write(mFilename);
    //Read(mFilename);



    //window ->show();


    MainWindow w;
    w.show();

    return a.exec();
}

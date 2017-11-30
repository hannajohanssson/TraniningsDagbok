#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workouts.h"
#include "workoutwindow.h"
#include <QApplication>
#include <Qlabel>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //hämtat från minimal
//    QWidget *window = new QWidget;              //skapar en widget
//    window->setWindowTitle("Träningsdagbok");           //skapar titeln
//    window->show();

//    parent->setWindowTitle("Workout Diary");
//    parent->show();

//    QLabel *label1 = new QLabel("Hanna Johansson\n940214\nCrossfit Athlete since: 2015\n");
//    label1->show();


//    ui->pushButton_2->hide();
//    ui->textEdit->hide();
//    ui->pushButton_3->hide();
//    ui->textEdit_2->hide();
//    ui->label_4->hide();
//    ui->label_5->hide();
//    ui->pushButton_4->hide();

    //från test
    // setCentralWidget((ui->plainTextEdit));      //lägga in fritext - spara träningspass?

    Workouts w1;
    w1.setDate(171130);
    w1.setWorkout("Running 10km");

        QString mFilename = "C:/Qt/Projektet/TraniningsDagbok/myfile.txt";

        w1.saveToFile(mFilename);
        w1.readFromFile(mFilename);




//        QCoreApplication a(argc, argv);

//        QString mFilename = "C:\Qt\Projektet\Testfiler, försök\myfile.txt";

//        Write(mFilename);
//        Read(mFilename);

//        return a.exec();


}

MainWindow::~MainWindow()
{
    delete ui;
}

////workouts
void MainWindow::on_pushButton_clicked()
{
    //från ppnt
//    workoutWindow *form2 = new workoutWindow;
//    form2->exec();


    //från test
    mWorkoutWindow = new workoutWindow(workouts, this);
    mWorkoutWindow -> show();





//    //add workouts
//    ui -> pushButton_2->show();
//    //show workouts
//    ui->pushButton_4->show();
    //När workout-knappen trycks -> öppnas nytt fönster (workoutwindow)
}


//void MainWindow::on_pushButton_2_clicked()
//{
//    //datum och ruta
//    ui->label_4->show();
//    ui->textEdit_2->show();
//    ui->label_5->show();
//    ui->textEdit->show();
//}

//void MainWindow::on_pushButton_3_clicked()
//{
//    //spara från text 1 ->  klassen, setDate
//   // ui ->textEdit -> get-funktion för o hämta text (två st)
//}

//void MainWindow::on_pushButton_4_clicked()
//{

//}


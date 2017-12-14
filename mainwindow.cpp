#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workouts.h"
#include "workoutwindow.h"
#include "workoutregister.h"
#include "workoutbankregister.h"
#include "prwindow.h"
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

    //läsa från fil

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

//    Workouts w1;
//    w1.setDate(171130);
//    w1.setWorkout("Running 10km");

//        QString mFilename = "C:/Qt/Projektet/TraniningsDagbok/myfile.txt";


//        w1.saveToFile(mFilename);
//        w1.readFromFile(mFilename);



        WorkoutRegister w1;
        w1.addWorkout(171205, "Running 10km");

        QString mFilename = "C:/Qt/Projektet/TraniningsDagbok/myfile.txt";


        w1.saveToFile(mFilename);
        w1.readFromFile(mFilename);

        workoutBankRegister wb1;
        workoutBankRegister wb2;
        wb1.addWorkoutWeight("Deadlift", "20171214", 130, 1);
        wb2.addWorkoutRunning("Running", "20171205", 10, 50);





//        QCoreApplication a(argc, argv);

//        QString mFilename = "C:\Qt\Projektet\Testfiler, försök\myfile.txt";

//        Write(mFilename);
//        Read(mFilename);

//        return a.exec();


}

MainWindow::~MainWindow()
{
    delete ui;
    //läsa till fil
}

////workouts
void MainWindow::on_pushButton_clicked()
{
    mWorkoutWindow = new workoutWindow(&workouts, this);
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


void MainWindow::on_pushButtonPR_clicked()
{
    mPRwindow = new PRwindow(&workoutbanks, this);
    mPRwindow -> show();
}

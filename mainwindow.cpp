#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workouts.h"
#include "workoutwindow.h"
#include "workoutregister.h"
#include "workoutbankregister.h"
#include "prwindow.h"
//#include "competition.h"
//#include "competitionregister.h"
//#include "competitionwindow.h"
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
    //workouts.readFromFile("filnamnet");


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
}

void MainWindow::on_pushButtonPR_clicked()
{
    mPRwindow = new PRwindow(&workoutbanks, this);
    mPRwindow -> show();
}


void MainWindow::on_pushButtonCompetitions_clicked()
{
//    mCompetitionWindow = new CompetitionWindow(&competitions, this);
//    mCompetitionWindow -> show();
}

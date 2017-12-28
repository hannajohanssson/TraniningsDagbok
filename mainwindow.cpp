#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workouts.h"
#include "workoutwindow.h"
#include "workoutregister.h"
#include "workoutbankregister.h"
#include "prwindow.h"
#include "competition.h"
#include "competitionregister.h"
#include "competitionwindow.h"
#include <QObject>
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

    QString WorkoutsFile = "C:/Qt/Projektet/TraniningsDagbok/WorkoutsFile.txt";
    workouts.readFromFile(WorkoutsFile);

    QString competitionsFile = "C:/Qt/Projektet/TraniningsDagbok/competitionsFile.txt";
    competitions.readFromFile(competitionsFile);
}

MainWindow::~MainWindow()
{
    delete ui;

    QString WorkoutsFile = "C:/Qt/Projektet/TraniningsDagbok/WorkoutsFile.txt";
    workouts.saveToFile(WorkoutsFile);

    QString competitionsFile = "C:/Qt/Projektet/TraniningsDagbok/competitionsFile.txt";
    competitions.saveToFile(competitionsFile);
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
    mCompetitionWindow = new CompetitionWindow(&competitions, this);
    mCompetitionWindow -> show();
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}

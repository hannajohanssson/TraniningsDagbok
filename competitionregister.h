#ifndef COMPETITIONREGISTER_H
#define COMPETITIONREGISTER_H
#include "competition.h"
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>         //behövs??
#include <QDir>
#include <QFileInfo>

#include <QObject>
#include <QWidget>

//#include <QtAlgorithms>
//#include <algorithm>		//istället för att själv skriva swap-funktionen




class CompetitionRegister
{
private:
    Competition** competitions;
    int capacity;
    int nrOfCompetitions;

    void Expand();



public:
    CompetitionRegister();
    ~CompetitionRegister();

    void addCompetition(int date, QString& name, int nrOfEvents, int finalPlace, QString& competitionInfo);
    QString toString() const;
    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    int getNrOfWorkouts();
    int removeLatest();
    QString ToStringSaveToFile() const;


    Competition* getCompetition(int index);


    QString sortedByPlace() const;

    int bestPlacement() const;
    QString bestPlacementString() const;




    //sortera tävlingar efter finalplace - ha i competitionregister
    //QString sortedByPlace() const;





};

#endif // COMPETITIONREGISTER_H



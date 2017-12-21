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

    void addCompetition(int date, QString& name, int nrOfEvents, QString& competitionInfo, int finalPlace);
    QString toString() const;
    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    int getNrOfWorkouts();

    //sortera tävlingar efter finalplace - ha i competitionregister
    //QString sortedByPlace() const;

    template <typename T>
    int partition(T* competitions,int start,int end);
    template <typename T>
    void quicksort(T* competitions, int start, int end);

};

#endif // COMPETITIONREGISTER_H



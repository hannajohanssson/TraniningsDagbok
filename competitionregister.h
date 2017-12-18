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
};

#endif // COMPETITIONREGISTER_H



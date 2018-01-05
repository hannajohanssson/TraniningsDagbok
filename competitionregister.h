#ifndef COMPETITIONREGISTER_H
#define COMPETITIONREGISTER_H
#include "competition.h"
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>
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

};

#endif // COMPETITIONREGISTER_H



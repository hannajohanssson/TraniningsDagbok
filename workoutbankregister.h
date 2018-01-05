#ifndef WORKOUTBANKREGISTER_H
#define WORKOUTBANKREGISTER_H

#include "workoutweight.h"
#include "workoutrunning.h"
#include "workoutbank.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QObject>
#include <QWidget>

class workoutBankRegister
{
private:
    workoutBank** workoutbanks;
    int capacity;
    int nrOfWorkouts;
    int Find(const workoutBank& workout) const;
    void Expand();

public:
    workoutBankRegister(int capacity = 10);
    ~workoutBankRegister();


    bool addWorkoutWeight(const QString& name, int date, int weight, int reps);
    bool addWorkoutRunning(const QString& name, int date, int distance, int time);
    QString getAllString() const;
    int removeLatest();

    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    QString ToStringAllSaveToFile() const;

    bool allWorkoutWeightAsString(QString* stringArr, int capacityOfStringArr) const;
    bool allWorkoutRunningAsString(QString* stringArr, int capacityOfStringArr) const;



    workoutBank* getPR(int index);

    int getNrOfWorkoutsPR() const;
    int getNrOfWorkoutsWeight() const;
    int getNrOfWorkoutsRunning() const;


};

#endif // WORKOUTBANKREGISTER_H

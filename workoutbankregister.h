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
    int Find(const workoutBank& workout) const;     //använda för att sortera/lägga till i meriter
    void Expand();

public:
//    workoutBankRegister();  //behövs tom??
    workoutBankRegister(int capacity = 10);
    ~workoutBankRegister();


    bool addWorkoutWeight(const QString& name, int date, int weight, int reps);
    bool addWorkoutRunning(const QString& name, int date, int distance, int time);
    QString getAllString() const;
    int removeLatest();

    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    QString ToStringAllSaveToFile() const;

    //int FindWorkout(QString& name, QString& date);

    //lägga till funktioner här som sorterar efter namn och vikt tex
   //QString SortedWeights() const; //skicka in vad?
//    QString SortedRunninng() const;


    bool allWorkoutWeightAsString(QString* stringArr, int capacityOfStringArr) const;
    bool allWorkoutRunningAsString(QString* stringArr, int capacityOfStringArr) const;



    workoutBank* getPR(int index);

    int getNrOfWorkoutsPR() const;
    int getNrOfWorkoutsWeight() const;      //behövs?
    int getNrOfWorkoutsRunning() const;


};

#endif // WORKOUTBANKREGISTER_H

#ifndef WORKOUTREGISTER_H
#define WORKOUTREGISTER_H
#include "workouts.h"
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

class WorkoutRegister
{
private:
    Workouts** workouts; //dubbelpekare??
    int capacity;
    int count;

    void Expand();

public:
    WorkoutRegister();
    ~WorkoutRegister();

    void addWorkout(int date, const QString& workout);

    //returnerar samtliga workouts
    QString toString() const;
    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    int getNrOfWorkouts() const;

};

#endif // WORKOUTREGISTER_H

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
    int Find(const Workouts& date) const;

public:
    WorkoutRegister();
    ~WorkoutRegister();

    void addWorkout(int date, const QString& workout);

    //returnerar samtliga workouts
    QString toString() const;
    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    int getNrOfWorkouts() const;
    bool removeWorkout(const int& date);

};

#endif // WORKOUTREGISTER_H

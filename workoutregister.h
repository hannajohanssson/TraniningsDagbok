#ifndef WORKOUTREGISTER_H
#define WORKOUTREGISTER_H
#include "workouts.h"
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

class WorkoutRegister
{
private:
    Workouts** workouts;
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

    //fixa en funktion för att få workout på plats index
    Workouts* getWorkout(int index);
    void saveToFile(QString fileName);
    void readFromFile(QString fileName);
    int getNrOfWorkouts() const;
    bool removeWorkout(const int& date);
    int removeLatest();
    QString ToStringSaveToFile() const;
    int getSpecWorkoutPlace(int userDate);
    QString getSpecWorkoutString(int userDate);

};

#endif // WORKOUTREGISTER_H

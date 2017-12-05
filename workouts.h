#ifndef WORKOUTS_H
#define WORKOUTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>         //behövs??
#include <QDir>
#include <QFileInfo>

class Workouts
{
private:
    int date;           //datum - medlemsvariabl, används för att söka på träningspass.
                            //Sorteras efter datum i lista ( = i den ordning de är inlagda)
    QString workout;        //Skriver in texten fritt, inte kunna sortera på ngt sätt.

public:
    Workouts(int date,const QString& workout);
    Workouts();
    ~Workouts();

    int getDate() const;
    void setDate(const int date);
    QString getWorkout() const;
    void setWorkout(const QString& workout);
    QString toString() const;

    //ha i workoutregister
//    void saveToFile(QString fileName);
//    void readFromFile(QString fileName);
    //void addWorkout(int date, const QString& workout);



};

#endif // WORKOUTS_H

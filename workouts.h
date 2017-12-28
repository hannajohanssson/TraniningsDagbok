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
    int date;
    QString workout;
public:
    Workouts(int date,const QString& workout);
    Workouts();
    ~Workouts();

    int getDate() const;
    void setDate(const int date);
    QString getWorkout() const;
    void setWorkout(const QString& workout);
    QString toString() const;
    bool operator==(const Workouts& other) const;
    QString ToStringSaveToFile() const;
};

#endif // WORKOUTS_H

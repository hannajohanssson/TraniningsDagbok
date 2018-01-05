#include "workouts.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>



Workouts::Workouts(int date,const QString &workout)
{
    this->date=date;
    this->workout=workout;
}

Workouts::Workouts()
{
    date = 0;
    workout ="";
}

Workouts::~Workouts()
{

}

int Workouts::getDate() const
{
    return date;
}


void Workouts::setDate(const int date)
{
    this->date=date;
}

QString Workouts::getWorkout() const
{
    return workout;
}

void  Workouts::setWorkout(const QString& workout)
{
    this->workout=workout;
}


QString Workouts::toString() const
{
    QString retString;
    retString += "Date: " + QString::number(date) + "\n";
    retString += "Workout:\n" + workout + "\n";

    return retString;
}

bool Workouts::operator==(const Workouts &other) const
{
    return this->getDate() == other.getDate();
}

QString Workouts::ToStringSaveToFile() const
{
    QString retString;
    retString += QString::number(this->date) + "\n";
    retString += this->workout + "\n";
    //quick fix
    retString += "WORKOUT_END\n";

    return retString;
}

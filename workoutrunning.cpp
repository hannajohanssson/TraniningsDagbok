#include "workoutrunning.h"

#include <QMessageBox>

QString workoutRunning::toStringSpecific() const
{
    QString retString;
    retString += "Distance: " + QString::number(distance) + "\n";
    retString += "Time: " + QString::number(time) + "\n";

    return retString;
}

QString workoutRunning::toStringSpecificFile() const
{
    QString retString;
    retString += QString::number(0) + "\n";
    retString += QString::number(distance) + "\n";
    retString += QString::number(time) + "\n";


    return retString;
}

workoutRunning::workoutRunning(const QString &name, int date, int distance, int time)
    : workoutBank(name, date)
{
    this->distance = distance;
    this->time = time;
}

workoutRunning::workoutRunning()
{

}

workoutRunning::~workoutRunning()
{

}

void workoutRunning::setDistance(int distance)
{
    this->distance = distance;
}

void workoutRunning::setTime(int time)
{
    this->time = time;
}

int workoutRunning::getDistance() const
{
    return distance;
}

int workoutRunning::getTime() const
{
    return time;
}

QString workoutRunning::ToStringSaveToFile() const
{
    QString retString;
    retString += QString::number(this->distance) + "\n";
    retString += QString::number(this->time) + "\n";
    retString += "WORKOUT_END\n";

    return retString;
}

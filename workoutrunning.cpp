#include "workoutrunning.h"

QString workoutRunning::toStringSpecific() const
{
    QString retString;
    retString += "Distance: " + QString::number(distance) + "\n";
    retString += "Time: " + QString::number(time) + "\n";

    return retString;
}

workoutRunning::workoutRunning(const QString &name, const QString &date, int distance, int time)
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

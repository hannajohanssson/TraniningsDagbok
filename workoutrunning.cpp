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

void workoutRunning::setDistance(int distance) const
{

}

void workoutRunning::setTime(int time) const
{

}

int workoutRunning::getDistance() const
{

}

int workoutRunning::getTime() const
{

}

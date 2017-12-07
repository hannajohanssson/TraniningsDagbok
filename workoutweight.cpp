#include "workoutweight.h"

QString workoutWeight::toStringSpecific() const
{
    QString retString;
    retString += "Weight: " + QString::number(weight) + "\n";
    retString += "Reps: " + QString::number(reps) + "\n";

    return retString;

}

workoutWeight::workoutWeight(const QString &name, const QString &date, int weight, int reps)
    : workoutBank(name, date)
{
    this->weight = weight;
    this->reps = reps;

}

workoutWeight::workoutWeight()
{

}

workoutWeight::~workoutWeight()
{

}

void workoutWeight::setWeight(int weight)
{

}

void workoutWeight::setreps(int reps)
{

}

int workoutWeight::getWeight() const
{

}

int workoutWeight::getReps() const
{

}

bool workoutWeight::operator==(int weight) const
{

}

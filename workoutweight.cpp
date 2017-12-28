#include "workoutweight.h"

QString workoutWeight::toStringSpecific() const
{
    QString retString;
    retString += "Weight: "  + QString::number(weight)  + "\n";  //
    retString += "Reps: " + QString::number(reps) + "\n";

    return retString;

}

QString workoutWeight::toStringSpecificFile() const
{
    QString retString;
    retString += QString::number(1) + "\n";
    retString += QString::number(weight)  + "\n";
    retString += QString::number(reps) + "\n";

    return retString;

}

workoutWeight::workoutWeight(const QString &name, int date, int weight, int reps)
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
    this->weight=weight;
}

void workoutWeight::setreps(int reps)
{
    this->reps=reps;
}

int workoutWeight::getWeight() const
{
    return weight;
}

int workoutWeight::getReps() const
{
    return reps;
}

QString workoutWeight::ToStringSaveToFile() const
{
    QString retString;
    retString += 1;
    retString += QString::number(this->weight) + "\n";
    retString += QString::number(this->reps) + "\n";
    retString += "WORKOUT_END\n";

    return retString;
}



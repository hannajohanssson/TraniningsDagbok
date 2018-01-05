#include "workoutbank.h"

workoutBank::workoutBank(const QString &name, const int date)
{
    this->name = name;
    this->date= date;
}

workoutBank::workoutBank()
{
    name ="";
    date = 0;
}

workoutBank::~workoutBank()
{

}



bool workoutBank::operator==(const workoutBank &other) const
{
    bool retValue= false;
    if(this->name == other.name)            //lägga tll om den ska jämföra fler
        retValue = true;

    return retValue;

}

QString workoutBank::getName() const
{
    return name;
}

int workoutBank::getDate() const
{
    return date;
}

QString workoutBank::getNameDate() const
{
    QString retString;
    retString += name + "\n";
    retString += QString::number(date) + "\n";

    return retString;
}

QString workoutBank::toString() const
{
    QString retString;
    retString += "Name: " + name + "\n";
    retString += "Date: " + QString::number(date) + "\n";
    retString += toStringSpecific() + "\n"; //om toStringSpecific innehåller int?

    return retString;
}

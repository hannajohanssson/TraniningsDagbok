#include "workoutbank.h"

workoutBank::workoutBank(const QString &name, const QString &date)
{
    this->name = name;
    this->date= date;
}

workoutBank::workoutBank()
{
    name ="";
    date ="";
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

QString workoutBank::getDate() const
{
    return date;
}

QString workoutBank::getNameDate() const
{
    QString retString;
    retString += "Name: " + name + "\n";
    retString += "Date: " + date + "\n";

    return retString;
}

QString workoutBank::toString() const
{
    QString retString;
    retString += getNameDate() + "\n";
    retString += toStringSpecific() + "\n"; //om toStringSpecific innehåller int?

    return retString;
}


//workoutWeight
//QString workoutWeight::toStringSpecific() const
//{
//    QString retString;
//    retString += "Weight: " + QString::number(weight) + "\n";
//    retString += "Reps: " + QString::number(reps) + "\n";

//    return retString;

//}

//workoutWeight::workoutWeight(const QString &name, const QString &date, int weight, int reps)
//    : workoutBank(name, date)
//{
//    this->weight = weight;
//    this->reps = reps;

//}

//workoutWeight::workoutWeight()
//{

//}

//workoutWeight::~workoutWeight()
//{

//}

//void workoutWeight::setWeight(int weight)
//{

//}

//void workoutWeight::setreps(int reps)
//{

//}

//int workoutWeight::getWeight() const
//{

//}

//int workoutWeight::getReps() const
//{

//}

//bool workoutWeight::operator==(int weight) const
//{

//}


//workoutRunning
//QString workoutRunning::toStringSpecific() const
//{
//    QString retString;
//    retString += "Distance: " + QString::number(distance) + "\n";
//    retString += "Time: " + QString::number(time) + "\n";

//    return retString;
//}

//workoutRunning::workoutRunning(const QString &name, const QString &date, int distance, int time)
//    : workoutBank(name, date)
//{
//    this->distance = distance;
//    this->time = time;
//}

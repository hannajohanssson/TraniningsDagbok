#include "competition.h"

Competition::Competition(int date, QString &name, int nrOfEvents, QString &competitionInfo, int finalPlace)
{
    this->date = date;
    this->name = name;
    this->nrOfEvents = nrOfEvents;
    this->competitionInfo = competitionInfo;
    this->finalPlace = finalPlace;

}

Competition::Competition()
{
    this->date = 0;
    this->name = "";
    this->nrOfEvents = 0;
    this->competitionInfo = "";
    this->finalPlace = 0;

}

Competition::~Competition()
{

}

int Competition::getDate() const
{
    return date;
}

QString Competition::getName() const
{
    return name;
}

int Competition::getNrOfEvents() const
{
    return nrOfEvents;
}

QString Competition::getCompetitionInfo() const
{
    return competitionInfo;
}

int Competition::getFinalPlace() const
{
    return finalPlace;
}

void Competition::setDate(const int date)
{
    this->date = date;
}

void Competition::setName(const QString &name)
{
    this->name = name;
}

void Competition::setNrOfEvents(const int nrOfEvents)
{
    this->nrOfEvents = nrOfEvents;
}

void Competition::setCompetitionInfo(const QString &competitionInfo)
{
    this->competitionInfo = competitionInfo;
}

void Competition::setFinalPlace(const int finalPlace)
{
    this->finalPlace = finalPlace;
}



bool Competition::operator<(const Competition &other) const
{
    return this->finalPlace < other.getFinalPlace();
}

QString Competition::toString() const
{
    QString retString;
    retString += "Name: " + name + "\n";
    retString += "Date: " + QString::number(date) +"\n";
    retString += "Placement: " + QString::number(finalPlace) + "\n";
    retString += "Number of Events: " + QString::number(nrOfEvents) + "\n";
    retString += "Description of the competition:\n" + competitionInfo + "\n";
    return retString;
}

QString Competition::ToStringSaveToFile() const
{
    QString retString;
    retString += this->name + "\n";
    retString += QString::number(this->date) + "\n";
    retString += QString::number(finalPlace) + "\n";
    retString += QString::number(nrOfEvents) + "\n";
    retString += competitionInfo + "\n";
    retString += "WORKOUT_END\n";

    return retString;
}

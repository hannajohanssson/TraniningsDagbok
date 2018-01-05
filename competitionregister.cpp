#include "competitionregister.h"

void CompetitionRegister::Expand()
{
    this->capacity +=5;
    Competition** temp = new Competition*[this->capacity];
    for(int i=0; i<nrOfCompetitions; i++)
    {
        temp[i] = competitions[i];
    }
    delete[] competitions;
    competitions = temp;
}

CompetitionRegister::CompetitionRegister()
{
    nrOfCompetitions = 0;
    capacity = 20;
    competitions = new Competition*[capacity];
}


CompetitionRegister::~CompetitionRegister()
{

}

void CompetitionRegister::addCompetition(int date, QString &name, int nrOfEvents, int finalPlace, QString &competitionInfo)
{
   if (nrOfCompetitions == capacity)
            {
                Expand();
            }
    competitions[nrOfCompetitions++] = new Competition(date, name, nrOfEvents, competitionInfo, finalPlace);
}

QString CompetitionRegister::toString() const
{
    QString retString = "";
    for(int i=0; i<nrOfCompetitions; i++)
    {
        retString += competitions[i]->toString();
    }
    return retString;
}

void CompetitionRegister::saveToFile(QString fileName)
{
    QFile mFile(fileName);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out << "Could not open file for writing" << "\n";
    }
    QTextStream out (&mFile);
    out << getNrOfWorkouts() << "\n";
    out << ToStringSaveToFile();

    mFile.flush();
    mFile.close();
}

void CompetitionRegister::readFromFile(QString fileName)
{
    QFile mFile(fileName);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out << "Could not open file for reading" << "\n";
    }
    QTextStream in (&mFile);
    int counterFile = in.readLine().toInt();
    for(int i=0; i<counterFile; i++)
    {
        QString name = in.readLine();
        int date = in.readLine().toInt();
        int nrOfEvents = in.readLine().toInt();
        int finalPlace = in.readLine().toInt();
        QString competitionInfo = "";
        QString text = in.readLine();

        //"WORKOUT_END\n"
        while(!text.endsWith("WORKOUT_END"))
        {
            if(competitionInfo.length() > 0)
                 competitionInfo += "\n";
            competitionInfo += text;
            text = in.readLine();
        }
        addCompetition(date, name, nrOfEvents, finalPlace, competitionInfo);
    }

    mFile.flush();
    mFile.close();
}

int CompetitionRegister::getNrOfWorkouts()
{
    return nrOfCompetitions;
}

int CompetitionRegister::removeLatest()
{
    if (nrOfCompetitions == 0)
        return nrOfCompetitions;
    else
    {
        delete competitions[nrOfCompetitions-1];
        nrOfCompetitions--;

        return nrOfCompetitions;
    }

}

QString CompetitionRegister::ToStringSaveToFile() const
{
    QString retString = "";

    for (int i=0; i<nrOfCompetitions; i++)
    {
        retString += competitions[i]->ToStringSaveToFile();
    }
    return retString;
}

Competition *CompetitionRegister::getCompetition(int index)
{
    if(index < 0)index = 0;
    else if(index >= getNrOfWorkouts())index = 0;
    return competitions[index];
}

QString CompetitionRegister::sortedByPlace() const
{
    QString retstring;
       int index = 1000;
       int placeInArr = -1;
        for(int i=0; i<nrOfCompetitions; i++)
        {
            if (competitions[i]->getFinalPlace() < index)
            {
                index = competitions[i]->getFinalPlace();
                placeInArr = i;
                if(i != nrOfCompetitions)
                {
                   competitions[0] = competitions[placeInArr];
                   competitions[placeInArr] = competitions[0];

                   retstring += competitions[i]->toString();
                }
            }
        }
     return retstring;
}

int CompetitionRegister::bestPlacement() const
{
    int bestPlacement = 1000;
    int placeInArr = -1;

    for(int i=0; i<nrOfCompetitions; i++)
    {
        if(competitions[i]->getFinalPlace() < bestPlacement)
        {
            bestPlacement = competitions[i]->getFinalPlace();
            placeInArr = i;
        }
    }
    return placeInArr;
}

QString CompetitionRegister::bestPlacementString() const
{
    int placeInArr = bestPlacement();
    QString retString;
    retString = competitions[placeInArr]->toStringBestComp();
    return retString;
}



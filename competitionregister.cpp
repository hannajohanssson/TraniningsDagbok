#include "competitionregister.h"

void CompetitionRegister::Expand()
{
    this->capacity +=5;
    Competition** temp = new Competition*[this->capacity];
    for(int i=0; i<nrOfCompetitions; i++)
    {
        temp[i] = competitions[i];
    }
    delete[] competitions; //avallokerar gammal array
    competitions = temp; //låt medlemsvariabeln workoutbanks peka på den nya större arrayen istället
}

CompetitionRegister::CompetitionRegister()
{
    nrOfCompetitions = 0;
    capacity = 20;
    competitions = new Competition*[capacity];       //pekare om dubbelpekare
}


CompetitionRegister::~CompetitionRegister()
{

}

void CompetitionRegister::addCompetition(int date, QString &name, int nrOfEvents, QString &competitionInfo, int finalPlace)
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

    if(!mFile.open(QFile::WriteOnly | QFile::Text))         //öppnar filen
    {
        qDebug() << "Could not open file for writing";
        return;
    }
    QTextStream out (&mFile);
    out << toString() << "\n";
//spara alla mha array

    mFile.flush();
    mFile.close();                          //om ngt skrivs - stäng den igen!


}

void CompetitionRegister::readFromFile(QString fileName)
{
    QFile mFile(fileName);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open file for reading";
        return;
    }
    QTextStream in (&mFile);
    QString mText = in.readAll();

    qDebug () << mText;

    mFile.flush();
    mFile.close();
}

int CompetitionRegister::getNrOfWorkouts()
{
    return nrOfCompetitions;
}

int CompetitionRegister::removeLatest()
{
    delete competitions[nrOfCompetitions-1];
    nrOfCompetitions--;
    return nrOfCompetitions;
}



//QString CompetitionRegister::sortedByPlace() const
//{
//    QString retstring;
//    int index = 1000;
//    for(int i=0; i<nrOfCompetitions; i++)
//    {
//        if (competitions->getFinalPlace() < index)
//        {

//        }


//    }
//    return retstring;
//}



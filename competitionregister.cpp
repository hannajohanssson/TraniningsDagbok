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
        //ADD: int date, QString& name, int nrOfEvents, QString& competitionInfo, int finalPlace

        int date = in.readLine().toInt();
        QString name = in.readLine();
        int nrOfEvents = in.readLine().toInt();
        QString competitionInfo = "";
        int finalPlace = in.readLine().toInt();

        QString text = in.readLine();

        //"WORKOUT_END\n"
        while(!text.endsWith("WORKOUT_END\n"))
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
    delete competitions[nrOfCompetitions-1];
    nrOfCompetitions--;
    return nrOfCompetitions;
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



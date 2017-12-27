#include "workouts.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>         //behövs??
#include <QDir>
#include <QFileInfo>



Workouts::Workouts(int date,const QString &workout)
{
    this->date=date;
    this->workout=workout;
//    count =0;
//    capacity = 20;
//    workoutsAll= new Workouts[capacity];
    //readFromFile();
}

Workouts::Workouts()
{
    date = 0;
    workout ="";
//    count =0;
//    capacity = 20;
//    workoutsAll = new Workouts[capacity];
}

Workouts::~Workouts()
{

}

int Workouts::getDate() const
{
    return date;
}


void Workouts::setDate(const int date)      //om två träningspass på en dag - lägga in i två omgångar?
{
    this->date=date;
}

QString Workouts::getWorkout() const
{
    return workout;
}

void  Workouts::setWorkout(const QString& workout)
{
    this->workout=workout;
}


QString Workouts::toString() const
{/*std::string retString;
    retString += Location::ToString();
    retString += "Population: " + std::to_string(population) + "\n";
    retString += "Area: " + std::to_string(area) + "\n";
    return retString;*/

    QString retString;
    retString += "Date: " + QString::number(date) + "\n";
    retString += "Workout:\n" + workout + "\n";

    return retString;



}

bool Workouts::operator==(const Workouts &other) const
{
    return this->getDate() == other.getDate();
}

QString Workouts::ToStringSaveToFile() const
{
    QString retString;
    retString += QString::number(this->date) + "\n";
    retString += this->workout + "\n";
    //quick fix
    retString += "WORKOUT_END\n";

    return retString;
}

//från dirs
//void Workouts::saveToFile(QString fileName)
//{
//    QFile mFile(fileName);

//    if(!mFile.open(QFile::WriteOnly | QFile::Text))         //öppnar filen
//    {
//        qDebug() << "Could not open file for writing";
//        return;
//    }
//    QTextStream out (&mFile);
//    out << toString() << "\n";
////spara alla mha array

//    mFile.flush();
//    mFile.close();                          //om ngt skrivs - stäng den igen!
//}

//void Workouts::readFromFile(QString fileName)
//{
//    QFile mFile(fileName);

//    if(!mFile.open(QFile::ReadOnly | QFile::Text))
//    {
//        qDebug() << "Could not open file for reading";
//        return;
//    }
//    QTextStream in (&mFile);
//    QString mText = in.readAll();

//    qDebug () << mText;

//    mFile.flush();
//    mFile.close();

//}

//void Workouts::addWorkout(int date, const QString &workout)
//{

//    //expandering

//    //arr [counter ] = new klassnamn (date, namn)
//    //workoutsAll[count] = new Workouts(date, workout);

////    if (count < capacity)
////    {
////        workoutsAll[count].setDate();
////        workoutsAll[count].setWorkout();
////        count ++;
////    }



//}


    //Lägga till i main!
//    QString mFilename = "C:\Qt\Projektet\Testfiler, försök\myfile.txt";

//    Write(mFilename);
//    Read(mFilename);



//}




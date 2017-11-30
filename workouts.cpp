#include "workouts.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>         //behövs??
#include <QDir>



Workouts::Workouts(int date, QString &workout)
{
    date = 0;
    workout ="";
}

Workouts::~Workouts()
{

}

int Workouts::getDate() const
{
    return date;
}


void Workouts::setDate(const int date)      //om två träningspass på en dag - lägga in i två omgångar?
{//this->name = name;
    this->date=date;
}

QString  Workouts::getWorkout() const
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

//från dirs
//void Workouts::saveToFile(QString fileName)
//{
//    QFile file(filename);

//    if(!mFile.open(QFile::WriteOnly | QFile::Text))         //öppnar filen
//    {
//        qDebug() << "Could not open file for writing";
//        return;
//    }
//    QTextStream out (&mFile);
//    out << "Hello World";

//    mFile.flush();
//    mFile.close();                          //om ngt skrivs - stäng den igen!
//}

//void Workouts::readFromFile(QString fileName)
//{
//    QFile mFile(Filename);

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


    //Lägga till i main!
//    QString mFilename = "C:\Qt\Projektet\Testfiler, försök\myfile.txt";

//    Write(mFilename);
//    Read(mFilename);



//}




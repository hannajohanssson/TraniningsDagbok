#include "workoutregister.h"



WorkoutRegister::WorkoutRegister()
{
    count = 0;
    capacity = 20;
    workouts = new Workouts*[capacity];       //pekare om dubbelpekare
}

WorkoutRegister::~WorkoutRegister()
{

}


void WorkoutRegister::Expand()
{
    capacity = capacity * 2;
    Workouts** temp = new Workouts*[capacity];
    for (int i =0; i<count; i++)
    {
        temp[i] = workouts[i];
    }
    delete[] workouts;
    workouts = temp;
}

void WorkoutRegister::addWorkout(int date, const QString &workout)
{
    if (count == capacity)
            {
                Expand();
            }
    workouts[count++] = new Workouts(date, workout);
}

QString WorkoutRegister::toString() const
{
    QString retString = "";
    for(int i=0; i<count; i++)
    {
        retString = workouts[i]->toString();
    }
    return retString;
}

void WorkoutRegister::saveToFile(QString fileName)
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

void WorkoutRegister::readFromFile(QString fileName)
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

int WorkoutRegister::getNrOfWorkouts() const
{
    return count;

}

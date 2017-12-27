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

int WorkoutRegister::Find(const Workouts &date) const
{
    int index = -1;
    for(int i =0; i<count; i++)
    {
        if (date == *workouts[i])
        {
            index = i;
            i = count;
        }
    }
    return index;
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
        retString += workouts[i]->toString() + "\n";
    }
    return retString;
}

Workouts* WorkoutRegister::getWorkout(int index)
{
    if(index < 0)index = 0;
    else if(index >= getNrOfWorkouts())index = 0;
    return workouts[index];
}

void WorkoutRegister::saveToFile(QString fileName)
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


    //gamla koden

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
//    mFile.close();





}

void WorkoutRegister::readFromFile(QString fileName)
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
        int date = in.readLine().toInt();
        QString workout = "";
        QString text = in.readLine();

        //"WORKOUT_END\n"
        while(!text.endsWith("WORKOUT_END\n"))
        {
            if(workout.length() > 0)
                workout += "\n";

            workout += text;

            text = in.readLine();
        }
        addWorkout(date, workout);

    }

    mFile.flush();
    mFile.close();




    //Gamla koden

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

}

int WorkoutRegister::getNrOfWorkouts() const
{
    return count;

}

bool WorkoutRegister::removeWorkout(const int& date)
{
    Workouts toRemove(date, "temp");
    int index = Find(toRemove);
    if(index != -1)
    {
        delete workouts[index];
        workouts[index] = workouts[--count];
        workouts[count] = nullptr;
    }
    return index != -1;
}

QString WorkoutRegister::ToStringSaveToFile() const
{
    QString retString = "";

    for (int i=0; i<count; i++)
    {
        retString += workouts[i]->ToStringSaveToFile();
    }

    return retString;
}

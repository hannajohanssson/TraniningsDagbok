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
        while(!text.endsWith("WORKOUT_END"))
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

int WorkoutRegister::removeLatest()
{
    if (count == 0)
        return count;
    else
    {
        delete workouts[count-1];
        count--;

        return count;
    }
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

int WorkoutRegister::getSpecWorkoutPlace(int userDate)
{
    int placeInArr = -1;
    for(int i=0; i<count; i++)
    {
        if(workouts[i]->getDate() == userDate)
        {

            placeInArr = i;
        }
    }
    return placeInArr;
}

QString WorkoutRegister::getSpecWorkoutString(int userDate)
{
    QString retString;
    int placeInArr = getSpecWorkoutPlace(userDate);
    if(placeInArr == -1)
        retString = "No Workout was found";
    else
        retString = workouts[placeInArr]->toString();

    return retString;
}

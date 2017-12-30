#include "workoutbankregister.h"
#include <QMessageBox>
#include <typeinfo>

int workoutBankRegister::Find(const workoutBank &workout) const
{
    int index=-1;
    for(int i=0; i<nrOfWorkouts; i++)
    {
        if(workout == *workoutbanks[i])
        {
            index =i;
            i = nrOfWorkouts;
        }
    }
    return index;
}

void workoutBankRegister::Expand()
{
    this->capacity +=5;
    workoutBank** temp = new workoutBank*[this->capacity];
    for(int i=0; i<nrOfWorkouts; i++)
    {
        temp[i] = workoutbanks[i];
    }
    delete[] workoutbanks;
    workoutbanks = temp;
}

workoutBankRegister::workoutBankRegister(int capacity)
{
    this->capacity=capacity;
    this->nrOfWorkouts =0;
    this->workoutbanks = new workoutBank*[this->capacity];
}

workoutBankRegister::~workoutBankRegister()
{
    delete[] workoutbanks;
}

bool workoutBankRegister::addWorkoutWeight(const QString &name, int date, int weight, int reps)
{
    bool added = false;
    workoutWeight toAdd(name, date, weight, reps);
    if (Find(toAdd) == -1)
    {
        if(nrOfWorkouts == capacity)
        {
            Expand();
        }
        workoutbanks[nrOfWorkouts++] = new workoutWeight(toAdd);
        added = true;
    }
    return added;
}

bool workoutBankRegister::addWorkoutRunning(const QString &name, int date, int distance, int time)
{
    bool added = false;
    workoutRunning toAdd(name, date, distance, time);
    if (Find(toAdd) == -1)
    {
        if(nrOfWorkouts == capacity)
        {
            Expand();
        }
        workoutbanks[nrOfWorkouts++] = new workoutRunning(toAdd);
        added = true;
    }
    return added;
}

QString workoutBankRegister::getAllString() const
{
    QString retString;
    for (int i=0; i<nrOfWorkouts; i++)
    {
        retString += workoutbanks[i]->toString() + "\n";
    }
    return retString;
}

int workoutBankRegister::removeLatest()
{
    if(nrOfWorkouts == 0)
        return nrOfWorkouts;
    else
    {
        delete workoutbanks[nrOfWorkouts-1];
        nrOfWorkouts --;

        return nrOfWorkouts;
    }
}

void workoutBankRegister::saveToFile(QString fileName)
{
    QFile mFile(fileName);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out << "Could not open file for writing" << "\n";
    }
    QTextStream out (&mFile);
    out << getNrOfWorkoutsPR() << "\n";
    out << ToStringAllSaveToFile();

    mFile.flush();
    mFile.close();
}

void workoutBankRegister::readFromFile(QString fileName)
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
        int id = in.readLine().toInt();
        //runnig 0
        //weight 1
        int distance;
        int time;
        int weight;
        int reps;
        if (id == 0)
        {
            distance = in.readLine().toInt();
            time = in.readLine().toInt();
            addWorkoutRunning(name, date, distance, time);
        }
        else
        {
            weight = in.readLine().toInt();
            reps = in.readLine().toInt();
            addWorkoutWeight(name, date, weight, reps);
        }


    }

    mFile.flush();
    mFile.close();



}

QString workoutBankRegister::ToStringAllSaveToFile() const
{
    QString retString = "";

    for (int i=0; i<nrOfWorkouts; i++)
    {
        retString += workoutbanks[i]->getNameDate();
        retString += workoutbanks[i]->toStringSpecificFile();
    }
    return retString;



}

//QString workoutBankRegister::SortedWeights() const
//{
    //Dynamic_cast... Behövs för att komma åt subklassernas _egna_ medlemsfunktioner.
//        for (int i = 0; i < 5; i++)
//        {
//            //Type inference, nytt i C++11, (eller var det C++14?)
//            //auto trianglePtr = dynamic_cast<Triangle*>(baseArray[i]);
//            Triangle* trianglePtr = dynamic_cast<Triangle*>(baseArray[i]);
//            if (trianglePtr != nullptr)


//    for (int i = 0; i < 5; i++)
//        {
//            std::cout << "At index " << i << " we have a " << typeid(*baseArray[i]).name() << "\n";
//        }
//        std::cin.get();
//        //Typeid...
//        if (typeid(*baseArray[0]) == typeid(Square))



//        QString retString;
//        int index = -1;


//        for (int i =0; i<nrOfWorkouts; i++)
//        {
//            workoutBank* workoutPtr = dynamic_cast<workoutBank*>(workoutbanks[i]);
//            if(workoutPtr != nullptr)
//            {
//                if(workoutbanks[i]->getName() == "Deadlift")
//                {
//                    if(typeid(*workoutbanks[i]).weight()  )

//                    if(index < 1)       //jämföra vikter??
//                        index = i;
//                }
//            }
//            retString += workoutbanks[]
//         }


//}

//QString workoutBankRegister::SortedWeights() const
//{
//    QString retString;
//    int index = -1;
//    for (int i =0; i<nrOfWorkouts; i++)
//    {
//        if(workoutbanks[i]->getName() == "Deadlift")
//        {


//            if(index < 1)       //jämföra vikter??
//                index = i;
//        }
//    }
//    retString += workoutbanks[]

//}

//QString workoutBankRegister::SortedRunninng() const
//{
//    QString retString;
//    //int index = -1;
//    for (int i =0; i<nrOfWorkouts; i++)
//    {
//        if (workoutRunning.getDistance() == 10)
//        {
//            retString += 0;
//        }

//    }


//QString workoutBankRegister::getAllString() const
//{
//    QString retString;
//    int index = -1;
//    index =  workoutBankRegister.FindWorkout(name, date);
//    retString+= "Name: " ++ workoutBankRegister.
//    if ()
//}

//int workoutBankRegister::FindWorkout(QString& name, QString& date)
//{
////    int index = -1;
////    for(int i=0; i<nrOfWorkouts; i++)
////    {
////        if(workoutWeight[i].getDate() == date && workoutWeight[i].getName() == name)
////            index = i;
////    }
// return 0;
//}

bool workoutBankRegister::allWorkoutWeightAsString(QString *stringArr, int capacityOfStringArr) const
{
    int index = 0;
    bool retValue = false;
    if(capacityOfStringArr >= getNrOfWorkoutsWeight())
    {
        retValue = true;
        for(int i=0; i<nrOfWorkouts; i++)
        {
            if(typeid(workoutWeight) == typeid(*workoutbanks[i]))        //dynamic_cast<workoutWeight*>(workoutbanks[i] != nullptr)
            {
                    stringArr[index++] = workoutbanks[i]->toString();
            }
        }
    }
    return retValue;

}

bool workoutBankRegister::allWorkoutRunningAsString(QString *stringArr, int capacityOfStringArr) const
{
    int index = 0;
    bool retValue = false;
    if(capacityOfStringArr >= getNrOfWorkoutsRunning())
    {
        retValue = true;
        for(int i=0; i<nrOfWorkouts; i++)
        {
            if(typeid(workoutRunning) == typeid(*workoutbanks[i]))        //dynamic_cast<workoutWeight*>(workoutbanks[i] != nullptr)
            {
                    stringArr[index++] = workoutbanks[i]->toString();
            }
        }
    }
    return retValue;

}

workoutBank *workoutBankRegister::getPR(int index)
{
    if(index < 0)index = 0;
    else if(index >= getNrOfWorkoutsPR())index = 0;
    return workoutbanks[index];

}

int workoutBankRegister::getNrOfWorkoutsPR() const
{
    return nrOfWorkouts;
}

int workoutBankRegister::getNrOfWorkoutsWeight() const
{
    int counter =0;
    for(int i=0; i<nrOfWorkouts; i++)
    {
        if(typeid(workoutWeight) == typeid(*workoutbanks[i]))       //går att skriva if(dynamic_cast<workoutWeight*>(workoutbanks[i] != nullptr))
        {
            ++counter;
        }
    }
    return counter;

}

int workoutBankRegister::getNrOfWorkoutsRunning() const
{
    int counter =0;
    for(int i=0; i<nrOfWorkouts; i++)
    {
        if(typeid(workoutRunning) == typeid(*workoutbanks[i]))       //går att skriva if(dynamic_cast<workoutWeight*>(workoutbanks[i] != nullptr))
        {
            ++counter;
        }
    }
    return counter;


}

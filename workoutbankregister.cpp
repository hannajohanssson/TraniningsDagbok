#include "workoutbankregister.h"

workoutBankRegister::workoutBankRegister()
{

}

int workoutBankRegister::Find(const workoutBank &workout) const
{
    int index=-1;
    for(int i=0; i<nrOfWorkouts; i++)
    {
        if(workout == *workoutbanks[i])
        {
            index =i;
            i = nrOfWorkouts;   //avbryter loopen
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
    delete[] workoutbanks; //avallokerar gammal array
    workoutbanks = temp; //låt medlemsvariabeln workoutbanks peka på den nya större arrayen istället


}

workoutBankRegister::workoutBankRegister(int capacity)
{
    this->capacity=capacity;
    this->nrOfWorkouts =0;
    this->workoutbanks = new workoutBank*[this->capacity];
}

workoutBankRegister::~workoutBankRegister()
{

}

bool workoutBankRegister::addWorkoutWeight(const QString &name, const QString &date, int weight, int reps)
{
    bool added = false;
    workoutWeight toAdd(name, date, weight, reps);
    if (Find(toAdd) == -1)
    {
        if(nrOfWorkouts = capacity)
        {
            Expand();
        }
        workoutbanks[nrOfWorkouts++] = new workoutWeight(toAdd);
        added = true;
    }
    return added;

}

bool workoutBankRegister::addWorkoutRunning(const QString &name, const QString &date, int distance, int time)
{
    bool added = false;
    workoutRunning toAdd(name, date, distance, time);
    if (Find(toAdd) == -1)
    {
        if(nrOfWorkouts = capacity)
        {
            Expand();
        }
        workoutbanks[nrOfWorkouts++] = new workoutRunning(toAdd);
        added = true;
    }
    return added;
}

bool workoutBankRegister::allWorkoutWeightAsString(QString *stringArr, int capacityOfStringArr) const
{
    int index = 0;
    bool retValue = false;
    if(capacityOfStringArr >= getNrOfWorkoutsWeight())
    {
        retValue = true;
        for(int i=0; i<nrOfWorkouts; i++)
        {
            if(dynamic_cast<workoutWeight*>(workoutbanks[i] != nullptr))
            {
                    stringArr[index++] = workoutbanks[i]->toString();
            }
        }
    }
    return retValue;

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

}

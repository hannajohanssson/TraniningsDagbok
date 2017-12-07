#ifndef WORKOUTBANKREGISTER_H
#define WORKOUTBANKREGISTER_H

#include "workoutweight.h"
#include "workoutrunning.h"


class workoutBankRegister
{
private:
    workoutBank** workoutbanks;
    int capacity;
    int nrOfWorkouts;
    int Find(const workoutBank& workout) const;     //använda för att sortera/lägga till i meriter
    void Expand();

public:
    workoutBankRegister(int capacity = 10);
    ~workoutBankRegister();

    bool addWorkoutWeight(const QString& name, const QString& date, int weight, int reps);

    bool addWorkoutRunning(const QString& name, const QString& date, int distance, int time);

    QString getAllString() const;

    //lägga till funktioner här som sorterar efter namn och vikt tex




    int getNrOfWorkoutsWeight() const;      //behövs?
    int getNrOfWorkoutsRunning() const;


};

#endif // WORKOUTBANKREGISTER_H

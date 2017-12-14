#ifndef WORKOUTWEIGHT_H
#define WORKOUTWEIGHT_H

#include "workoutbank.h"

class workoutWeight: public workoutBank
{
private:
    int weight;     //kunna jämföra vikter och sortera efter högst vikt
    int reps;

    QString toStringSpecific() const;

public:
    workoutWeight(const QString& name, const QString& date, int weight, int reps);
    workoutWeight();
    ~workoutWeight();

    void setWeight(int weight);
    void setreps(int reps);

    int getWeight() const;
    int getReps() const;



    //jämföra vikter
    //bool operator==(int weight) const;

    //bool addWorkoutWeight(int weight, int reps);
 };


#endif // WORKOUTWEIGHT_H

#ifndef WORKOUTRUNNING_H
#define WORKOUTRUNNING_H

#include "workoutbank.h"

class workoutRunning: public workoutBank
{
private:
    int distance;
    int time; //eller double?

    QString toStringSpecific() const;

public:
    workoutRunning(const QString& name, const QString& date, int distance, int time);
    workoutRunning();
    ~workoutRunning();

    void setDistance(int distance);
    void setTime(int time);

    int getDistance() const;
    int getTime() const;

    //sortera efter distans och sen tid
};


#endif // WORKOUTRUNNING_H

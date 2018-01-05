#ifndef WORKOUTRUNNING_H
#define WORKOUTRUNNING_H

#include "workoutbank.h"

class workoutRunning: public workoutBank
{
private:
    int distance;
    int time;

    QString toStringSpecific() const;


public:
    workoutRunning(const QString& name, int date, int distance, int time);
    workoutRunning();
    ~workoutRunning();

    void setDistance(int distance);
    void setTime(int time);

    int getDistance() const;
    int getTime() const;

    QString toStringSpecificFile() const;
    QString ToStringSaveToFile() const;


};


#endif // WORKOUTRUNNING_H

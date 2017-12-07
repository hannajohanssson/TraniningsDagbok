#ifndef WORKOUTRUNNING_H
#define WORKOUTRUNNING_H


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

    void setDistance(int distance) const;
    void setTime(int time) const;

    int getDistance() const;
    int getTime() const;

    //sortera efter distans och sen tid
};


#endif // WORKOUTRUNNING_H

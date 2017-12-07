#ifndef WORKOUTBANK_H
#define WORKOUTBANK_H
#include <QString>


class workoutBank
{
private:
QString name;
QString date;

virtual QString toStringSpecific() const = 0;

public:
    workoutBank(const QString& name, const QString& date);
    workoutBank();
    virtual ~workoutBank();

    //jämföra namn
    bool operator==(const QString& name) const;

    QString getName() const;
    QString getDate() const;
    QString getNameDate() const;
    QString toString() const;       //endast i basklassen

//    void setName(const QString& name);
//    void setDate(const QString& date);     //behövs denna??
//    bool addPR(const QString& name, const QString& date);       //om den inte redan finns - lägg till helt ny?(
//    bool operator=(const workoutBank other) const;

    //Lägga till helt ny, name och date i alla, men om weight eller tid?
};


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
    bool operator==(int weight) const;

    //bool addWorkoutWeight(int weight, int reps);
 };

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


#endif // WORKOUTBANK_H

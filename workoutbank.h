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
    bool operator==(const workoutBank& other) const;

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






#endif // WORKOUTBANK_H

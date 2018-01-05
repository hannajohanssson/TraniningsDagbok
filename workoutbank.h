#ifndef WORKOUTBANK_H
#define WORKOUTBANK_H
#include <QString>


class workoutBank
{
private:
QString name;
int date;

virtual QString toStringSpecific() const = 0;


public:
    workoutBank(const QString& name, const int date);
    workoutBank();
    virtual ~workoutBank();

    //jämföra namn
    bool operator==(const workoutBank& other) const;

    QString getName() const;
    int getDate() const;
    QString getNameDate() const;
    QString toString() const;       //endast i basklassen

    virtual QString toStringSpecificFile() const =0;
};






#endif // WORKOUTBANK_H

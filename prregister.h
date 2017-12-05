#ifndef PRREGISTER_H
#define PRREGISTER_H

#include "pr.h"
#include <QString>


class prRegister
{
public:
    prRegister();

    ~prRegister();



    void addPR(const QString& name);


    std::string toString() const;
    void saveToFile(QString fileName);
    void readFromFile(QString fileName);

private:
    pr** prs; //dubbelpekare??
    int capacity;
    int count;

    void Expand();


};

#endif // PRREGISTER_H

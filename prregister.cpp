#include "prregister.h"

prRegister::prRegister()
{
    name = "";
}

prRegister::prRegister(const QString &name)
{
    this->name = name;
}

prRegister::~prRegister()
{

}

void prRegister::addPR(const QString &name)
{

}

std::string prRegister::toString() const
{

}

void prRegister::saveToFile(QString fileName)
{

}

void prRegister::readFromFile(QString fileName)
{

}

void prRegister::Expand()
{
//    capacity = capacity * 2;
//    Workouts** temp = new Workouts*[capacity];
//    for (int i =0; i<count; i++)
//    {
//        temp[i] = workouts[i];
//    }
//    delete[] workouts;
//    workouts = temp;

    capacity = capacity *2;
    pr** temp = new pr*[capacity];
    for (int i=0; i<count; i++)
    {
        temp[i] = pr[i];
    }
    delete[] pr;
    pr = temp;

}

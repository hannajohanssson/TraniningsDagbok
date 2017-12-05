#include "prregister.h"

prRegister::prRegister()
{
    count = 0;
    capacity = 20;
    prs = new pr*[capacity];       //pekare om dubbelpekare
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
    capacity = capacity *2;
    pr** temp = new pr*[capacity];
    for (int i=0; i<count; i++)
    {
        temp[i] = pr[i];
    }
    delete[] pr;
    pr = temp;

}

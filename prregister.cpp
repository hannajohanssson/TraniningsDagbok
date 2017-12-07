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
//    if (count == capacity)
//            {
//                Expand();
//            }
//    workouts[count++] = new Workouts(date, workout);

}

std::string prRegister::toString() const
{
//    QString retString = "";
//    for(int i=0; i<count; i++)
//    {
//        retString = workouts[i]->toString();
//    }
//    return retString;

}

void prRegister::saveToFile(QString fileName)
{

}

void prRegister::readFromFile(QString fileName)
{

}

int prRegister::findPr(const pr &f) const
{
//    int index = -1;
//    for (int i=0; i<count; i++)
//    {
//        if(f == *prs[i])
//        {
//            index = i;
//            i=count;
//        }
//    }
//    return index;
}

void prRegister::Expand()
{
//    capacity = capacity *2;
//    pr** temp = new pr*[capacity];
//    for (int i=0; i<count; i++)
//    {
//        temp[i] = pr[i];
//    }
//    delete[] pr;
//    pr = temp;
}

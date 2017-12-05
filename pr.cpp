#include "pr.h"

pr::pr()
{
    name = "";
}

pr::pr(const QString &name)
{
    this->name = name;
}

QString pr::getName() const
{
    return name;
}

void pr::setName(const QString &name)
{
    this->name = name;
}

QString pr::toString() const
{
    QString retString;
    retString += "PR: " + name + "\n";

    return retString;
}

bool pr::operator ==(const pr &other) const
{
    return this->name==other.name;
}

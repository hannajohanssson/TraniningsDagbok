#ifndef PR_H
#define PR_H
#include <QString>


class pr
{
public:
    pr();
    pr(const QString& name);
    ~pr();

    QString getName() const;
    void setName(const QString& name);
    QString toString() const;
    bool operator == (const pr& other) const;



private:
    QString name;

};

#endif // PR_H

#ifndef COMPETITION_H
#define COMPETITION_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>

class Competition
{
private:
    int date;
    QString name;
    int nrOfEvents;
    QString competitionInfo;
    int finalPlace;

public:
    Competition(int date, QString& name, int nrOfEvents, QString& competitionInfo, int finalPlace);
    Competition();
    ~Competition();

    int getDate() const;
    QString getName() const;
    int getNrOfEvents() const;
    QString getCompetitionInfo() const;
    int getFinalPlace() const;

    void setDate(const int date);
    void setName(const QString& name);
    void setNrOfEvents(const int nrOfEvents);
    void setCompetitionInfo(const QString& competitionInfo);
    void setFinalPlace(const int finalPlace);

    bool operator<(const Competition& other) const;

    QString toString() const;
    QString ToStringSaveToFile() const;
    QString toStringBestComp() const;

};

#endif // COMPETITION_H

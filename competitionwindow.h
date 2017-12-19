#ifndef COMPETITIONWINDOW_H
#define COMPETITIONWINDOW_H

#include <QDialog>
#include "competitionregister.h"


namespace Ui {
class CompetitionWindow;
}

class CompetitionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CompetitionWindow(QWidget *parent = 0);
    ~CompetitionWindow();

//explicit CompetitionWindow(CompetitionRegister* competitions, QWidget *parent = 0);

private slots:
    void on_pushButtonAddCompetition_clicked();

    void on_pushButtonShow_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonGoBack_clicked();

private:
    Ui::CompetitionWindow *ui;
    //CompetitionRegister* competitions;


};

#endif // COMPETITIONWINDOW_H

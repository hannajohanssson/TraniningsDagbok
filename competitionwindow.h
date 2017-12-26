#ifndef COMPETITIONWINDOW_H
#define COMPETITIONWINDOW_H


#include "competitionregister.h"
#include <QDialog>


namespace Ui {
class CompetitionWindow;
}

class CompetitionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CompetitionWindow(CompetitionRegister* competitions, QWidget *parent = 0);
    ~CompetitionWindow();

private slots:
    void on_pushButtonAddCompetition_clicked();

    void on_pushButtonShow_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonGoBack_clicked();

    void on_RemoveComp_clicked();

    void on_pushButton_clicked();

    void on_pushButtonRemove_clicked();

private:
    Ui::CompetitionWindow *ui;
    CompetitionRegister* competitions;


};

#endif // COMPETITIONWINDOW_H

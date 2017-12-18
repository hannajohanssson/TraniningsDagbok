#ifndef COPMETITIONSWINDOW_H
#define COPMETITIONSWINDOW_H

#include <QDialog>
#include "competition.h"
#include "competitionregister.h"

namespace Ui {
class Copmetitionswindow;
}

class Copmetitionswindow : public QDialog
{
    Q_OBJECT

public:
    explicit Copmetitionswindow(CompetitionRegister* competitions, QWidget *parent = 0);
    ~Copmetitionswindow();

private slots:
    void on_pushButtonAddCompetitions_clicked();

    void on_pushButtonShowCompetitions_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonGoBack_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::Copmetitionswindow *ui;
    CompetitionRegister* competitions;


};

#endif // COPMETITIONSWINDOW_H

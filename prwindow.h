#ifndef PRWINDOW_H
#define PRWINDOW_H

#include <QDialog>
#include "workoutbankregister.h"
#include <QObject>

namespace Ui {
class PRwindow;
}

class PRwindow : public QDialog
{
    Q_OBJECT

public:
    explicit PRwindow(workoutBankRegister* workoutbanks, QWidget *parent = 0);
    ~PRwindow();

private slots:
    void on_ButtonAddPR_clicked();

    void on_ButtonShowPR_clicked();

    void on_ButtonAddPRweight_clicked();

    void on_ButtonAddPRrunning_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_RemovePR_clicked();

private:
    Ui::PRwindow *ui;
    workoutBankRegister* workoutbanks;
};

#endif // PRWINDOW_H

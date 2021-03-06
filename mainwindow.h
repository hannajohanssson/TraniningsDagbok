#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "workouts.h"
#include "workoutwindow.h"
#include "workoutregister.h"
#include "workoutbankregister.h"
#include "prwindow.h"
#include "competition.h"
#include "competitionregister.h"
#include "competitionwindow.h"

#include <QMainWindow>

#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButtonPR_clicked();
    void on_pushButtonCompetitions_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::MainWindow *ui;
    WorkoutRegister workouts;
    workoutWindow *mWorkoutWindow;

    workoutBankRegister  workoutbanks;
    PRwindow *mPRwindow;

    CompetitionRegister competitions;
    CompetitionWindow *mCompetitionWindow;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workouts.h"  //behövs det?
#include "workoutwindow.h"
#include "workoutregister.h"
#include "workoutbankregister.h"
#include "prwindow.h"
#include "competition.h"
#include "competitionregister.h"
#include "copmetitionswindow.h"

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

    //void on_pushButtonPR_2_clicked();

    void on_pushButtonCompetition_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    WorkoutRegister workouts;
    workoutWindow *mWorkoutWindow;

    workoutBankRegister workoutbanks;
    PRwindow *mPRwindow;

    CompetitionRegister competitions;
    Copmetitionswindow *mCompetitionWindow;







};

#endif // MAINWINDOW_H

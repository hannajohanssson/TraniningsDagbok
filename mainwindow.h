#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workouts.h"  //behövs det?
#include "workoutwindow.h"

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



private:
    Ui::MainWindow *ui;
    Workouts workouts;
    workoutWindow *mWorkoutWindow;
    //friend class workoutWindow;

    //från test //pekare
    //workoutWindow *mWorkoutWindow;


};

#endif // MAINWINDOW_H

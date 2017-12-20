#ifndef WORKOUTWINDOW_H
#define WORKOUTWINDOW_H

#include <QDialog>
#include "workouts.h"
#include "workoutregister.h"
#include <QObject>

namespace Ui {
class workoutWindow;
}

class workoutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit workoutWindow(WorkoutRegister* workouts, QWidget *parent = 0);
    ~workoutWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_goBack_clicked();

private:
    Ui::workoutWindow *ui;
    WorkoutRegister* workouts;
};

#endif // WORKOUTWINDOW_H

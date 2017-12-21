#include "workoutwindow.h"
#include "ui_workoutwindow.h"
#include "workouts.h"
#include "workoutregister.h"
#include <QMessageBox>



workoutWindow::workoutWindow(WorkoutRegister* workouts,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workoutWindow)
{
    ui->setupUi(this);
    this-> workouts = workouts;

    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowWorkouts->hide();
    ui->labelShowAllWorkouts->hide();

}

workoutWindow::~workoutWindow()
{
    delete ui;
}
//show workouts
void workoutWindow::on_pushButton_4_clicked()
{
    WorkoutRegister w1;
    w1.addWorkout(171205, "Running 10km");

    ui->labelShowAllWorkouts->show();

    ui->listWidgetShowWorkouts->show();
    ui->listWidgetShowWorkouts->addItem(w1.toString());     //ej skriva ut igen??
    ui->listWidgetShowWorkouts->addItem(workouts->toString());




    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();


}

//add workout
void workoutWindow::on_pushButton_2_clicked()
{

    ui->listWidgetShowWorkouts->hide();
    //visa datum mm
    ui->label_date->show();
    ui->label_workout->show();
    ui->lineEdit_date->show();
    ui->textEdit_WorkoutDescription->show();
    ui->pushButton_save->show();
    ui->labelShowAllWorkouts->hide();

}

void workoutWindow::on_pushButton_save_clicked()
{

    QString date = ui->lineEdit_date->text();
    QString workoutText = ui->textEdit_WorkoutDescription->toPlainText();
    ui->lineEdit_date->clear();
    ui->textEdit_WorkoutDescription->clear();



    QMessageBox::information(this, "Add workout", "The workout has been added.");
    workouts->addWorkout(date.toInt(), workoutText);

    //test
    ui->listWidget->addItem(workouts->toString());
}

void workoutWindow::on_pushButton_goBack_clicked()
{
    this->close();
    parentWidget()->show();
}

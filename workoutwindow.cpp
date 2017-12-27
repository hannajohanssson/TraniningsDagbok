#include "workoutwindow.h"
#include "ui_workoutwindow.h"
#include "workouts.h"
#include "workoutregister.h"
#include <QMessageBox>
#include <iostream>



workoutWindow::workoutWindow(WorkoutRegister* workouts,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workoutWindow)
{
    ui->setupUi(this);
    this-> workouts = workouts;



    //skriva ut antal workoouts hittills, .getNrOfWorkouts()
    QString nrOfWorkouts = "Amount of workouts this far: " + QString::number(workouts->getNrOfWorkouts());
    ui->labelNrOfWorkouts->setText(nrOfWorkouts);

    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowWorkouts->hide();
    ui->labelShowAllWorkouts->hide();
    ui->labelRemove->hide();
    ui->lineEditRemove->hide();
    ui->pushButtonRemoveSave->hide();
    ui->listWidgetRemoveShow->hide();


}

workoutWindow::~workoutWindow()
{
    delete ui;
}
//show workouts
void workoutWindow::on_pushButton_4_clicked()
{
    ui->listWidgetShowWorkouts->clear();
    ui->labelNrOfWorkouts->hide();
    ui->labelShowAllWorkouts->clear();
//    WorkoutRegister w1;
//    w1.addWorkout(171205, "Running 10km");

    ui->labelShowAllWorkouts->show();

    ui->listWidgetShowWorkouts->show();
    //ui->listWidgetShowWorkouts->addItem(w1.toString());     //ej skriva ut igen??
    ui->listWidgetShowWorkouts->addItem(workouts->toString());







    ui->listWidgetRemoveShow->hide();
    ui->pushButtonRemoveSave->hide();
    ui->labelRemove->hide();
    ui->lineEditRemove->hide();
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();


}

//add workout
void workoutWindow::on_pushButton_2_clicked()
{
    ui->labelNrOfWorkouts->show();
    QString nrOfWorkouts = "Amount of workouts this far: " + QString::number(workouts->getNrOfWorkouts());
    ui->labelNrOfWorkouts->setText(nrOfWorkouts);
    ui->pushButtonRemoveSave->hide();
    ui->labelRemove->hide();
    ui->lineEditRemove->hide();
    ui->listWidgetShowWorkouts->hide();
    //visa datum mm
    ui->label_date->show();
    ui->label_workout->show();
    ui->lineEdit_date->show();
    ui->textEdit_WorkoutDescription->show();
    ui->pushButton_save->show();
    ui->labelShowAllWorkouts->hide();
    ui->listWidgetRemoveShow->hide();

}

void workoutWindow::on_pushButton_save_clicked()
{

    QString date = ui->lineEdit_date->text();
    QString workoutText = ui->textEdit_WorkoutDescription->toPlainText();
    ui->lineEdit_date->clear();
    ui->textEdit_WorkoutDescription->clear();



    QMessageBox::information(this, "Add workout", "The workout has been added.");
    workouts->addWorkout(date.toInt(), workoutText);

    QString nrOfWorkouts = "Amount of workouts this far: " + QString::number(workouts->getNrOfWorkouts());
    ui->labelNrOfWorkouts->setText(nrOfWorkouts);
}

void workoutWindow::on_pushButton_goBack_clicked()
{
    this->close();
    parentWidget()->show();
}

void workoutWindow::on_pushButtonRemove_clicked()
{
    ui->pushButtonRemoveSave->show();
    ui->labelRemove->show();
    ui->lineEditRemove->show();
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowWorkouts->hide();
    ui->listWidgetRemoveShow->show();
    ui->listWidgetRemoveShow->addItem(workouts->toString());



}

void workoutWindow::on_pushButtonRemoveSave_clicked()
{
    QString date = ui->lineEditRemove->text();
    ui->lineEditRemove->clear();

    QMessageBox::information(this, "Remove workout", "The workout has been removed.");
    workouts->removeWorkout(date.toInt());

    ui->listWidgetRemoveShow->clear();
    ui->listWidgetRemoveShow->addItem(workouts->toString());



}

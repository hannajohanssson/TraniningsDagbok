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
    ui->listWidgetShowFound->hide();
    ui->lineEditFind->hide();
    ui->labelFind->hide();
    ui->pushButtonFindSave->hide();
    ui->labelRemove_2->hide();
    ui->labelFind_2->hide();

}

workoutWindow::~workoutWindow()
{
    delete ui;
}
//show workouts
void workoutWindow::on_pushButton_4_clicked()
{
    ui->labelShowAllWorkouts->show();
    ui->listWidgetShowWorkouts->clear();
    ui->labelNrOfWorkouts->hide();
    ui->listWidgetShowWorkouts->clear();

    ui->listWidgetShowWorkouts->show();

    //ui->listWidgetShowWorkouts->addItem(workouts->toString());
    for(int i = 0; i < workouts->getNrOfWorkouts(); i++)
        ui->listWidgetShowWorkouts->addItem(workouts->getWorkout(i)->toString());


    ui->listWidgetRemoveShow->hide();
    ui->pushButtonRemoveSave->hide();
    ui->labelRemove->hide();
    ui->lineEditRemove->hide();
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowFound->hide();
    ui->lineEditFind->hide();
    ui->labelFind->hide();
    ui->pushButtonFindSave->hide();
    ui->labelRemove_2->hide();
    ui->labelFind_2->hide();
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
    ui->listWidgetShowFound->hide();
    ui->lineEditFind->hide();
    ui->labelFind->hide();
    ui->pushButtonFindSave->hide();
    ui->labelRemove_2->hide();
    ui->labelFind_2->hide();
}

void workoutWindow::on_pushButton_save_clicked()
{
    if(ui->lineEdit_date->text().length() == 0 || ui->textEdit_WorkoutDescription->toPlainText().length() == 0)
    {
        QMessageBox::information(this, "Add workout", "No workout has been added. Try again.");
    }
    else
    {


        QString date = ui->lineEdit_date->text();
        QString workoutText = ui->textEdit_WorkoutDescription->toPlainText();
        ui->lineEdit_date->clear();
        ui->textEdit_WorkoutDescription->clear();

        QMessageBox::information(this, "Add workout", "The workout has been added.");
        workouts->addWorkout(date.toInt(), workoutText);
    }


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
    ui->listWidgetRemoveShow->show();
    ui->listWidgetRemoveShow->clear();
    ui->labelShowAllWorkouts->hide();

    for(int i = 0; i < workouts->getNrOfWorkouts(); i++)
        ui->listWidgetRemoveShow->addItem(workouts->getWorkout(i)->toString());


    ui->pushButtonRemoveSave->show();
    ui->labelRemove->show();
    ui->lineEditRemove->show();
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowWorkouts->hide();
    ui->listWidgetShowFound->hide();
    ui->lineEditFind->hide();
    ui->labelFind->hide();
    ui->pushButtonFindSave->hide();
    ui->labelNrOfWorkouts->hide();
    ui->labelRemove_2->show();
    ui->labelFind_2->hide();
}

void workoutWindow::on_pushButtonRemoveSave_clicked()
{
    if (ui->lineEditRemove->text().length() == 0)
    {
        QMessageBox::information(this, "Remove workout", "No workout has been removed. Try again.");
    }
    else
    {
        QString date = ui->lineEditRemove->text();
        ui->lineEditRemove->clear();

        if(workouts->removeWorkout(date.toInt()))
        {
          QMessageBox::information(this, "Remove workout", "The workout has been removed.");
        }
        else
            QMessageBox::information(this, "Remove workout", "The workout has not been removed.");

        ui->listWidgetRemoveShow->clear();
    }


    for(int i = 0; i < workouts->getNrOfWorkouts(); i++)
        ui->listWidgetRemoveShow->addItem(workouts->getWorkout(i)->toString());
}

void workoutWindow::on_pushButton_clicked()
{
    ui->labelShowAllWorkouts->hide();
    ui->labelRemove->hide();
    ui->lineEditRemove->hide();
    ui->pushButtonRemoveSave->hide();
    ui->listWidgetRemoveShow->hide();
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowWorkouts->hide();
    ui->listWidgetShowFound->hide();
    ui->lineEditFind->show();
    ui->labelFind->show();
    ui->pushButtonFindSave->show();
    ui->labelNrOfWorkouts->hide();
    ui->labelRemove_2->hide();
    ui->labelFind_2->show();
}

void workoutWindow::on_pushButtonFindSave_clicked()
{
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->textEdit_WorkoutDescription->hide();
    ui->pushButton_save->hide();
    ui->listWidgetShowWorkouts->hide();
    ui->listWidgetShowFound->clear();
    ui->listWidgetShowFound->show();
    if (ui->lineEditFind->text().length() == 0)
    {
        QMessageBox::information(this, "Find workout", "Try again.");
    }
    else
    {
        QString date = ui->lineEditFind->text();
        ui->lineEditFind->clear();

        QString foundWorkout = workouts->getSpecWorkoutString(date.toInt());

        ui->listWidgetShowFound->addItem(foundWorkout);
    }

}

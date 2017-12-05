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

    //ui->pushButton->hide();
    //ui->pushButton_2->hide();
    //ui->pushButton_4->hide();
    ui->label_date->hide();
    ui->label_workout->hide();
    ui->lineEdit_date->hide();
    ui->lineEdit_workout->hide();
    ui->pushButton_save->hide();

}

workoutWindow::~workoutWindow()
{
    delete ui;
}



//show workouts
void workoutWindow::on_pushButton_4_clicked()
{
    //läsa från fil


}

//add workout
void workoutWindow::on_pushButton_2_clicked()
{
    //visa datum mm
    ui->label_date->show();
    ui->label_workout->show();
    ui->lineEdit_date->show();
    ui->lineEdit_workout->show();
    ui->pushButton_save->show();

}

void workoutWindow::on_pushButton_save_clicked()
{

    QString date = ui->lineEdit_date->text();       //göra till en int?
    QString workoutText = ui->lineEdit_workout->text();

    QMessageBox::information(this, "Add workout", "The workout has been added.");

    workouts->addWorkout(date.toInt(), workoutText);

}

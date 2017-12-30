#include "prwindow.h"
#include "ui_prwindow.h"
#include "workoutbankregister.h"

#include <QMessageBox>

PRwindow::PRwindow(workoutBankRegister* workoutbanks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PRwindow)
{
    ui->setupUi(this);
    this->workoutbanks = workoutbanks;


    //läsa från fil
    // WorkoutBanksFile

    ui->ButtonAddPRrunning->hide();
    ui->ButtonAddPRweight->hide();
    ui->labelNama->hide();
    ui->label_2Date->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->lineEditTime->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->lineEdit_5Date->hide();
    ui->lineEdit_6Name->hide();
    ui->lineEdit_7Distance->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->listWidget->hide();
    ui->labelPRs->hide();
    ui->pushButtonRemoveLatest->hide();
}

PRwindow::~PRwindow()
{
    delete ui;
}

void PRwindow::on_ButtonAddPR_clicked()
{
    ui->ButtonAddPRrunning->show();
    ui->ButtonAddPRweight->show();
    ui->listWidget->hide();
    ui->labelNama->hide();
    ui->label_2Date->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->lineEditTime->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->lineEdit_5Date->hide();
    ui->lineEdit_6Name->hide();
    ui->lineEdit_7Distance->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->listWidget->hide();
    ui->labelPRs->hide();
    ui->pushButtonRemoveLatest->hide();
}

void PRwindow::on_ButtonShowPR_clicked()
{
    ui->labelPRs->show();
    ui->listWidget->clear();
    ui->listWidget->show();

    for(int i = 0; i < workoutbanks->getNrOfWorkoutsPR(); i++)
        ui->listWidget->addItem(workoutbanks->getPR(i)->toString());


    ui->pushButtonRemoveLatest->hide();
    ui->labelNama->hide();
    ui->label_2Date->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->lineEditTime->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->lineEdit_5Date->hide();
    ui->lineEdit_6Name->hide();
    ui->lineEdit_7Distance->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();

}

void PRwindow::on_ButtonAddPRweight_clicked()
{
    ui->labelPRs->hide();
    ui->listWidget->hide();
    ui->lineEditTime->hide();
    ui->lineEdit_7Distance->hide();
    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->labelNama->show();
    ui->label_2Date->show();
    ui->label_3Weight->show();
    ui->label_4Reps->show();
    ui->lineEdit_2Reps->show();
    ui->lineEdit_4Weight->show();
    ui->lineEdit_5Date->show();
    ui->lineEdit_6Name->show();
    ui->pushButton->show();
    ui->pushButton_2->hide();   //save running
    ui->pushButtonRemoveLatest->hide();
}

void PRwindow::on_ButtonAddPRrunning_clicked()
{
    ui->labelPRs->hide();
    ui->listWidget->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->labelNama->show();
    ui->label_2Date->show();
    ui->label_5Distance->show();
    ui->label_6Time->show();
    ui->lineEditTime->show();
    ui->lineEdit_5Date->show();
    ui->lineEdit_6Name->show();
    ui->lineEdit_7Distance->show();
    ui->pushButton_2->show();
    ui->pushButton->hide();
    ui->pushButtonRemoveLatest->hide();
}

//save workout weight
void PRwindow::on_pushButton_clicked()
{
    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->lineEditTime->hide();
    ui->lineEdit_7Distance->hide();
    ui->pushButton_2->hide();
    if(ui->lineEdit_4Weight->text().length() == 0 || ui->lineEdit_2Reps->text().length() == 0 || ui->lineEdit_6Name == 0 || ui->lineEdit_5Date->text().length() == 0)
        QMessageBox::information(this, "Add PR", "No PR has been added, try again.");
    else
    {
        QString name = ui->lineEdit_6Name->text();
        ui->lineEdit_6Name->clear();
        QString date = ui->lineEdit_5Date->text();
        ui->lineEdit_5Date->clear();
        QString weight = ui->lineEdit_4Weight->text();
        ui->lineEdit_4Weight->clear();
        QString reps = ui->lineEdit_2Reps->text();
        ui->lineEdit_2Reps->clear();

        if(ui->lineEdit_5Date->text().length() == 6)
            QMessageBox::information(this, "test == 6", "ok");
        else
            QMessageBox::information(this, "test !=6", "ej ok", QString(ui->lineEdit_5Date->text()));
//        if(ui->lineEdit_5Date->text().length() != 6)
//        {
//            QMessageBox::information(this, "Add date", "The date must be YYMMDD. Try again");
//            QMessageBox::information(this, "test", QString(ui->lineEdit_5Date->text()));
//        }
//        else
//        {
//            QMessageBox::information(0, QString("Information"), QString("Added weight"), QMessageBox::Ok);

//            workoutbanks->addWorkoutWeight(name, date.toInt(), weight.toInt(), reps.toInt());
//        }

        QMessageBox::information(0, QString("Information"), QString("Added weight"), QMessageBox::Ok);

        workoutbanks->addWorkoutWeight(name, date.toInt(), weight.toInt(), reps.toInt());

    }

    int index = workoutbanks->getNrOfWorkoutsWeight();

    QString* arr = new QString[index];

    workoutbanks->allWorkoutWeightAsString(arr, index);

    for(int i=0; i<index; i++)
    {
        ui->listWidget->addItem(arr[i]);

    }
    delete[] arr;

    ui->pushButtonRemoveLatest->hide();
}

//save PR running
void PRwindow::on_pushButton_2_clicked()
{
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->pushButton->hide();

    if(ui->lineEdit_7Distance->text().length() == 0 || ui->lineEditTime->text().length() == 0 || ui->lineEdit_6Name == 0 || ui->lineEdit_5Date->text().length() == 0)
        QMessageBox::information(this, "Add PR", "No PR has been added, try again.");
    else
    {
        QString name = ui->lineEdit_6Name->text();
        ui->lineEdit_6Name->clear();
        QString date = ui->lineEdit_5Date->text();
        ui->lineEdit_5Date->clear();
        QString distance = ui->lineEdit_7Distance->text();
        ui->lineEdit_7Distance->clear();
        QString time = ui->lineEditTime->text();
        ui->lineEditTime->clear();

        QMessageBox::information(0, QString("Information"), QString("Added running"), QMessageBox::Ok);

        workoutbanks->addWorkoutRunning(name, date.toInt(), distance.toInt(), time.toInt());
    }


    int index = workoutbanks->getNrOfWorkoutsRunning();

    QString* arr = new QString[index];

    workoutbanks->allWorkoutRunningAsString(arr, index);

    for(int i=0; i<index; i++)
    {
        ui->listWidget->addItem(arr[i]);
    }

    delete[] arr;



    ui->pushButtonRemoveLatest->hide();
}

//Go back
void PRwindow::on_pushButton_3_clicked()
{
    this->close();
    parentWidget()->show();
}

void PRwindow::on_pushButtonRemove_clicked()
{
    ui->pushButtonRemoveLatest->show();
    ui->ButtonAddPRrunning->hide();
    ui->ButtonAddPRweight->hide();
    ui->labelNama->hide();
    ui->label_2Date->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->lineEditTime->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->lineEdit_5Date->hide();
    ui->lineEdit_6Name->hide();
    ui->lineEdit_7Distance->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->listWidget->clear();
    ui->listWidget->show();
    ui->labelPRs->show();

    for(int i = 0; i < workoutbanks->getNrOfWorkoutsPR(); i++)
        ui->listWidget->addItem(workoutbanks->getPR(i)->toString());



}

void PRwindow::on_pushButtonRemoveLatest_clicked()
{
    if(workoutbanks->getNrOfWorkoutsPR() > 0)
    {
        workoutbanks->removeLatest();
        QMessageBox::information(this, "Remove latest PR", "The latest PR has been removed.");
        ui->listWidget->clear();

    }
    else
    {
        QMessageBox::information(this, "Remove latest PR", "The latest PR has not been removed. No PR has been added.");
    }

    for(int i = 0; i < workoutbanks->getNrOfWorkoutsPR(); i++)
        ui->listWidget->addItem(workoutbanks->getPR(i)->toString());


}

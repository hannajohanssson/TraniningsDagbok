#include "prwindow.h"
#include "ui_prwindow.h"
#include "workoutbankregister.h"

PRwindow::PRwindow(workoutBankRegister* workoutbanks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PRwindow)
{
    ui->setupUi(this);
    this->workoutbanks = workoutbanks;

    ui->ButtonAddPRrunning->hide();
    ui->ButtonAddPRweight->hide();
    ui->labelNama->hide();
    ui->label_2Date->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->label_5BesPR->hide();
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
    ui->textEdit_BestPR->hide();
    ui->textEdit_BestPR_2->hide();

}

PRwindow::~PRwindow()
{
    delete ui;
}

void PRwindow::on_ButtonAddPR_clicked()
{
    ui->ButtonAddPRrunning->show();

    ui->ButtonAddPRweight->show();

}

void PRwindow::on_ButtonShowPR_clicked()
{
    ui->label_5BesPR->show();
    ui->textEdit_BestPR->show();
    ui->textEdit_BestPR_2->show();  //visar alla



    //visa bästa lyftet

    //kan sortera här annars i workoutbankregister, göra en sorteringsfunktion


}

void PRwindow::on_ButtonAddPRweight_clicked()
{
    ui->labelNama->show();
    ui->label_2Date->show();
    ui->label_3Weight->show();
    ui->label_4Reps->show();
    ui->lineEdit_2Reps->show();
    ui->lineEdit_4Weight->show();
    ui->lineEdit_5Date->show();
    ui->lineEdit_6Name->show();

    ui->pushButton->show();

}

void PRwindow::on_ButtonAddPRrunning_clicked()
{
    ui->labelNama->show();
    ui->label_2Date->show();
    ui->label_5Distance->show();
    ui->label_6Time->show();

    ui->lineEditTime->show();

    ui->lineEdit_5Date->show();
    ui->lineEdit_6Name->show();
    ui->lineEdit_7Distance->show();

    ui->pushButton_2->show();


}

//save workout weight
void PRwindow::on_pushButton_clicked()
{
    ui->listWidget->show();
    QString name = ui->lineEdit_6Name->text();
    ui->lineEdit_6Name->clear();

    QString date = ui->lineEdit_5Date->text();
    ui->lineEdit_5Date->clear();

    QString weight = ui->lineEdit_4Weight->text();
    ui->lineEdit_4Weight->clear();

    QString reps = ui->lineEdit_2Reps->text();
    ui->lineEdit_2Reps->clear();



    workoutbanks->addWorkoutWeight(name, date, weight.toInt(), reps.toInt());

    int index = workoutbanks->getNrOfWorkoutsWeight();

    QString* arr = new QString[index];


    workoutbanks->allWorkoutWeightAsString(arr, index);

    for(int i=0; i<index; i++)
    {
        ui->listWidget->addItem(arr[i]);
    }

    delete[] arr;





    ui->labelNama->hide();
    ui->label_2Date->hide();
    ui->label_3Weight->hide();
    ui->label_4Reps->hide();
    ui->lineEdit_2Reps->hide();
    ui->lineEdit_4Weight->hide();
    ui->lineEdit_5Date->hide();
    ui->lineEdit_6Name->hide();
    ui->pushButton->hide();



}

//save PR running
void PRwindow::on_pushButton_2_clicked()
{
    ui->listWidget->show();
    QString name = ui->lineEdit_6Name->text();
    ui->lineEdit_6Name->clear();

    QString date = ui->lineEdit_5Date->text();
    ui->lineEdit_5Date->clear();

    QString distance = ui->lineEdit_7Distance->text();
    ui->lineEdit_7Distance->clear();

    QString time = ui->lineEditTime->text();
    ui->lineEditTime->clear();

    workoutbanks->addWorkoutRunning(name, date, distance.toInt(), time.toInt());


    int index = workoutbanks->getNrOfWorkoutsRunning();

    QString* arr = new QString[index];


    workoutbanks->allWorkoutWeightAsString(arr, index);

    for(int i=0; i<index; i++)
    {
        ui->listWidget->addItem(arr[i]);
    }

    delete[] arr;




    ui->labelNama->hide();
    ui->label_2Date->hide();

    ui->label_5Distance->hide();
    ui->label_6Time->hide();
    ui->lineEditTime->hide();

    ui->lineEdit_5Date->hide();
    ui->lineEdit_6Name->hide();
    ui->lineEdit_7Distance->hide();
    ui->pushButton_2->hide();


}

//Go back
void PRwindow::on_pushButton_3_clicked()
{
    this->close();
    parentWidget()->show();
}

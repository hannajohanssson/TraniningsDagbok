#include "copmetitionswindow.h"
#include "ui_copmetitionswindow.h"

Copmetitionswindow::Copmetitionswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Copmetitionswindow)
{
    ui->setupUi(this);

    ui->pushButtonAddCompetitions->hide();
    ui->pushButtonShowCompetitions->hide();
    ui->label_Date->hide();
    ui->label_Description->hide();
    ui->label_Name->hide();
    ui->label_NrOfEvents->hide();
    ui->label_Placement->hide();
    ui->lineEditDate->hide();
    ui->lineEditDescription->hide();
    ui->lineEditName->hide();
    ui->lineEditNrOfEvents->hide();
    ui->lineEditPlace->hide();

}

Copmetitionswindow::~Copmetitionswindow()
{
    delete ui;
}

void Copmetitionswindow::on_pushButtonAddCompetitions_clicked()
{
    ui->labelBestRanked->hide();
    ui->pushButtonShowCompetitions->hide();
    ui->pushButtonAddCompetitions->hide();
    ui->label_Date->show();
    ui->label_Description->show();
    ui->label_Name->show();
    ui->label_NrOfEvents->show();
    ui->label_Placement->show();
    ui->lineEditDate->show();
    ui->lineEditDescription->show();
    ui->lineEditName->show();
    ui->lineEditNrOfEvents->show();
    ui->lineEditPlace->show();



}

void Copmetitionswindow::on_pushButtonShowCompetitions_clicked()
{
    ui->labelBestRanked->hide();
    ui->pushButtonShowCompetitions->hide();
    ui->pushButtonAddCompetitions->hide();

}



void Copmetitionswindow::on_pushButtonGoBack_clicked()
{
    this->close();
    parentWidget()->show();
}

void Copmetitionswindow::on_pushButtonSave_clicked()
{

}

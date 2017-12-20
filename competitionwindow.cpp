#include "competitionwindow.h"
#include "ui_competitionwindow.h"
#include "competition.h"
#include "competitionregister.h"
#include <QMessageBox>

CompetitionWindow::CompetitionWindow(CompetitionRegister* competitions, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompetitionWindow)
{
    ui->setupUi(this);
    this->competitions = competitions;


    ui->Date->hide();
    ui->Description->hide();
    ui->FinalPlace->hide();
    ui->Name->hide();
    ui->NrOfEvents->hide();
    ui->lineEditDate->hide();
    ui->lineEditName->hide();
    ui->lineEditNrOfEvents->hide();
    ui->lineEditNrOfEvents->hide();
    ui->lineEditPlace->hide();
    ui->textEditDescription->hide();
    ui->pushButtonSave->hide();
    ui->listWidgetTest->hide();
}

CompetitionWindow::~CompetitionWindow()
{
    delete ui;
}

void CompetitionWindow::on_pushButtonAddCompetition_clicked()
{
    ui->Date->show();
    ui->Description->show();
    ui->FinalPlace->show();
    ui->Name->show();
    ui->NrOfEvents->show();
    ui->lineEditDate->show();
    ui->lineEditName->show();
    ui->lineEditNrOfEvents->show();
    ui->lineEditNrOfEvents->show();
    ui->lineEditPlace->show();
    ui->textEditDescription->show();
    ui->pushButtonSave->show();
    ui->listWidgetTest->show();

}

void CompetitionWindow::on_pushButtonShow_clicked()
{

}

void CompetitionWindow::on_pushButtonSave_clicked()
{

    ui->listWidgetTest->show();
    QString date = ui->lineEditDate->text();
    ui->lineEditDate->clear();

    QString name  = ui->lineEditName->text();
    ui->lineEditName->clear();

    QString nrOfEvents = ui->lineEditNrOfEvents->text();
    ui->lineEditNrOfEvents->clear();

//Kolla tutoril hur det sparas

//    QString description = ui->textEditDescription->text();
//    ui->textEditDescription->clear();

    QString description = ui->lineEditTestDescription->text();
    ui->lineEditTestDescription->clear();

    QString place = ui->lineEditPlace->text();
    ui->lineEditPlace->clear();



//    competitions->addCompetition(date.toInt(), name, nrOfEvents.toInt(), description, place.toInt());

//    ui->listWidgetTest->addItem(competitions->toString());




}

void CompetitionWindow::on_pushButtonGoBack_clicked()
{
    this->close();
    parentWidget()->show();
}

#include "competitionwindow.h"
#include "ui_competitionwindow.h"
#include "competition.h"
#include "competitionregister.h"
#include <QMessageBox>
#include <QDialog>
#include <QObject>



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
    ui->listWidgetShowCompetitions->hide();

}

CompetitionWindow::~CompetitionWindow()
{
    delete ui;
}

void CompetitionWindow::on_pushButtonAddCompetition_clicked()
{
    ui->listWidgetShowCompetitions->hide();
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



}

void CompetitionWindow::on_pushButtonShow_clicked()
{
    ui->listWidgetShowCompetitions->clear();
    QString description1 = "1: 60 cal AB, 50 synced wallbaalls, 40 dumbell snatches, 30 goblet suats."
                           "\n2:5 Deadlifts 115kg, 5 pullups, 5 T2B, 1 ropeclimb. Adding 5 each round."
                           "\n3:A/ 1RM powerclean + 3front squats"
                           "\n  B/ 4 rounds: 20 cal row, 20 burpee boxjump over, 5 high snatch, 3 OHS.\n";
    QString name1 = "Juleböj";
    CompetitionRegister c1;
    c1.addCompetition(171210, name1, 3, description1, 8);
    ui->listWidgetShowCompetitions->addItem(c1.toString());

    ui->listWidgetShowCompetitions->show();
    ui->listWidgetShowCompetitions->addItem(competitions->toString());


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



}

void CompetitionWindow::on_pushButtonSave_clicked()
{


    QString date = ui->lineEditDate->text();
    ui->lineEditDate->clear();

    QString name  = ui->lineEditName->text();
    ui->lineEditName->clear();

    QString nrOfEvents = ui->lineEditNrOfEvents->text();
    ui->lineEditNrOfEvents->clear();

//Kolla tutoril hur det sparas

//    QString description = ui->textEditDescription->text();
//    ui->textEditDescription->clear();

//    QString description = ui->lineEditTestDescription->text();
//    ui->lineEditTestDescription->clear();

    QString description = ui->textEditDescription->toPlainText();
    ui->textEditDescription->clear();

    QString place = ui->lineEditPlace->text();
    ui->lineEditPlace->clear();



    competitions->addCompetition(date.toInt(), name, nrOfEvents.toInt(), description, place.toInt());

    //ui->listWidgetTest->addItem(competitions->toString());






}

void CompetitionWindow::on_pushButtonGoBack_clicked()
{
    this->close();
    parentWidget()->show();
}

void CompetitionWindow::on_RemoveComp_clicked()
{
    competitions->removeLatest();
    ui->listWidgetShowCompetitions->hide();
    QMessageBox::information(this, "Remove latest competition", "The latest competition has been removed.");

}

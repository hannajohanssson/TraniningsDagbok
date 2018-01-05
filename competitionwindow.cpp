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
    ui->labelBestComp->hide();
    ui->RubrikAllComp->hide();
    ui->RubrikBestComp->hide();
}

CompetitionWindow::~CompetitionWindow()
{
    delete ui;
}

void CompetitionWindow::on_pushButtonAddCompetition_clicked()
{
    ui->RubrikAllComp->hide();
    ui->labelBestComp->hide();
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
    ui->RubrikAllComp->hide();
    ui->RubrikBestComp->hide();
}

void CompetitionWindow::on_pushButtonShow_clicked()
{
    ui->RubrikAllComp->show();
    ui->listWidgetShowCompetitions->clear();
    ui->listWidgetShowCompetitions->show();
    for(int i = 0; i < competitions->getNrOfWorkouts(); i++)
        ui->listWidgetShowCompetitions->addItem(competitions->getCompetition(i)->toString());

    //ui->listWidgetSorted->addItem(competitions->sortedByPlace());

    ui->labelBestComp->show();
    QString bestComp = competitions->bestPlacementString();
    ui->labelBestComp->setText(bestComp);

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
    ui->RubrikBestComp->show();
}

void CompetitionWindow::on_pushButtonSave_clicked()
{
    if(ui->lineEditDate->text().length() == 0 || ui->lineEditName->text().length() == 0 || ui->lineEditNrOfEvents->text().length() == 0 || ui->textEditDescription->toPlainText().length() == 0 || ui->lineEditPlace->text().length() == 0)
    {
        QMessageBox::information(this, "Add competition", "No competition has been added. Try again.");
    }
    else
    {
        QString date = ui->lineEditDate->text();
        ui->lineEditDate->clear();
        QString name  = ui->lineEditName->text();
        ui->lineEditName->clear();
        QString nrOfEvents = ui->lineEditNrOfEvents->text();
        ui->lineEditNrOfEvents->clear();
        QString description = ui->textEditDescription->toPlainText();
        ui->textEditDescription->clear();
        QString place = ui->lineEditPlace->text();
        ui->lineEditPlace->clear();

        QMessageBox::information(this, "Add competition", "The competition has been added.");
        competitions->addCompetition(date.toInt(), name, nrOfEvents.toInt(), place.toInt(), description);
    }
    ui->RubrikAllComp->hide();
    ui->RubrikBestComp->hide();
}

void CompetitionWindow::on_pushButtonGoBack_clicked()
{
    this->close();
    parentWidget()->show();
}

void CompetitionWindow::on_RemoveComp_clicked()
{
    ui->RubrikAllComp->hide();
    ui->listWidgetShowCompetitions->hide();
    ui->labelBestComp->hide();
    ui->RubrikBestComp->hide();
    if(competitions->getNrOfWorkouts() >0)
    {
        competitions->removeLatest();
        QMessageBox::information(this, "Remove latest competition", "The latest competition has been removed.");
    }
    else
    {
       QMessageBox::information(this, "Remove latest competition", "There are no competitions added.");
    }

}

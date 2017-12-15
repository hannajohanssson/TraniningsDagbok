#ifndef COPMETITIONSWINDOW_H
#define COPMETITIONSWINDOW_H

#include <QDialog>

namespace Ui {
class Copmetitionswindow;
}

class Copmetitionswindow : public QDialog
{
    Q_OBJECT

public:
    explicit Copmetitionswindow(QWidget *parent = 0);
    ~Copmetitionswindow();

private slots:
    void on_pushButtonAddCompetitions_clicked();

    void on_pushButtonShowCompetitions_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonGoBack_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::Copmetitionswindow *ui;
};

#endif // COPMETITIONSWINDOW_H

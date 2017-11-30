#ifndef WORKOUTWINDOW_H
#define WORKOUTWINDOW_H

#include <QDialog>

namespace Ui {
class workoutWindow;
}

class workoutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit workoutWindow(QWidget *parent = 0);
    ~workoutWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::workoutWindow *ui;
};

#endif // WORKOUTWINDOW_H

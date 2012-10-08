#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QErrorMessage>
#include "rpncalculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_button9_clicked();
    void on_button8_clicked();
    void on_button7_clicked();
    void on_button6_clicked();
    void on_button5_clicked();
    void on_button4_clicked();
    void on_button3_clicked();
    void on_button2_clicked();
    void on_button1_clicked();
    void on_button0_clicked();
    void on_buttonEnter_clicked();

    void on_buttonEquals_clicked();

    void on_buttonAdd_clicked();

    void on_buttonSubtract_clicked();

    void on_buttonMultiply_clicked();

    void on_buttonDivide_clicked();

    void on_inputLine_editingFinished();

private:
    Ui::MainWindow *ui;
    rpn_calculator *calc;
    QErrorMessage *error_dialog;

    void number_clicked(QPushButton* bp);
};

#endif // MAINWINDOW_H

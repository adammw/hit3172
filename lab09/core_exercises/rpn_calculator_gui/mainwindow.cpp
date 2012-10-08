#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calc = new rpn_calculator;
    error_dialog = new QErrorMessage;

    // Set up input validator
    QValidator *validator = new QIntValidator(this);
    ui->inputLine->setValidator(validator);

    // don't collapse buttons
    ui->splitter->setCollapsible(0, false);
}

MainWindow::~MainWindow()
{
    delete error_dialog;
    delete calc;
    delete ui;
}

void MainWindow::number_clicked(QPushButton* bp) {
    QString text = ui->inputLine->text();
    text.append(bp->text());
    ui->inputLine->setText(text);
}

void MainWindow::on_button9_clicked()
{
    number_clicked(ui->button9);
}

void MainWindow::on_button8_clicked()
{
    number_clicked(ui->button8);
}

void MainWindow::on_button7_clicked()
{
    number_clicked(ui->button7);
}

void MainWindow::on_button6_clicked()
{
    number_clicked(ui->button6);
}

void MainWindow::on_button5_clicked()
{
    number_clicked(ui->button5);
}

void MainWindow::on_button4_clicked()
{
    number_clicked(ui->button4);
}

void MainWindow::on_button3_clicked()
{
    number_clicked(ui->button3);
}

void MainWindow::on_button2_clicked()
{
    number_clicked(ui->button2);
}

void MainWindow::on_button1_clicked()
{
    number_clicked(ui->button1);
}

void MainWindow::on_button0_clicked()
{
    number_clicked(ui->button0);
}


void MainWindow::on_buttonEnter_clicked()
{
    QString text = ui->inputLine->text();
    if (text.trimmed().length() == 0) {
        error_dialog->showMessage("No value entered", "empty_value");
        return;
    }
    calc->push(text.toInt());
    ui->stackList->addItem(QString::number(calc->peek_answer()));
    ui->inputLine->clear();
}

void MainWindow::on_buttonEquals_clicked()
{
    if (ui->stackList->count() < 2) {
        error_dialog->showMessage("Cannot perform the operation, not enough values on the stack", "empty_stack");
        return;
    }
    ui->inputLine->setText(QString::number(calc->answer()));
    ui->stackList->clear();
}

void MainWindow::on_buttonAdd_clicked()
{
    if (ui->stackList->count() < 2) {
        error_dialog->showMessage("Cannot perform the operation, not enough values on the stack", "empty_stack");
        return;
    }
    calc->add();
    ui->stackList->addItem(ui->buttonAdd->text());
}

void MainWindow::on_buttonSubtract_clicked()
{
    if (ui->stackList->count() < 2) {
        error_dialog->showMessage("Cannot perform the operation, not enough values on the stack", "empty_stack");
        return;
    }
    calc->subtract();
    ui->stackList->addItem(ui->buttonSubtract->text());
}

void MainWindow::on_buttonMultiply_clicked()
{
    if (ui->stackList->count() < 2) {
        error_dialog->showMessage("Cannot perform the operation, not enough values on the stack", "empty_stack");
        return;
    }
    calc->multiply();
    ui->stackList->addItem(ui->buttonMultiply->text());
}

void MainWindow::on_buttonDivide_clicked()
{
    if (ui->stackList->count() < 2) {
        error_dialog->showMessage("Cannot perform the operation, not enough values on the stack", "empty_stack");
        return;
    }
    calc->divide();
    ui->stackList->addItem(ui->buttonDivide->text());
}

void MainWindow::on_inputLine_editingFinished()
{
    on_buttonEnter_clicked();
}

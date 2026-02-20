/* Tehtävä 1
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Asetetaan alkuarvo
    ui->lineEdit->setText(QString::number(counter));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_countButton_clicked()
{
    counter++;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::on_resetButton_clicked()
{
    counter = 0;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::on_pushButton_2_clicked()
{

}
*/



//Tehtävä 2


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    number1 = "";
    number2 = "";
    state = 1;
    operand = -1;

    // kytketään numeronäppäimet samaan handleriin
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// -----------------------------
// NUMEROT
// -----------------------------
void MainWindow::numberClickHandler()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QString digit = btn->text();

    if (state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else {
        number2 += digit;
        ui->num2->setText(number2);
    }

    qDebug() << "N1:" << number1 << " N2:" << number2;
}

// -----------------------------
// OPERAATTORIT
// -----------------------------
void MainWindow::on_add_clicked()
{
    operand = 0;
    state = 2;
}

void MainWindow::on_sub_clicked()
{
    operand = 1;
    state = 2;
}

void MainWindow::on_mul_clicked()
{
    operand = 2;
    state = 2;
}

void MainWindow::on_div_clicked()
{
    operand = 3;
    state = 2;
}

// -----------------------------
// CLEAR
// -----------------------------
void MainWindow::on_clear_clicked()
{
    number1 = "";
    number2 = "";
    state = 1;
    operand = -1;
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

// -----------------------------
// ENTER = laske
// -----------------------------
void MainWindow::on_enter_clicked()
{
    if (number1.isEmpty() || number2.isEmpty())
        return;

    float a = number1.toFloat();
    float b = number2.toFloat();
    float res = 0;

    if (operand == 0) res = a + b;
    else if (operand == 1) res = a - b;
    else if (operand == 2) res = a * b;
    else if (operand == 3) {
        if (b == 0) {
            ui->result->setText("ERR");
            return;
        }
        res = a / b;
    }

    ui->result->setText(QString::number(res));
}



/* Tehtävä 1
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_countButton_clicked();
    void on_resetButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int counter = 0;
};

#endif // MAINWINDOW_H
*/



//Tehtävä 2


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // numeronäppäimet
    void numberClickHandler();

    // operaattorit
    void on_add_clicked();
    void on_sub_clicked();
    void on_mul_clicked();
    void on_div_clicked();

    // Clear ja Enter
    void on_clear_clicked();
    void on_enter_clicked();

private:
    Ui::MainWindow *ui;

    // laskimen muuttujat
    QString number1;
    QString number2;
    int state;
    int operand;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout(); // kytketään QTimer::timeout() -signaaliin

private slots:
    // ajan valintanapit
    void on_btnTime1_clicked();  // 2 min (120 sec)
    void on_btnTime5_clicked();  // 5 min

    // pelin ohjaus
    void on_btnStart_clicked();
    void on_btnSwitchP1_clicked();
    void on_btnSwitchP2_clicked();
    void on_btnEnd_clicked();

private:
    Ui::MainWindow *ui;
    QTimer timer;

    // asetettava peliaika millisekunneissa
    int gameTimeMs = 0;

    // jäljellä oleva aika pelaajille millisekunneissa
    int player1TimeMs = 0;
    int player2TimeMs = 0;

    // 1 = P1 vuoro, 2 = P2 vuoro, 0 = ei käynnissä
    int activePlayer = 0;

    // apufunktiot
    void resetGameState(int minutes);
    void updateProgressBars();
    void setGameInfoText(const QString &text, short fontPointSize = 11);
    void setControlsEnabled(bool beforeStartPhase);
    void checkGameOver();
};

#endif // MAINWINDOW_H



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFont>
#include <QtGlobal>

static constexpr int TICK_MS = 100; // ajastimen tikkaus (0.1 s)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Ajastin
    timer.setInterval(TICK_MS);
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeout);

    // Alkutekstit ja tilat
    setControlsEnabled(true); // ennen starttia
    setGameInfoText("Valitse peliaika ja paina START GAME aloittaaksesi.", 12);

    // Progressbarien alkuasetukset
    ui->progressP1->setRange(0, 100);
    ui->progressP2->setRange(0, 100);
    ui->progressP1->setValue(0);
    ui->progressP2->setValue(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setControlsEnabled(bool beforeStartPhase) {
    // Ennen pelin starttia: aika- ja start-napit käytössä, switch/end poissa
    ui->btnTime1->setEnabled(beforeStartPhase);  // 2 min
    ui->btnTime5->setEnabled(beforeStartPhase);  // 5 min
    ui->btnStart->setEnabled(beforeStartPhase);

    // Pelin aikana: switch ja end käytössä
    ui->btnSwitchP1->setEnabled(!beforeStartPhase);
    ui->btnSwitchP2->setEnabled(!beforeStartPhase);
    ui->btnEnd->setEnabled(!beforeStartPhase);
}

void MainWindow::resetGameState(int minutes) {
    gameTimeMs    = minutes * 60 * 1000;
    player1TimeMs = gameTimeMs;
    player2TimeMs = gameTimeMs;
    activePlayer  = 0; // ei vielä kukaan, odottaa starttia
    timer.stop();
    updateProgressBars();
    setGameInfoText(QString("Peliaika valittu: %1 min. Paina START GAME.").arg(minutes), 12);
    setControlsEnabled(true);
}

void MainWindow::updateProgressBars() {
    if (gameTimeMs <= 0) {
        ui->progressP1->setValue(0);
        ui->progressP2->setValue(0);
        return;
    }
    int p1 = qBound(0, static_cast<int>((player1TimeMs * 100.0) / gameTimeMs), 100);
    int p2 = qBound(0, static_cast<int>((player2TimeMs * 100.0) / gameTimeMs), 100);
    ui->progressP1->setValue(p1);
    ui->progressP2->setValue(p2);

}

void MainWindow::setGameInfoText(const QString &text, short fontPointSize) {
    ui->lblInfo->setText(text);
    QFont f = ui->lblInfo->font();
    f.setPointSize(fontPointSize);
    ui->lblInfo->setFont(f);
}

void MainWindow::checkGameOver() {
    if (player1TimeMs <= 0 || player2TimeMs <= 0) {
        timer.stop();
        int loser = (player1TimeMs <= 0) ? 1 : 2;
        setGameInfoText(QString("Aika loppui! Pelaaja %1 häviää. Valitse uusi peliaika aloittaaksesi.")
                            .arg(loser), 12);
        activePlayer = 0;
        setControlsEnabled(true); // takaisin ennen-starttia moodiin
    }
}

void MainWindow::timeout() {
    if (activePlayer == 1) {
        player1TimeMs -= TICK_MS;
        if (player1TimeMs < 0) player1TimeMs = 0;
    } else if (activePlayer == 2) {
        player2TimeMs -= TICK_MS;
        if (player2TimeMs < 0) player2TimeMs = 0;
    }
    updateProgressBars();
    checkGameOver();
}

/* ==== Ajan valintanapit ==== */
// 120 sec = 2 min
void MainWindow::on_btnTime1_clicked() { resetGameState(2); }
void MainWindow::on_btnTime5_clicked() { resetGameState(5); }

/* ==== Peli käyntiin ==== */
void MainWindow::on_btnStart_clicked() {
    if (gameTimeMs <= 0) {
        setGameInfoText("Valitse ensin peliaika (2 tai 5 min).", 12);
        return;
    }
    // Pelin alussa vuoro alkaa pelaajasta 1
    activePlayer = 1;
    setControlsEnabled(false);
    setGameInfoText("Peli käynnissä. Pelaaja 1:n vuoro. Vaihda vuoroa SWITCH PLAYER 1/2 -napeilla.", 11);
    timer.start();
}

/* ==== Vuoron vaihto ==== */
void MainWindow::on_btnSwitchP1_clicked() {
    // Tätä painaa P1 siirtonsa jälkeen -> vuoro P2:lle
    if (activePlayer == 1) {
        activePlayer = 2;
        setGameInfoText("Pelaaja 2:n vuoro.", 11);
    }
}

void MainWindow::on_btnSwitchP2_clicked() {
    // Tätä painaa P2 siirtonsa jälkeen -> vuoro P1:lle
    if (activePlayer == 2) {
        activePlayer = 1;
        setGameInfoText("Pelaaja 1:n vuoro.", 11);
    }
}

/* ==== Pelin lopetus ==== */
void MainWindow::on_btnEnd_clicked() {
    timer.stop();
    activePlayer = 0;
    setControlsEnabled(true);
    setGameInfoText("Peli lopetettu. Valitse uusi peliaika ja paina START GAME.", 12);
}

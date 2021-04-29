#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <random>

#include "QDateTime"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUdpSocket>
#include <QTextCodec>
#include <QTimer>
#include <QScreen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_competitor1Button_clicked();
    void on_competitor2Button_clicked();
    void on_lockUnlockButton_clicked();
    void on_selectJudgeComboBox_currentIndexChanged(int judge);
    void processPendingDatagrams();
    void confirmConnection();

private:
    Ui::MainWindow *ui;
    int fontSize;

    QTimer *confirmTimer;
    QNetworkAccessManager *manager;
    void sendGetRequest(QString competitor, int score);

    QUdpSocket *socket = nullptr;

    QString selectedJudge;
    int comboBoxJudge = 0;
    int competitor1score = 0;
    int competitor2score = 0;
    QStringList UDPcommands = {"START", "END", "PAUSE", "CONTINUE", "BRAKE"};
    QString currentCommand = "";
    QString newCommand;
};

#endif // MAINWINDOW_H

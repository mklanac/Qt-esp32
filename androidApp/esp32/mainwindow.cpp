#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    this->setWindowTitle("Judge Device");
    manager = new QNetworkAccessManager(this);

    //send confirmation command to server every 4-5 seconds
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(4000, 5000);

    confirmTimer = new QTimer();
    confirmTimer->setInterval(uid(gen));
    connect(confirmTimer,&QTimer::timeout,this,&MainWindow::confirmConnection);
    confirmTimer->start();


    socket = new QUdpSocket(this);
            bool result =  socket->bind(QHostAddress::Any, 3333);
            qDebug() << result;
            if(result)
            {
                qDebug() << "PASS";
            }
            else
            {
                qDebug() << "FAIL";
            }
            //processPendingDatagrams();
            connect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()),Qt::QueuedConnection);

    QScreen *screen = QApplication::screens().at(0);
    int screenHeight = screen->availableSize().height();
    int screenWidth = screen->availableSize().width();

    if(0.3*screenWidth > 0.5*screenHeight)
        fontSize = static_cast<int>(qRound(0.5*screenHeight));
    else
        fontSize = static_cast<int>(qRound(0.3*screenWidth));

    QFont font = ui->competitor1Button->font();
    font.setPixelSize(fontSize);

    ui->competitor1Button->setFont(font);
    ui->competitor2Button->setFont(font);
    ui->competitor1Button->setEnabled(false);
    ui->competitor2Button->setEnabled(false);
    ui->fightStatusLabel->setText("Waiting");


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_competitor1Button_clicked()
{
    if(comboBoxJudge==0)
        return;

    competitor1score++;
    ui->competitor1Button->setText(QString::number(competitor1score));
    QString competitor = "C1";
    sendGetRequest(competitor, competitor1score);
}

void MainWindow::on_competitor2Button_clicked()
{
    if(comboBoxJudge==0)
        return;

    competitor2score++;
    ui->competitor2Button->setText(QString::number(competitor2score));
    QString competitor = "C2";
    sendGetRequest(competitor, competitor2score);
}


void MainWindow::on_selectJudgeComboBox_currentIndexChanged(int judge)
{
    comboBoxJudge = judge;
}


void MainWindow::on_lockUnlockButton_clicked()
{
    if(comboBoxJudge==0)
        return;

    if(!(ui->lockUnlockButton->isChecked())) {
        ui->lockUnlockButton->setIcon(QIcon(":/img/img/unlock.png"));

        selectedJudge = "J" + QString::number(comboBoxJudge);
        ui->selectJudgeComboBox->setEnabled(false);

    }else {
        ui->lockUnlockButton->setIcon(QIcon(":/img/img/lock.png"));

        ui->selectJudgeComboBox->setEnabled(true);
    }
}

void MainWindow::sendGetRequest(QString competitor, int score)
{
    QString path = "/?Command=True&"+ selectedJudge + "=" + competitor + "&Score=" +  QString::number(score) + "&";
    QUrl myurl;
    myurl.setScheme("http"); //https also applicable
    myurl.setHost("192.168.4.1");
    myurl.setPath(path);

    QNetworkRequest request;
    request.setUrl(myurl);

    manager->get(request);
}

void MainWindow::processPendingDatagrams()
 {
    qDebug() << "in :";
    QHostAddress sender;
    u_int16_t port;
    while (socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(),datagram.size(),&sender,&port);
        //qDebug() <<"Message From :: " << sender.toString();
        //qDebug() <<"Port From :: "<< port;
        //qDebug() <<"Message :: " << datagram;
        newCommand = QTextCodec::codecForMib(106)->toUnicode(datagram);

        qDebug() << newCommand;
        if (newCommand != currentCommand){
            int commandIndex = UDPcommands.indexOf(newCommand);
            switch(commandIndex){
                case 0: case 3: // START & CONTINUE
                  ui->fightStatusLabel->setText("In progress");
                  ui->competitor1Button->setEnabled(true);
                  ui->competitor2Button->setEnabled(true);
                  break;

                case 1: //END
                  competitor1score = 0;
                  competitor2score = 0;
                  ui->competitor1Button->setText("0");
                  ui->competitor1Button->setEnabled(false);
                  ui->competitor2Button->setText("0");
                  ui->competitor2Button->setEnabled(false);
                  ui->fightStatusLabel->setText("Ended");
                  break;

                case 2: //PAUSE
                  ui->fightStatusLabel->setText("Paused");
                  ui->competitor1Button->setEnabled(false);
                  ui->competitor2Button->setEnabled(false);
                  break;

                case 4: //BRAKE
                  ui->fightStatusLabel->setText("Brake");
                  ui->competitor1Button->setEnabled(false);
                  ui->competitor2Button->setEnabled(false);
                  break;

                default:
                  break;
            }
            currentCommand = newCommand;

        }
    }

}


void MainWindow::confirmConnection()
{
    QString path = "/?Command=True&"+ selectedJudge + "=ON&";
    QUrl myurl;
    myurl.setScheme("http"); //https also applicable
    myurl.setHost("192.168.4.1");
    myurl.setPath(path);

    QNetworkRequest request;
    request.setUrl(myurl);

    manager->get(request);
}

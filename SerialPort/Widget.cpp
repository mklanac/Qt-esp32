#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

	//server receives confirmation command from client every 2 seconds
	// if after 10 seconds it does not get the confirmation show the message
	confirmTimer = new QTimer();
	confirmTimer->setInterval(6000);
	connect(confirmTimer, &QTimer::timeout, this, &Widget::devicesConnected);
	confirmTimer->start();


	const int numOfPorts = QSerialPortInfo::availablePorts().length();

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        availablePorts.append(serialPortInfo.portName());
	}

	ui->portsComboBox->addItems(availablePorts);

}

Widget::~Widget()
{
    delete ui;
	arduino->close();
}

void Widget::on_startStopButton_clicked()
{
	competitor1points = 0;
	competitor2points = 0;
	if (arduino->isWritable()) {
		arduino->write("START");
	}
	else {
		qDebug() << "Couldn't write to serial!";
	}
}

void Widget::on_newFightButton_clicked()
{
	competitor1points = 0;
	competitor2points = 0;
	ui->competitor1points->setText("0");
	ui->competitor2points->setText("0");
    if(arduino->isWritable()){
        arduino->write("END");
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}


void Widget::on_portsComboBox_currentIndexChanged(QString port)
{
	arduino->close();
	arduino = new QSerialPort;
	arduino_port_name = port;
	arduino_is_available = true;

	if (arduino_is_available) {
		// open and configure the serialport
		arduino->setPortName(arduino_port_name);
		arduino->setDataTerminalReady(true);
		arduino->open(QSerialPort::ReadWrite);
		arduino->setBaudRate(QSerialPort::Baud115200);
		arduino->setDataBits(QSerialPort::Data8);
		arduino->setParity(QSerialPort::NoParity);
		arduino->setStopBits(QSerialPort::OneStop);
		arduino->setFlowControl(QSerialPort::NoFlowControl);
		connect(arduino, &QSerialPort::readyRead, this, &Widget::handleReadyRead);
	}
	else {
		// give error message if not available
		QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
	}
}

void Widget::devicesConnected()
{
	QString connectedJudges = "Connected judges:";
	if (judge1connected) connectedJudges.append(" J1,");
	if (judge2connected) connectedJudges.append(" J2,");
	if (judge3connected) connectedJudges.append(" J3,");

	if (connectedJudges.endsWith(",")) connectedJudges.chop(1);

	ui->connectedJudgesLabel->setText(connectedJudges);

	judge1connected = judge2connected = judge3connected = false;

}

void Widget::on_rescanPortsButton_clicked()
{
	availablePorts.clear();

	foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
		availablePorts.append(serialPortInfo.portName());
	}

	ui->portsComboBox->clear();
	ui->portsComboBox->addItems(availablePorts);
}

void Widget::handleReadyRead()
{
	m_readData.append(arduino->readAll());
	if (!m_readData.isEmpty()) {

		int index = m_readData.indexOf("\r\n");
		if (index == -1) return;

		QByteArray newCommand = m_readData.left(index);
		if (m_readData.length() == (index + 2)) m_readData.clear();
		else m_readData = m_readData.mid(index + 2);

		QString newCOMstring = QTextCodec::codecForMib(106)->toUnicode(newCommand);
		if (newCOMstring.length() < 5) return;
		
		int indexEqualsSign = newCOMstring.lastIndexOf("=");
		QString judgeStatus = newCOMstring.mid(indexEqualsSign + 1);

		if (judgeStatus == "ON") {
			int commandIndex = judgesList.indexOf(newCOMstring.mid(0,2));
			switch (commandIndex) {
				case 0:
					judge1connected = true;
					break;

				case 1:
					judge2connected = true;
					break;

				case 2:
					judge3connected = true;
					break;
				default:
					break;
			}
		}

		if (newCOMstring.length() < 13) return;
		indexEqualsSign = newCOMstring.lastIndexOf("=");
		QString score = newCOMstring.mid(indexEqualsSign+1);
		if (newCOMstring[4] == '1') {
			competitor1points = score.toInt();
			ui->competitor1points->setText(score);
		}
		else if (newCOMstring[4] == '2') {
			competitor2points = score.toInt();
			ui->competitor2points->setText(score);
		}
		
	}
}



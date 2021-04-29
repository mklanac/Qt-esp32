#ifndef WIDGET_H
#define WIDGET_H

#include <random>
#include "QDateTime"

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QByteArray>
#include <QTextStream>
#include <QTextCodec>


namespace Ui
{
class Widget;
}

class QSerialPort;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:

    void on_newFightButton_clicked();
	void on_startStopButton_clicked();
	void on_portsComboBox_currentIndexChanged(QString port);
	void on_rescanPortsButton_clicked();

	void devicesConnected();

private:
    Ui::Widget *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 4292;
    static const quint16 arduino_uno_product_id = 60000;
	void handleReadyRead();
    QString arduino_port_name;
    bool arduino_is_available;
	QByteArray m_readData;
	QStringList availablePorts;

	QTimer* confirmTimer;
	bool judge1connected = false;
	bool judge2connected = false;
	bool judge3connected = false;
	QStringList judgesList = { "J1", "J2", "J3"};

	int competitor1points = 0; 
	int competitor2points = 0;
};

#endif // WIDGET_H

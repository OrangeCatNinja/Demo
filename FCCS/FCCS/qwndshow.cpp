#include "qwndshow.h"
#include <QMessageBox>
#include <QTime>

const int g_nUpdate = 1000;

QWndShow::QWndShow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->hide();

	m_timer = new QTimer(this);
	m_timer->stop();
	m_timer->setInterval(g_nUpdate);
	connect(m_timer, &QTimer::timeout, this, &QWndShow::onTimeOut);
	m_timer->start();

	ui.lcdTemp->setDigitCount(3);
	ui.lcdTemp->setMode(QLCDNumber::Dec);
	ui.lcdTemp->display(25);
	ui.lcdInTemp->setDigitCount(4);
	ui.lcdTemp->setMode(QLCDNumber::Dec);
	ui.lcdOutTemp->setDigitCount(4);
	ui.lcdOutTemp->setMode(QLCDNumber::Dec);
	ui.lcdInTemp->display(10);
	ui.lcdOutTemp->display(20);
}

QWndShow::~QWndShow()
{
}

QStringList QWndShow::rowData(double power)
{
	QStringList lstData;
	if (power > 0)
	{
		QString strPower = QString("%1").arg(power);
		QString strFreq = QString("%1").arg(power * 10);
		QString strRunSpeed = QString("%1").arg(power / 3.14);
		QString strFlux = QString("%1").arg(power * 1024);
		QString strYangCh = QString("%1").arg(power);
		lstData << strPower << strFreq << strRunSpeed << strFlux << strYangCh;
	}
	return lstData;
}

bool QWndShow::setRowData(int index, QStringList data)
{
	if(index < 0 || index >= ui.tabData->rowCount() || data.size() != 5)
		return false;
	for (int i = 0; i < data.size(); i++)
	{
		QTableWidgetItem* item = ui.tabData->item(index, i);
		if (item == NULL)
			item = new QTableWidgetItem();
		item->setText(data.at(i));
		ui.tabData->setItem(index, i, item);
	}
	return true;
}

double QWndShow::randNum(int min, int strech)
{
	QTime time = QTime::currentTime();
	qsrand(time.msec() + time.second() * 1000);
	int nRand = qrand() % strech + min;
	return nRand;
}

void QWndShow::updateLcd()
{
	double inTemp = ui.lcdInTemp->value();
	double outTemp = ui.lcdOutTemp->value();
	if (inTemp < outTemp)
	{
		double dChange = randNum(0, 20) * 0.01;
		inTemp += dChange;
		outTemp -= dChange;
		ui.lcdInTemp->display(inTemp);
		ui.lcdOutTemp->display(outTemp);
	}
}

void QWndShow::onTimeOut()
{
	double nPower = 0;
	QString strInputPower = "";
	strInputPower = ui.ledPower->text();
	nPower = strInputPower.toDouble();

	if (nPower > 0)
	{
		nPower = randNum(90, 10) * 0.01;

		QStringList lstEDing = rowData(nPower);
		QStringList lstNo1 = rowData(nPower*0.9);
		QStringList lstNo2 = rowData(nPower*1.1);
		QStringList lstNo3 = rowData(nPower*1.5);
		QTableWidgetItem* item = ui.tabData->item(0, 0);
		bool ret = setRowData(0, lstEDing) && setRowData(1, lstNo1) && setRowData(2, lstNo2) && setRowData(3, lstNo3);
		if (!ret)
			QMessageBox::information(NULL, "update fail!", "update fail!");

		updateLcd();
	}
}
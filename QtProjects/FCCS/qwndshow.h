#pragma once

#include <QWidget>
#include "ui_qwndshow.h"
#include "QTimer"

class QWndShow : public QWidget
{
	Q_OBJECT

public:
	QWndShow(QWidget *parent = Q_NULLPTR);
	~QWndShow();

public slots:
	void onTimeOut();

private:
	QStringList rowData(double power);
	bool setRowData(int index, QStringList data);
	double randNum(int min,int strech);
	void updateLcd();
	

private:
	Ui::QWndShow ui;
	QTimer* m_timer;
};

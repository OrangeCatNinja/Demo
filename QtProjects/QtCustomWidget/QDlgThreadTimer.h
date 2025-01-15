#pragma once

#include <QWidget>
#include "ui_QDlgThreadTimer.h"
#include "QtThreadRun.h"
#include "QtObjectThread.h"

class QDlgThreadTimer : public QWidget
{
	Q_OBJECT

public:
	QDlgThreadTimer(QWidget *parent = nullptr);
	~QDlgThreadTimer();

public slots:
	void on_btnThreadStart_clicked();
	void on_btnThreadEnd_clicked();
	//void on_btnThreadOver_clicked();

	void on_btnObjectStart_clicked();
	void on_btnObjectEnd_clicked();

	void ChangeThreadLabel(int time);
	void ChangeObjectLabel(int time);

signals:
	void SigStartObjectThread(bool);

private:
	Ui::QDlgThreadTimerClass ui;

	QtThreadRun m_threadRun;
	QtObjectThread m_threadObject;

	QThread m_threadForObj;
};

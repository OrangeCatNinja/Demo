#include "stdafx.h"
#include "QDlgThreadTimer.h"

QDlgThreadTimer::QDlgThreadTimer(QWidget *parent)
	: QWidget(parent)
	, m_threadRun(this)
	, m_threadObject(nullptr)
	, m_threadForObj(nullptr)
{
	ui.setupUi(this);

	m_threadObject.moveToThread(&m_threadForObj);

	connect(&m_threadRun, &QtThreadRun::ThreadTimeOut, this, &QDlgThreadTimer::ChangeThreadLabel);
	connect(&m_threadRun, &QThread::finished, &m_threadRun, &QObject::deleteLater);
	connect(&m_threadForObj, &QThread::finished, &m_threadObject, &QObject::deleteLater);
	connect(&m_threadObject, &QtObjectThread::ThreadTimeOut, this, &QDlgThreadTimer::ChangeObjectLabel);

	m_threadForObj.start();

	hide();
}

QDlgThreadTimer::~QDlgThreadTimer()
{
}

void QDlgThreadTimer::on_btnThreadStart_clicked()
{
	m_threadRun.SetIsWorking(true);
	m_threadRun.start();
}

void QDlgThreadTimer::on_btnThreadEnd_clicked()
{
	m_threadRun.SetIsWorking(false);
}

void QDlgThreadTimer::on_btnObjectStart_clicked()
{
	m_threadObject.StartTime();
}

void QDlgThreadTimer::on_btnObjectEnd_clicked()
{
	m_threadObject.StopTime();
}

void QDlgThreadTimer::ChangeThreadLabel(int time)
{
	ui.labThreadTime->setText(QString::number(time));
}

void QDlgThreadTimer::ChangeObjectLabel(int time)
{
	ui.labObjectTime->setText(QString::number(time));
}

#include "stdafx.h"
#include "QtObjectThread.h"

QtObjectThread::QtObjectThread(QObject *parent)
	: QObject(parent)
	, m_nTime(0)
{
	connect(&m_timer, &QTimer::timeout, this, [&]() {
		++m_nTime;
		emit ThreadTimeOut(m_nTime);
	});
}

QtObjectThread::~QtObjectThread()
{}

void QtObjectThread::StartTime()
{
	m_timer.start(1000);
}

void QtObjectThread::StopTime()
{
	m_timer.stop();
}

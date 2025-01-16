#include "stdafx.h"
#include "QtThreadRun.h"

QtThreadRun::QtThreadRun(QObject *parent)
	: QThread(parent)
	, m_bIsWorking(false)
	, m_bIsOver(false)
	, m_nTime(0)
{
}

QtThreadRun::~QtThreadRun()
{}

void QtThreadRun::run()
{
	while (!m_bIsOver)
	{
		if(!m_bIsWorking)
			continue;

		++m_nTime;

		emit ThreadTimeOut(m_nTime);

		sleep(1);
	}
	this->exec();
}


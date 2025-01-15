#pragma once

#include <QThread>

class QtThreadRun  : public QThread
{
	Q_OBJECT

public:
	QtThreadRun(QObject *parent);
	~QtThreadRun();

	virtual void run() override;

	void SetIsWorking(bool work) { m_bIsWorking = work; }
	void SetIsOver(bool over) { m_bIsOver = over; }

signals:
	void ThreadTimeOut(int time);

private:
	bool m_bIsWorking;
	bool m_bIsOver;
	int m_nTime;
};

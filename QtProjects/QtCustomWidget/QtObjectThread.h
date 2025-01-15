#pragma once

#include <QObject>
#include <QTimer>

class QtObjectThread  : public QObject
{
	Q_OBJECT

public:
	QtObjectThread(QObject *parent);
	~QtObjectThread();

public slots:
	void StartTime();
	void StopTime();

signals:
	void ThreadTimeOut(int time);

private:
	QTimer m_timer;
	int m_nTime;
};

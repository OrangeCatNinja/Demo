#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "ui_qwndlogin.h"
#include <QCloseEvent>

class QWndLogin : public QDialog
{
	Q_OBJECT

public:
	QWndLogin(QWidget *parent = Q_NULLPTR);
	~QWndLogin();

protected:
	void closeEvent(QCloseEvent*event);

public slots:
	void on_btnEnter_clicked();
	void on_btnCancel_clicked();

private:
	Ui::QWndLogin ui;
	QString m_strWorkNum;
	QString m_strUserName;
	QString m_strPassWord;
};

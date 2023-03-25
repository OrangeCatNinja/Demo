#include "qwndlogin.h"
#include <QMessageBox>

const QString g_strWorkNo = "001";
const QString g_strUserName = "houyu";
const QString g_strPassWord = "001";

QWndLogin::QWndLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.ledWorknum->setText(g_strWorkNo);
	ui.ledUsername->setText(g_strUserName);
	ui.ledPassword->setText(g_strPassWord);
}

QWndLogin::~QWndLogin()
{
}

void QWndLogin::closeEvent(QCloseEvent * event)
{
	reject();
}

void QWndLogin::on_btnEnter_clicked()
{
	QString _strWorkNo = ui.ledWorknum->text();
	QString _strUserName = ui.ledUsername->text();
	QString _strPassWord = ui.ledPassword->text();
	if (_strWorkNo == g_strWorkNo && _strUserName == g_strUserName && _strPassWord == g_strPassWord)
	{
		QMessageBox::information(NULL, "µÇÂ¼³É¹¦", "µÇÂ¼³É¹¦");
		accept();
	}
	else
	{
		QMessageBox::information(NULL, "µÇÂ¼Ê§°Ü", "µÇÂ¼Ê§°Ü£¬ÇëÖØÊÔ");
	}
}

void QWndLogin::on_btnCancel_clicked()
{
	reject();
}

#include "stdafx.h"
#include "QDlgSelect.h"

QStringList SelectList {
	QString("AAA"),
	QString("BBB"),
	QString("CCC"),
	QString("DDD"),
	QString("EEE")
};

QDlgSelect::QDlgSelect(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.listWidget->addItems(SelectList);
	setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
}

QDlgSelect::~QDlgSelect()
{}

void QDlgSelect::on_btnSure_clicked()
{
	QString text = ui.listWidget->currentItem()->text();
	emit SigSure(text);
	close();
}

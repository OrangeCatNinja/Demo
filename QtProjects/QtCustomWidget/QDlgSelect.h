#pragma once

#include <QDialog>
#include "ui_QDlgSelect.h"

class QDlgSelect : public QDialog
{
	Q_OBJECT

public:
	QDlgSelect(QWidget *parent = nullptr);
	~QDlgSelect();

signals:
	void SigSure(const QString& text);

public slots:
	void on_btnSure_clicked();

private:
	Ui::QDlgSelectClass ui;
};

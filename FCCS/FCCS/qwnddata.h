#pragma once

#include <QWidget>
#include "ui_qwnddata.h"

class QWndData : public QWidget
{
	Q_OBJECT

public:
	QWndData(QWidget *parent = Q_NULLPTR);
	~QWndData();

private:
	Ui::QWndData ui;
};

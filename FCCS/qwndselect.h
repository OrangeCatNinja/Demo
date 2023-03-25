#pragma once

#include <QWidget>
#include "ui_qwndselect.h"

class QWndSelect : public QWidget
{
	Q_OBJECT

public:
	QWndSelect(QWidget *parent = Q_NULLPTR);
	~QWndSelect();

private:
	Ui::QWndSelect ui;
};

#pragma once

#include <QWidget>
#include "ui_qwndchange.h"
#include "const.h"
#include "qselectcontrol.h"

class QWndChange : public QWidget
{
	Q_OBJECT

public:
	QWndChange(QWidget *parent = Q_NULLPTR);
	~QWndChange();

private:
	Ui::QWndChange ui;
};

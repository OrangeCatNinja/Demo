#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_fccs.h"
#include "qwndindex.h"

class FCCS : public QMainWindow
{
	Q_OBJECT

public:
	FCCS(QWidget *parent = Q_NULLPTR);


private:

private:
	Ui::FCCSClass ui;
	QWndIndex* m_pIndex;
};

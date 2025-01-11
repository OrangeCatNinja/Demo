#pragma once

#include <QWidget>
#include "ui_qwndshare.h"

class QWndShare : public QWidget
{
	Q_OBJECT

public:
	QWndShare(QWidget *parent = Q_NULLPTR);
	~QWndShare();

private:
	Ui::QWndShare ui;
};

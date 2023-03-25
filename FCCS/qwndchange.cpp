#include "qwndchange.h"

QWndChange::QWndChange(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->hide();
}

QWndChange::~QWndChange()
{
}

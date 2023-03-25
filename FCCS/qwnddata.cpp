#include "qwnddata.h"

QWndData::QWndData(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->hide();
}

QWndData::~QWndData()
{
}

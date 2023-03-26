#include "qwndshare.h"

QWndShare::QWndShare(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->hide();
}

QWndShare::~QWndShare()
{
}

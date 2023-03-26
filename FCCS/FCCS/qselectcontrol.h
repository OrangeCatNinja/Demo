#pragma once

#include <QWidget>
#include "ui_qselectcontrol.h"
#include "const.h"

class QSelectControl : public QWidget
{
	Q_OBJECT

public:
	QSelectControl(QWidget *parent = Q_NULLPTR, styleType style = styleType::Rect);
	~QSelectControl();
	FCCSConst::emFreq getFreqRet();

private:
	Ui::QSelectControl ui;
	FCCSConst::emFreq m_emFreqRet;
};

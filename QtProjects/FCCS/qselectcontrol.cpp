#include "qselectcontrol.h"

const QString g_strRoundSS = "QRadioButton::indicator{border-radius:15px}";

QSelectControl::QSelectControl(QWidget *parent, styleType style)
	: QWidget(parent)
	,m_emFreqRet(FCCSConst::GongPing)
{
	ui.setupUi(this);

	if (style == FCCSConst::emStyle::Round)
	{
		QString strLeftSS = ui.radLeft->styleSheet();
		QString strRightSS = ui.radRight->styleSheet();
		strLeftSS += g_strRoundSS;
		strRightSS += g_strRoundSS;
		ui.radLeft->setStyleSheet(strLeftSS);
		ui.radRight->setStyleSheet(strRightSS);
	}
}

QSelectControl::~QSelectControl()
{
}

FCCSConst::emFreq QSelectControl::getFreqRet()
{
	if (ui.radLeft->isChecked())
		m_emFreqRet = FCCSConst::GongPing;
	else
		m_emFreqRet = FCCSConst::BianPing;
	return m_emFreqRet;
}
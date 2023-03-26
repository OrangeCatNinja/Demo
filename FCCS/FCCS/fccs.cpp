#include "fccs.h"

FCCS::FCCS(QWidget *parent)
	: QMainWindow(parent)
	,m_pIndex(NULL)
{
	ui.setupUi(this);

	if (!m_pIndex)
	{
		m_pIndex = new QWndIndex(this);
		ui.layShow->addWidget(m_pIndex);
	}
}

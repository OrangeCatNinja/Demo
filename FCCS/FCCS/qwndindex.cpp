#include "qwndindex.h"

QWndIndex::QWndIndex(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_lstWnd.append(new QWndSelect(this));
	m_lstWnd.append(new QWndData(this));
	m_lstWnd.append(new QWndChange(this));
	m_lstWnd.append(new QWndShow(this));
	m_lstWnd.append(new QWndShare(this));
}

QWndIndex::~QWndIndex()
{
}

bool QWndIndex::changeWnd(int index)
{
	QWidget* pCurWnd = NULL;
	if(ui.layShow->count() > 0)
		pCurWnd = ui.layShow->itemAt(0)->widget();
	if (pCurWnd)
	{
		pCurWnd->hide();
		ui.layShow->removeWidget(pCurWnd);
	}
	if (index < m_lstWnd.size())
	{
		QWidget* pNextWnd = m_lstWnd.at(index);
		ui.layShow->addWidget(pNextWnd);
		pNextWnd->show();
		return true;
	}
	return false;
}

void QWndIndex::on_btnSelect_clicked()
{
	if (changeWnd(SELECTWND))
		;
}

void QWndIndex::on_btnData_clicked()
{
	if (changeWnd(DATAWND))
		;
}

void QWndIndex::on_btnChange_clicked()
{
	if (changeWnd(CHANGEWND))
		;
}

void QWndIndex::on_btnShow_clicked()
{
	if (changeWnd(SHOWWND))
		;
}

void QWndIndex::on_btnShare_clicked()
{
	if (changeWnd(SHAREWND))
		;
}

void QWndIndex::on_btnIndex_clicked()
{
}

#include "stdafx.h"
#include "QMainWin.h"


QMainWin::QMainWin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	InitData();

	InitSignalSlot();
}

QMainWin::~QMainWin()
{}

void QMainWin::InitData()
{
	ui.tree->setColumnCount(1);
	ui.tree->setHeaderHidden(true);

	QTreeWidgetItem* pTopItem = new QTreeWidgetItem(QStringList() << QString("��Ŀ"));
	ui.tree->addTopLevelItem(pTopItem);

	pTopItem->addChild(new QTreeWidgetItem(QStringList() << "�Զ���ؼ�"));
	pTopItem->addChild(new QTreeWidgetItem(QStringList() << "���߳�"));
	pTopItem->addChild(new QTreeWidgetItem(QStringList() << "��GLC����"));

	pTopItem->setExpanded(true);
}

void QMainWin::InitSignalSlot()
{
}

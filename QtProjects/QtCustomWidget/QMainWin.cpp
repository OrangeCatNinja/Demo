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

	QTreeWidgetItem* pTopItem = new QTreeWidgetItem(QStringList() << QString("项目"));
	ui.tree->addTopLevelItem(pTopItem);

	pTopItem->addChild(new QTreeWidgetItem(QStringList() << "自定义控件"));
	pTopItem->addChild(new QTreeWidgetItem(QStringList() << "多线程"));
	pTopItem->addChild(new QTreeWidgetItem(QStringList() << "仿GLC界面"));

	pTopItem->setExpanded(true);
}

void QMainWin::InitSignalSlot()
{
}

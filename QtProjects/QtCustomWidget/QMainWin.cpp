#include "stdafx.h"
#include "QMainWin.h"


QMainWin::QMainWin(QWidget *parent)
	: QDialog(parent)
	, m_pCurrentWidget(nullptr)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	
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

	QTreeWidgetItem* pItem = new QTreeWidgetItem(QStringList("自定义控件"));
	pItem->setData(0, Qt::ItemDataRole::UserRole, QVariant(WidgetType::enCustom));
	pTopItem->addChild(pItem);

	pItem = new QTreeWidgetItem(QStringList("多线程"));
	pItem->setData(0, Qt::ItemDataRole::UserRole, QVariant(WidgetType::enThread));
	pTopItem->addChild(pItem);

	pItem = new QTreeWidgetItem(QStringList("仿GLC界面"));
	pItem->setData(0, Qt::ItemDataRole::UserRole, QVariant(WidgetType::enGLC));
	pTopItem->addChild(pItem);

	pTopItem->setExpanded(true);

	//m_dlgCustom.setParent(this);
	//m_wdgThread.setParent(this);
}

void QMainWin::InitSignalSlot()
{
	connect(ui.tree, &QTreeWidget::itemClicked, this, &QMainWin::ClickTree);
}

void QMainWin::ClickTree(QTreeWidgetItem *item, int column)
{
	QVariant var = item->data(column, Qt::ItemDataRole::UserRole);
	WidgetType type = static_cast<WidgetType>(var.toInt());

	if (nullptr != m_pCurrentWidget)
	{
		m_pCurrentWidget->hide();
		ui.layoutShow->removeWidget(m_pCurrentWidget);
	}

	switch (type)
	{
	case enCustom:
		m_pCurrentWidget = &m_dlgCustom;
		break;
	case enThread:
		m_pCurrentWidget = &m_wdgThread;
		break;
	case enGLC:
		m_pCurrentWidget = &m_wdgGlc;
		break;
	default:
		break;
	}

	ui.layoutShow->addWidget(m_pCurrentWidget);
	m_pCurrentWidget->show();
}

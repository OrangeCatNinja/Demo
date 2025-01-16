#include "stdafx.h"
#include "QDlgGLC.h"
#include <QLabel>
#include <QComboBox>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "QDlgSelect.h"

//单纯计数用
int g_nItemNum = 0;

QString firHeader("生产阶段");

std::list<QString> secHeader{
	QString("建筑名称"),
	QString("用量"),
	QString("生产因子\n(tCO₂e/用量)"),
	QString("碳排放量\n(tCO₂e)(实时)"),
	QString("单位"),
};

QDlgGLC::QDlgGLC(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	InitTable();
	InitData();
	InitSignalSlot();
}

QDlgGLC::~QDlgGLC()
{}

void QDlgGLC::InitTable()
{
	ui.table->verticalHeader()->setVisible(false);
	ui.table->horizontalHeader()->setVisible(false);
	ui.table->setShowGrid(true);
	ui.table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//等距
	ui.table->horizontalHeader()->setDefaultSectionSize(50);
	ui.table->verticalHeader()->setDefaultSectionSize(50);
	
	//用单元格实现表头
	ui.table->setRowCount(2);
	ui.table->setColumnCount(secHeader.size());
	ui.table->setSpan(0, 0, 1, secHeader.size());
	
	//合并后itemAt会失效，要用新的单元格
	QTableWidgetItem* pSpanItem = new QTableWidgetItem(firHeader);
	pSpanItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	pSpanItem->setBackgroundColor(QColor(128, 128, 128));
	pSpanItem->setTextColor(QColor(0, 0, 0));
	pSpanItem->setFlags(pSpanItem->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
	ui.table->setItem(0, 0, pSpanItem);

	int i = 0;
	for (const QString& h : secHeader)
	{
		int nColumn = i++;
		QTableWidgetItem* pItem = new QTableWidgetItem(h);
		ui.table->setItem(1, nColumn, pItem);

		QPushButton* pButton = new QPushButton();
		pButton->setIcon(QIcon(":/QtCustomWidget/btnIcon"));
		pButton->setStyleSheet("background: transparent; border: none;");

		QLabel* pLabel = new QLabel(h);

		connect(pButton, &QPushButton::clicked, this, &QDlgGLC::ShowPicture);

		QHBoxLayout *pLayout = new QHBoxLayout();
		QWidget *pWidget = new QWidget();
		pLayout->addWidget(pLabel);
		pLayout->addWidget(pButton);
		pWidget->setLayout(pLayout);
		pWidget->setStyleSheet("background-color: lightgray;");

		ui.table->setCellWidget(1, nColumn, pWidget);
	}
}

void QDlgGLC::InitData()
{
	/************************************************************************/
	/* 数据格式为
	 * + Item		|	Item	|	ComboBox	|	PushButton(...)	|	PushButton	|
	 * (折叠按钮)		文字		下拉框			...按钮，可多选		按钮
	*/
	/************************************************************************/

	//添加假数据
	AddRow(0);
	AddRow(1);
	AddRow(0);
	AddRow(0);
	AddRow(1);
}

void QDlgGLC::InitSignalSlot()
{
}

void QDlgGLC::AddRow(int type, QTableWidgetItem* pInfo)
{
	QTableWidgetItem* pItem = nullptr;
	int nCurRow = ui.table->rowCount();
	ui.table->setRowCount(nCurRow + 1);

	// 1	Item
	pItem = new QTableWidgetItem(GetItemContent());
	pItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QTableWidgetItem* pItemInfo = pItem;
	QVariant var;
	ItemInfo info(type);
	ui.table->setItem(nCurRow, 0, pItem);

	if (1 == type)
	{
		ui.table->setCellWidget(nCurRow, 0, CreateCollapseItem(type, pItem->text()));
		pItem->setText("");
	}
	else if (2 == type)
	{
		pItem->setIcon(QIcon(":/QtCustomWidget/line"));
		info.pItem = pInfo;
	}

	var = QVariant::fromValue(info);
	pItem->setData(Qt::UserRole, var);

	// 2	Item
	pItem = new QTableWidgetItem(GetItemContent());
	pItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	ui.table->setItem(nCurRow, 1, pItem);

	// 3	ComboBox
	pItem = new QTableWidgetItem();
	ui.table->setItem(nCurRow, 2, pItem);
	ui.table->setCellWidget(nCurRow, 2, CreateComboBoxItem());

	// 4	PushButton(...)
	pItem = new QTableWidgetItem();
	ui.table->setItem(nCurRow, 3, pItem);
	ui.table->setCellWidget(nCurRow, 3, CreateButtonItem(GetItemContent()));

	// 5	PushButton
	pItem = new QTableWidgetItem();
	ui.table->setItem(nCurRow, 4, pItem);
	ui.table->setCellWidget(nCurRow, 4, CreatePushButton());

	if (1 == type)
	{
		for (int i = 0; i < 3; ++i)
			AddRow(2, pItemInfo);
	}
}

QWidget * QDlgGLC::CreateComboBoxItem()
{
	QComboBox* pCombo = new QComboBox();
	pCombo->addItems(QStringList() << "Combox_1" << "Combox_2" << "Combox_3");
	pCombo->setEditable(true);
	pCombo->lineEdit()->setReadOnly(true);
	pCombo->lineEdit()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	pCombo->setCurrentIndex(0);

	return pCombo;
}

QWidget * QDlgGLC::CreateButtonItem(const QString& text)
{
	QWidget* pWidget = new QWidget();
	QHBoxLayout* pLayout = new QHBoxLayout();

	QLabel* pLabel = new QLabel(text);
	QPushButton* pBtn = new QPushButton("...");
	pLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	pBtn->setFixedWidth(30);

	pLayout->addWidget(pLabel);
	pLayout->addWidget(pBtn);

	connect(pBtn, &QPushButton::clicked, this, &QDlgGLC::ShowSelectWidget);

	pWidget->setLayout(pLayout);

	return pWidget;
}

QWidget * QDlgGLC::CreatePushButton()
{
	QWidget* pWidget = new QWidget();
	QHBoxLayout* pLayout = new QHBoxLayout();

	QPushButton* pBtn = new QPushButton("删除");

	connect(pBtn, &QPushButton::clicked, this, &QDlgGLC::RemoveItem);

	pLayout->addWidget(pBtn);
	pWidget->setLayout(pLayout);

	return pWidget;
}

QWidget * QDlgGLC::CreateCollapseItem(int type, const QString& text)
{
	QWidget* pWidget = new QWidget();
	QHBoxLayout* pLayout = new QHBoxLayout();

	QPushButton* pBtn = new QPushButton("+");
	pBtn->setFixedSize(20, 20);
	connect(pBtn, &QPushButton::clicked, this, &QDlgGLC::Collapse);

	QLabel* pLabel = new QLabel(text);
	pLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	pLayout->addWidget(pBtn);
	pLayout->addWidget(pLabel);
	pWidget->setLayout(pLayout);

	return pWidget;
}

void QDlgGLC::ShowPicture()
{
	QDialog w(this);
	w.resize(1038, 624);
	w.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	w.setStyleSheet("border-image: url(:/QtCustomWidget/template);");
	w.exec();
}

void QDlgGLC::ShowSelectWidget()
{
	QPushButton* pBtn = dynamic_cast<QPushButton*>(this->sender());
	if (nullptr == pBtn)
		return;

	QPoint pt = pBtn->parentWidget()->pos();

	QModelIndex idx = ui.table->indexAt(pt);
	m_nCurRow = idx.row();

	QDlgSelect w;
	connect(&w, &QDlgSelect::SigSure, this, &QDlgGLC::ChangeSelectedItem);
	w.exec();
}

void QDlgGLC::ChangeSelectedItem(const QString & text)
{
	QWidget* pWidget = ui.table->cellWidget(m_nCurRow, 3);
	if (nullptr == pWidget)
		return;

	auto pItem = pWidget->layout()->itemAt(0);
	QLabel* pLabel = qobject_cast<QLabel*>(pItem->widget());
	if (nullptr != pLabel)
		pLabel->setText(text);
}

void QDlgGLC::RemoveItem()
{
	QPushButton* pBtn = dynamic_cast<QPushButton*>(this->sender());
	if (nullptr == pBtn)
		return;

	QPoint pt = pBtn->parentWidget()->pos();

	QModelIndex idx = ui.table->indexAt(pt);
	m_nCurRow = idx.row();

	QTableWidgetItem* pItem = ui.table->item(m_nCurRow, 0);
	if (nullptr == pItem)
		return;

	QVariant var = pItem->data(Qt::UserRole);
	ItemInfo info = var.value<ItemInfo>();

	if (0 == info.type)
	{
		ui.table->removeRow(m_nCurRow);
	}
	else if (2 == info.type)
	{
		if (!info.pItem)
			return;

		QVariant var = info.pItem->data(Qt::UserRole);
		ItemInfo infoTemp = var.value<ItemInfo>();
		infoTemp.nCollapseNum -= 1;
		info.pItem->setData(Qt::UserRole, QVariant::fromValue(infoTemp));

		ui.table->removeRow(m_nCurRow);
	}
	else if (1 == info.type)
	{
		for (int i = 0; i < info.nCollapseNum + 1; ++i)
		{
			int nCount = ui.table->rowCount();
			ui.table->removeRow(m_nCurRow);
		}
	}
	else
		return;
}

void QDlgGLC::Collapse()
{
	QPushButton* pBtn = dynamic_cast<QPushButton*>(this->sender());
	if (nullptr == pBtn)
		return;

	QPoint pt = pBtn->parentWidget()->pos();

	QModelIndex idx = ui.table->indexAt(pt);
	m_nCurRow = idx.row();

	QTableWidgetItem* pItem = ui.table->item(m_nCurRow, 0);
	if (nullptr == pItem)
		return;

	QVariant var = pItem->data(Qt::UserRole);
	ItemInfo info = var.value<ItemInfo>();

	info.bCollapse = !info.bCollapse;
	if (info.bCollapse)
	{
		pBtn->setText("-");

		for(int i = 1; i <= info.nCollapseNum; ++i)
			ui.table->hideRow(m_nCurRow + i);
	}
	else
	{
		pBtn->setText("+");

		for (int i = 1; i <= info.nCollapseNum; ++i)
			ui.table->showRow(m_nCurRow + i);
	}

	pItem->setData(Qt::UserRole, QVariant::fromValue(info));
}


QString GetItemContent()
{
	QString str = QString("Item%1").arg(g_nItemNum++);
	return str;
}

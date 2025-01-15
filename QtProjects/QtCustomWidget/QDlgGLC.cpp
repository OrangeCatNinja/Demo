#include "stdafx.h"
#include "QDlgGLC.h"
#include <QLabel>
#include <QComboBox>
#include <QDialog>
#include <QLineEdit>

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
	AddRow(false);
	AddRow(true);
	AddRow(false);
	AddRow(false);
	AddRow(true);
}

void QDlgGLC::InitSignalSlot()
{
}

void QDlgGLC::AddRow(bool collapse)
{
	QTableWidgetItem* pItem = nullptr;
	int nCurRow = ui.table->rowCount();
	ui.table->setRowCount(nCurRow + 1);

	// 1	Item
	pItem = new QTableWidgetItem(GetItemContent());
	ui.table->setItem(nCurRow, 0, pItem);
	if (collapse)
	{
		ui.table->setCellWidget(nCurRow, 0, CreateCollapseItem(3, pItem->text()));
		pItem->setText("");
	}

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

	if (collapse)
	{
		for (int i = 0; i < 3; ++i)
			AddRow(false);
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

	pWidget->setLayout(pLayout);

	return pWidget;
}

QWidget * QDlgGLC::CreatePushButton()
{
	QWidget* pWidget = new QWidget();
	QHBoxLayout* pLayout = new QHBoxLayout();

	QPushButton* pBtn = new QPushButton("删除");

	pLayout->addWidget(pBtn);
	pWidget->setLayout(pLayout);

	return pWidget;
}

QWidget * QDlgGLC::CreateCollapseItem(int nCollapseRows, const QString& text)
{
	QWidget* pWidget = new QWidget();
	QHBoxLayout* pLayout = new QHBoxLayout();

	QPushButton* pBtn = new QPushButton("+");
	pBtn->setFixedSize(20, 20);

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



QString GetItemContent()
{
	QString str = QString("Item%1").arg(g_nItemNum++);
	return str;
}

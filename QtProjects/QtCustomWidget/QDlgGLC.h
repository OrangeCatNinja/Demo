#pragma once

#include <QWidget>
#include "ui_QDlgGLC.h"
#include <QObject>

struct ItemInfo
{
	ItemInfo() {}
	ItemInfo(int t) { type = t; }

	int type = 0;//0:普通行，1:折叠头行，具有折叠按钮，	2:折叠行，具有折叠图标，能被折叠
	bool bCollapse = false;//是否折叠状态
	int nCollapseNum = 3;//折叠头所拥有的折叠行的数量
	QTableWidgetItem* pItem = nullptr;//如果type=2，该指针指向折叠头行的Item
};

class QDlgGLC : public QWidget
{
	Q_OBJECT

public:
	QDlgGLC(QWidget *parent = nullptr);
	~QDlgGLC();

	void InitTable();
	void InitData();
	void InitSignalSlot();

private:
	//是否有折叠按钮
	void AddRow(int type, QTableWidgetItem* pInfo = nullptr);

	QWidget* CreateComboBoxItem();
	QWidget* CreateButtonItem(const QString& text);
	QWidget* CreatePushButton();
	QWidget* CreateCollapseItem(int type, const QString& text);

public slots:
	void ShowPicture();

	void ShowSelectWidget();

	void ChangeSelectedItem(const QString& text);

	void RemoveItem();

	void Collapse();

private:
	Ui::QDlgGLCClass ui;

	int m_nCurRow;
};

//根据编号返回单元格内容
QString GetItemContent();

Q_DECLARE_METATYPE(ItemInfo)
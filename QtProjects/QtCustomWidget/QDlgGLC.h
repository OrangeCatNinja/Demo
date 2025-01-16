#pragma once

#include <QWidget>
#include "ui_QDlgGLC.h"
#include <QObject>

struct ItemInfo
{
	ItemInfo() {}
	ItemInfo(int t) { type = t; }

	int type = 0;//0:��ͨ�У�1:�۵�ͷ�У������۵���ť��	2:�۵��У������۵�ͼ�꣬�ܱ��۵�
	bool bCollapse = false;//�Ƿ��۵�״̬
	int nCollapseNum = 3;//�۵�ͷ��ӵ�е��۵��е�����
	QTableWidgetItem* pItem = nullptr;//���type=2����ָ��ָ���۵�ͷ�е�Item
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
	//�Ƿ����۵���ť
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

//���ݱ�ŷ��ص�Ԫ������
QString GetItemContent();

Q_DECLARE_METATYPE(ItemInfo)
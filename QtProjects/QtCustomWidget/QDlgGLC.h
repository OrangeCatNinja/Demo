#pragma once

#include <QWidget>
#include "ui_QDlgGLC.h"

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
	void AddRow(bool collapse);

	QWidget* CreateComboBoxItem();
	QWidget* CreateButtonItem(const QString& text);
	QWidget* CreatePushButton();
	QWidget* CreateCollapseItem(int nCollapseRows, const QString& text);

public slots:
	void ShowPicture();

private:
	Ui::QDlgGLCClass ui;
};

//根据编号返回单元格内容
QString GetItemContent();
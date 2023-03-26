#pragma once
#define SELECTWND 0
#define DATAWND 1
#define CHANGEWND 2
#define SHOWWND 3
#define SHAREWND 4

#include <QWidget>
#include "ui_qwndindex.h"
#include "qwndselect.h"
#include "qwnddata.h"
#include "qwndchange.h"
#include "qwndshow.h"
#include "qwndshare.h"


class QWndIndex : public QWidget
{
	Q_OBJECT

public:
	QWndIndex(QWidget *parent = Q_NULLPTR);
	~QWndIndex();
	bool changeWnd(int index);

public slots:
	void on_btnSelect_clicked();
	void on_btnData_clicked();
	void on_btnChange_clicked();
	void on_btnShow_clicked();
	void on_btnShare_clicked();
	void on_btnIndex_clicked();

private:
	Ui::QWndIndex ui;
	QList<QWidget*> m_lstWnd;
};

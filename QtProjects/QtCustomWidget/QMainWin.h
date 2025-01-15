#pragma once

#include <QDialog>
#include "ui_QMainWin.h"
#include "QtWidgetsDemo.h"
#include "QDlgThreadTimer.h"
#include "QDlgGLC.h"

enum WidgetType
{
	enCustom = 0,
	enThread,
	enGLC
};

class QMainWin : public QDialog
{
	Q_OBJECT

public:
	QMainWin(QWidget *parent = nullptr);
	~QMainWin();

	void InitData();

	void InitSignalSlot();

public slots:
	void ClickTree(QTreeWidgetItem *item, int column);

private:
	Ui::QMainWinClass ui;

	QtWidgetsDemo m_dlgCustom;
	QDlgThreadTimer m_wdgThread;
	QDlgGLC m_wdgGlc;

	QWidget* m_pCurrentWidget;
};

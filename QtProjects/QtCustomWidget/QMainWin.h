#pragma once

#include <QDialog>
#include "ui_QMainWin.h"

class QMainWin : public QDialog
{
	Q_OBJECT

public:
	QMainWin(QWidget *parent = nullptr);
	~QMainWin();

	void InitData();

	void InitSignalSlot();

private:
	Ui::QMainWinClass ui;
};

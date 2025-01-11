#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_raise3d.h"
#include <qnewtextedit.h>
#include <qscrollarea.h>

class Raise3D : public QMainWindow
{
	Q_OBJECT

public:
	Raise3D(QWidget *parent = Q_NULLPTR);

	bool getText(QString file);

public slots:
	void slotPaintFinish(int hight);

private:
	Ui::Raise3DClass ui;

	QRect m_rect;
	QString m_strContent;
	QScrollArea* m_pScrollArea;
};

#pragma once

#include <QWidget>
#include "ui_qnewtextedit.h"
#include <QTextEdit>
#include <qpainter.h>

class QNewTextEdit : public QWidget
{
	Q_OBJECT

public:
	QNewTextEdit(QWidget *parent = Q_NULLPTR);
	~QNewTextEdit();

	void setText(QStringList content);
	void clear();

protected:
	void paintEvent(QPaintEvent* event);

signals:
	void sigPaintFinish(int hight);

private:
	Ui::QNewTextEdit ui;
	QStringList m_lstContent;
};

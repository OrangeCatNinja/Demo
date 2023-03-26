#include "raise3d.h"
#include <qfile.h>
#include <qtextstream.h>
#include <QResizeEvent>

Raise3D::Raise3D(QWidget *parent)
	: QMainWindow(parent)
	,m_pScrollArea(NULL)
{
	ui.setupUi(this);

	connect(ui.widget, &QNewTextEdit::sigPaintFinish, this, &Raise3D::slotPaintFinish);

	QString strFile = QString("%1/%2").arg(QApplication::applicationDirPath()).arg("content.txt");
	getText(strFile);

	ui.widget->update();
}

bool Raise3D::getText(QString fileName)
{
	QFile file(fileName);
	if (!file.exists())
		return false;
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;

	QTextStream stream(&file);
	stream.setCodec("UTF-8");
	QStringList lstContent;
	while (!stream.atEnd())
	{
		lstContent << stream.readLine();
	}
	ui.widget->setText(lstContent);
	file.close();
	return true;
}

void Raise3D::slotPaintFinish(int hight)
{
	int width = ui.widget->width();
	int height = hight;
	ui.scrollAreaWidgetContents->setMinimumSize(width, height);
}
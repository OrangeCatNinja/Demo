#include "qnewtextedit.h"

QNewTextEdit::QNewTextEdit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QNewTextEdit::~QNewTextEdit()
{
}

void QNewTextEdit::setText(QStringList content)
{
	m_lstContent = content;
}

void QNewTextEdit::clear()
{
}

void QNewTextEdit::paintEvent(QPaintEvent * event)
{
	QWidget::paintEvent(event);
	
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 2));
	painter.setFont(QFont("宋体", 9));

	QFontMetrics fontMetrics(painter.font());

	int nMaxWidth = this->width();//控件宽
	int nFontHight = fontMetrics.height() + 10;
	int nLineCount = 0;

	for (int i = 0; i < m_lstContent.size(); i++)
	{
		QString strLine = m_lstContent[i];
		int nLineWidth = fontMetrics.width(strLine);//字符串总宽
		if (nLineWidth < nMaxWidth)
		{
			QRect rect(0, nLineCount*nFontHight, nMaxWidth, nFontHight);
			painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, strLine);
			nLineCount++;
		}
		else
		{
			int nLineNum = nLineWidth / nMaxWidth + 1;//要换的行数
			int size = strLine.size();
			double nMaxFontCount = (nMaxWidth * strLine.size()) / nLineWidth;//一整行的字符数

			int nStart = 0 ,nEnd = 0;
			for (int loop = 0; loop < nLineNum; loop++)
			{
				QString strTemp = strLine.mid(loop*nMaxFontCount, nMaxFontCount);
				QRect rect(0, nLineCount*nFontHight, nMaxWidth, nFontHight);
				int nLastCharAsc = int(strTemp.at(strTemp.size() - 1).toLatin1());//字符串最后一个字符的ascii码
				if ((nLastCharAsc > 64 && nLastCharAsc < 91) || (nLastCharAsc > 96 && nLastCharAsc < 123))//如果是英语
					strTemp += "-";//加连接符

				painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, strTemp);
				nLineCount++;
			}
		}
	}

	QRect geom = this->geometry();
	QRect contentRect(geom.x(), geom.y(), geom.width(), nFontHight * nLineCount);
	this->setGeometry(contentRect);
	emit sigPaintFinish(contentRect.height());
}

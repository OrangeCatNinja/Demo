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
	painter.setFont(QFont("����", 9));

	QFontMetrics fontMetrics(painter.font());

	int nMaxWidth = this->width();//�ؼ���
	int nFontHight = fontMetrics.height() + 10;
	int nLineCount = 0;

	for (int i = 0; i < m_lstContent.size(); i++)
	{
		QString strLine = m_lstContent[i];
		int nLineWidth = fontMetrics.width(strLine);//�ַ����ܿ�
		if (nLineWidth < nMaxWidth)
		{
			QRect rect(0, nLineCount*nFontHight, nMaxWidth, nFontHight);
			painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, strLine);
			nLineCount++;
		}
		else
		{
			int nLineNum = nLineWidth / nMaxWidth + 1;//Ҫ��������
			int size = strLine.size();
			double nMaxFontCount = (nMaxWidth * strLine.size()) / nLineWidth;//һ���е��ַ���

			int nStart = 0 ,nEnd = 0;
			for (int loop = 0; loop < nLineNum; loop++)
			{
				QString strTemp = strLine.mid(loop*nMaxFontCount, nMaxFontCount);
				QRect rect(0, nLineCount*nFontHight, nMaxWidth, nFontHight);
				int nLastCharAsc = int(strTemp.at(strTemp.size() - 1).toLatin1());//�ַ������һ���ַ���ascii��
				if ((nLastCharAsc > 64 && nLastCharAsc < 91) || (nLastCharAsc > 96 && nLastCharAsc < 123))//�����Ӣ��
					strTemp += "-";//�����ӷ�

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

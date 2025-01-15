#include "stdafx.h"
#include "QtWidgetsDemo.h"
#include <QSpinBox.h>

QtWidgetsDemo::QtWidgetsDemo(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

	m_pBtn = ui.btnCalculate;
	m_pSpin_1 = ui.spinBoxNum1;
	m_pSpin_2 = ui.spinBoxNum2;
	m_nNum_1 = m_nNum_2 = m_nNumResult = 0;

	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
	hide();

	connect(m_pBtn, &QPushButton::clicked, this, &QtWidgetsDemo::CalculateResult);
	connect(m_pBtn, SIGNAL(QPushButton::clicked), this, SLOT(QtWidgetsDemo::CalculateResult));
	connect(ui.spinBoxNum1, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtWidgetsDemo::SpinValueChange_1);
	connect(ui.spinBoxNum2, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtWidgetsDemo::SpinValueChange_2);
}

QtWidgetsDemo::~QtWidgetsDemo()
{}

void QtWidgetsDemo::CalculateResult()
{
	m_nNumResult = m_nNum_1 + m_nNum_2;
	ui.result->setText(QString::number(m_nNumResult));
}

void QtWidgetsDemo::on_btnCalculate_clicked()
{
	QString str = ui.result->text();
	m_nNumResult = str.toInt();
}

void QtWidgetsDemo::SpinValueChange_1(int val)
{
	m_nNum_1 = val;
	ui.num1->setText(QString::number(val));
}

void QtWidgetsDemo::SpinValueChange_2(int val)
{
	m_nNum_2 = val;
	ui.num2->setText(QString::number(val));
}

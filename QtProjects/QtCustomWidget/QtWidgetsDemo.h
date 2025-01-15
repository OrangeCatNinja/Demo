#pragma once

#include <QtWidgets/QDialog>
#include "ui_QtWidgetsDemo.h"

class QtWidgetsDemo : public QDialog
{
    Q_OBJECT

public:
    QtWidgetsDemo(QWidget *parent = nullptr);
    ~QtWidgetsDemo();

private slots:

	void CalculateResult();
	void on_btnCalculate_clicked();

	void SpinValueChange_1(int val);

	void SpinValueChange_2(int val);

private:
    Ui::QtWidgetsDemoClass ui;

	QPushButton* m_pBtn;
	QSpinBox* m_pSpin_1;
	QSpinBox* m_pSpin_2;

	int m_nNum_1;
	int m_nNum_2;
	int m_nNumResult;
};

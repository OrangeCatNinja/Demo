/********************************************************************************
** Form generated from reading UI file 'qnewtextedit.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEWTEXTEDIT_H
#define UI_QNEWTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QNewTextEdit
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *QNewTextEdit)
    {
        if (QNewTextEdit->objectName().isEmpty())
            QNewTextEdit->setObjectName(QString::fromUtf8("QNewTextEdit"));
        QNewTextEdit->resize(400, 300);
        QNewTextEdit->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #242424;\n"
"	background: white;\n"
"}"));
        gridLayout = new QGridLayout(QNewTextEdit);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(QNewTextEdit);

        QMetaObject::connectSlotsByName(QNewTextEdit);
    } // setupUi

    void retranslateUi(QWidget *QNewTextEdit)
    {
        QNewTextEdit->setWindowTitle(QCoreApplication::translate("QNewTextEdit", "QNewTextEdit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QNewTextEdit: public Ui_QNewTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEWTEXTEDIT_H

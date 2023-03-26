/********************************************************************************
** Form generated from reading UI file 'raise3d.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAISE3D_H
#define UI_RAISE3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qnewtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_Raise3DClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QNewTextEdit *widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Raise3DClass)
    {
        if (Raise3DClass->objectName().isEmpty())
            Raise3DClass->setObjectName(QString::fromUtf8("Raise3DClass"));
        Raise3DClass->resize(600, 400);
        Raise3DClass->setStyleSheet(QString::fromUtf8("#widget{\n"
"	border:1px solid #242424;\n"
"	background: white;\n"
"}"));
        centralWidget = new QWidget(Raise3DClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 580, 358));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QNewTextEdit(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        Raise3DClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Raise3DClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Raise3DClass->setStatusBar(statusBar);

        retranslateUi(Raise3DClass);

        QMetaObject::connectSlotsByName(Raise3DClass);
    } // setupUi

    void retranslateUi(QMainWindow *Raise3DClass)
    {
        Raise3DClass->setWindowTitle(QCoreApplication::translate("Raise3DClass", "Raise3D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Raise3DClass: public Ui_Raise3DClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAISE3D_H

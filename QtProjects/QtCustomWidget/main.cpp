#include "stdafx.h"
#include <QtWidgets/QApplication>
#include "QMainWin.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWin w;
    w.show();
    return a.exec();
}

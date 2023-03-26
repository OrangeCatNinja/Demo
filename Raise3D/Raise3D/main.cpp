#include "raise3d.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Raise3D w;
	w.show();
	return a.exec();
}

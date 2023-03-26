#include "fccs.h"
#include <QtWidgets/QApplication>
#include "qwndlogin.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWndLogin login;
	int ret = login.exec();
	if (ret == QDialog::Rejected)
		return -1;
	FCCS w;
	w.show();
	return a.exec();
}

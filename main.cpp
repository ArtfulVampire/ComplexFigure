#include <QApplication>
#include "picture.h"
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Picture peec;
	for(int i = 0; i < 180; ++i)
	{
		peec.compose();
		peec.draw("/media/Files/Pictures/NewCF");
	}

    return 0;
}

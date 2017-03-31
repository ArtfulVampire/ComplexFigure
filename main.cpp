#include <QApplication>
#include "picture.h"
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//	Picture::drawSlices("/media/Files/Pictures/vars");
//	return 0;

    Picture peec;

	for(int i = 0; i < 300; ++i)
	{
		peec.compose();
		peec.draw("/media/Files/Pictures/NewCF");
	}

    return 0;
}

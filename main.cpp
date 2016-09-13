#include <QApplication>
#include "picture.h"
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Picture peec;
    peec.compose();
    peec.draw("/media/Files/Data/asfasdf.jpg");

    return 0;
}

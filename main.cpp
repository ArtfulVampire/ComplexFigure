#include <QApplication>
#include "picture.h"
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Picture peec;
    peec.compose();
    peec.draw("/media/Files/Data");

    return 0;
}

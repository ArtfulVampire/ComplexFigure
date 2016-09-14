#ifndef PICTURE_H
#define PICTURE_H
#include <vector>
#include <QPixmap>
#include <QColor>
#include <QPainter>
#include <QPolygon>
#include <chrono>
#include <random>
#include <iostream>
#include "pieces.h"


enum figType {square = 0,
              rect = 1,
              tri = 2,
              rhomb = 3,
              trapeze = 4,
              paral = 5,
              penta = 6,
              hexa = 7};


class Picture
{
public:
    Picture();
    const int width = 1280;
    const int height = 1024;
    const double size = 270.;
    void draw(const QString & outPath = QString());
    void compose();
    QPolygon myPolygon(int type, int num);

private:
    static const int numFigs = 3;

    const double figX[numFigs] = {
        1.1/6.,
        3./6.,
        4.9/6.
    };
    const double figY = 4.4/6.;
    const double numY = 5.7/6.;
    const QColor color = "darkgray";
    QPolygon figs[numFigs];
    int figTypes[numFigs];
    int ans;
    void addPieces();


};

#endif // PICTURE_H

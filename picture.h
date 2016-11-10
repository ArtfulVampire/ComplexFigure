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
#include <QTransform>


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
    void draw(const QString & outDir = QString());
    void compose();
    QPolygon myPolygon(int type, int num);

private:
    static const int numFigs = 3;

    const double figX[numFigs] = {
        1.1/6.,
        3./6.,
        4.9/6.
    };

    const double dist_3 = 1.6;

    const std::vector<double> pieceX_3 = {
        (3. - dist_3)/6.,
        3./6.,
        (3. + dist_3)/6.
    };
	const std::vector<double> pieceY_3 = std::vector<double>(3, 2.2 / 6.);


	const double dist_4 = 1.5;

    const std::vector<double> pieceX_4 = {
		(3. - 1.35 * dist_4)/6.,
		(3. - 0.45 * dist_4)/6.,
		(3. + 0.45 * dist_4)/6.,
		(3. + 1.35 * dist_4)/6.
	};

#if 01
	const std::vector<double> pieceY_4 = std::vector<double>(4, 2.2 / 6.);
#else
	const std::vector<double> pieceY_4 = {
		(2. + 0.8) / 6.,
		(2. - 0.5) / 6.,
		(2. - 0.5) / 6.,
		(2. + 0.8) / 6.
	};
#endif


    const double figY = 4.4/6.;
    const double numY = 5.7/6.;
    const QColor color = "darkgray";
    QPolygon figs[numFigs];
    int figTypes[numFigs];
    int ans;
    void addPieces();


};

#endif // PICTURE_H

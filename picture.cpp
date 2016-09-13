#include "picture.h"

Picture::Picture()
{

}

QPolygon Picture::myPolygon(int type, int num)
{
    double size = 270.;
    double halfSize = size / 2.;
    double halfSizeX = halfSize / width;
    double halfSizeY = halfSize / height;

    const double degToRad = M_PI / 180.;

    QVector<QPointF> vec{};
    switch(type)
    {
    case 0:
    {
        /// square
        vec.push_back({figX[num] - halfSizeX, figY - halfSizeY});
        vec.push_back({figX[num] + halfSizeX, figY - halfSizeY});
        vec.push_back({figX[num] + halfSizeX, figY + halfSizeY});
        vec.push_back({figX[num] - halfSizeX, figY + halfSizeY});
        break;
    }
    case 1:
    {
        /// rect
//        halfSizeY /= 1.1;
        const double sizeX = halfSizeX * 1.35;
        vec.push_back({figX[num] - sizeX, figY - halfSizeY});
        vec.push_back({figX[num] + sizeX, figY - halfSizeY});
        vec.push_back({figX[num] + sizeX, figY + halfSizeY});
        vec.push_back({figX[num] - sizeX, figY + halfSizeY});
        break;
    }
    case 2:
    {
        /// triange
        vec.push_back({figX[num] - halfSizeX, figY + halfSizeY});
        vec.push_back({figX[num] + halfSizeX, figY - halfSizeY});
        vec.push_back({figX[num] + halfSizeX, figY + halfSizeY});
        break;
    }
    case 3:
    {
        /// rhomb
        const double sizeX = halfSizeX * 1.4;
        vec.push_back({figX[num] - sizeX, figY});
        vec.push_back({figX[num], figY - halfSizeY});
        vec.push_back({figX[num] + sizeX, figY});
        vec.push_back({figX[num], figY + halfSizeY});
        break;
    }
    case 4:
    {
        /// trapeze
//        halfSizeX /= 1.1;
//        halfSizeY /= 1.1;
        const double alpha = 54.;
        const double halfUpper = 0.8 * halfSizeX;
        const double halfLower = halfUpper + tan((90. - alpha) * degToRad) * halfSizeX;
        vec.push_back({figX[num] - halfLower, figY + halfSizeY});
        vec.push_back({figX[num] - halfUpper, figY - halfSizeY});
        vec.push_back({figX[num] + halfUpper, figY - halfSizeY});
        vec.push_back({figX[num] + halfLower, figY + halfSizeY});
        break;
    }
    case 5:
    {
        /// paral
        const double alpha = 65.; /// base ange, deg
        const double base = halfSizeX * tan( (90. - alpha) * degToRad); /// 1/4 of a base
        vec.push_back({figX[num] - base, figY + halfSizeY});
        vec.push_back({figX[num] - 3 * base, figY - halfSizeY});
        vec.push_back({figX[num] + base, figY - halfSizeY});
        vec.push_back({figX[num] + 3 * base, figY + halfSizeY});
        break;
    }
    case 6:
    {
        /// penta
        const double halfSideX = halfSizeX * tan(36. * degToRad);
        const double radiusY = halfSizeY / cos(36. * degToRad);
        const double radiusX = halfSizeX / cos(36. * degToRad);
        vec.push_back({figX[num] - halfSideX, figY + halfSizeY});

        vec.push_back({figX[num] - radiusX * cos(18. * degToRad),
                       figY - radiusY * sin(18. * degToRad)});

        vec.push_back({figX[num], figY - radiusY});

        vec.push_back({figX[num] + radiusX * cos(18. * degToRad),
                       figY - radiusY * sin(18. * degToRad)});

        vec.push_back({figX[num] + halfSideX, figY + halfSizeY});
        break;
    }
    case 7:
    {
        /// hexa
        const double halfSideX = halfSizeX * tan(30. * degToRad);
        const double radiusX = halfSizeX / cos(30. * degToRad);
        vec.push_back({figX[num] - halfSideX, figY + halfSizeY});
        vec.push_back({figX[num] - radiusX, figY});
        vec.push_back({figX[num] - halfSideX, figY - halfSizeY});
        vec.push_back({figX[num] + halfSideX, figY - halfSizeY});
        vec.push_back({figX[num] + radiusX, figY});
        vec.push_back({figX[num] + halfSideX, figY + halfSizeY});

        break;
    }
    default:
    {
        std::cout << "myPolygon: bad input" << std::endl;
        break;
    }
    }

    QVector<QPoint> vec2;
    for(const QPointF p : vec)
    {
        vec2.push_back(QPoint(p.x() * width, p.y() * height));
    }
    return QPolygon(vec2);
}

void Picture::compose()
{
//    std::default_random_engine gen;
    std::random_device gen;
    std::uniform_int_distribution<int> distrAns(1, 3);
    /// 8 with hexzgon
    std::vector<int> feeg(8);

    std::iota(std::begin(feeg), std::end(feeg), 0);
    std::shuffle(std::begin(feeg), std::end(feeg), std::random_device{});

    for(int i = 0; i < numFigs; ++i)
    {
        figs[i] = myPolygon(feeg[i], i);
        figTypes = feeg[i];
//        std::cout << feeg[i] << std::endl;
    }

    int a = distrAns(gen);
    ans = a;

    addPieces();

}

void Picture::addPieces()
{
    switch(ans)
    {
    case 1:
    {
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
    {
        break;
    }
    }
}

void Picture::draw(const QString &outPath)
{
    QPixmap pic(width, height);
    pic.fill("white");
    QPainter pnt;
    pnt.begin(&pic);

    pnt.setPen(color);
    pnt.setBrush(QBrush(color));
    const int fontSize = 36;
    pnt.setFont(QFont("Arial", fontSize));
    for(int i = 0; i < numFigs; ++i)
    {
        pnt.drawPolygon(figs[i]);
        pnt.drawText(figX[i] * width - fontSize / 3,
                     numY * height,
                     QString::number(i + 1));
    }

    pic.save(outPath, nullptr, 100);
}

// return number of pieces
int getPieces(int type, int var)
{
    switch(type)
    {
    case 0:
    {
        /// square
        break;
    }
    case 1:
    {
        /// rect
        break;
    }
    case 2:
    {
        /// triange
        break;
    }
    case 3:
    {
        /// rhomb
        break;
    }
    case 4:
    {
        /// trapeze
        break;
    }
    case 5:
    {
        /// paral
        break;
    }
    case 6:
    {
        /// penta
        break;
    }
    case 7:
    {
        /// hexa
        break;
    }
    default:
    {
        break;
    }
    }

}

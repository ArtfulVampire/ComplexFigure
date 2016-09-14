#include "picture.h"

Picture::Picture()
{

}

QPolygon Picture::myPolygon(int type, int num)
{

    QVector<QPoint> vec2;
    for(const QPointF p : fig::figures[type])
    {
        vec2.push_back(QPoint(figX[num] * width + p.x() * fig::size,
                              figY * height + p.y() * fig::size));
    }
    return QPolygon(vec2);

}

void Picture::compose()
{
//    std::default_random_engine gen;
    std::random_device gen;
    std::uniform_int_distribution<int> distrAns(1, 3);
    /// 8 with hexagon
    std::vector<int> feeg(8);

    std::iota(std::begin(feeg), std::end(feeg), 0);
    std::shuffle(std::begin(feeg), std::end(feeg), std::random_device{});

    for(int i = 0; i < numFigs; ++i)
    {
        figs[i] = myPolygon(feeg[i], i);
        figTypes[i] = feeg[i];
        std::cout << feeg[i] << std::endl;
    }

    int a = distrAns(gen);
    ans = a;

    addPieces();

}

void Picture::addPieces()
{

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

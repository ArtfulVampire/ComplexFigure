#include "picture.h"

QString rightNumber(const int input, int N) // prepend zeros
{
	QString h;
	h.setNum(input);
	h.prepend(QString(N, '0'));
	return h.right(N);
}

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
    std::uniform_int_distribution<int> distrAns(0, 2);
    /// 8 with hexagon
    std::vector<int> feeg(8);

    std::iota(std::begin(feeg), std::end(feeg), 0);
	std::shuffle(std::begin(feeg), std::end(feeg),
				 std::default_random_engine(
					 std::chrono::system_clock::now().time_since_epoch().count()));

    for(int i = 0; i < numFigs; ++i)
    {
        figs[i] = myPolygon(feeg[i], i);
        figTypes[i] = feeg[i];
//        std::cout << feeg[i] << std::endl;
    }

    int a = distrAns(gen);
    ans = a;
}


void Picture::draw(const QString & outDir)
{

    QPixmap pic(width, height);
    pic.fill("black");
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

    std::random_device gen;
    auto distrVar = std::uniform_int_distribution<int>{0, fig::pieces[figTypes[ans]].size() - 1};
    int var = distrVar(gen);
    int numOfPieces = fig::pieces[figTypes[ans]][var].size();
    const std::vector<double> * pieceX;
    if(numOfPieces == 3)
    {
        pieceX = &pieceX_3;
    }
    else if(numOfPieces == 4)
    {
        pieceX = &pieceX_4;
    }

	const std::vector<double> * pieceY;
	if(numOfPieces == 3)
	{
		pieceY = &pieceY_3;
	}
	else if(numOfPieces == 4)
	{
		pieceY = &pieceY_4;
	}

    std::cout << "ans = " << ans + 1 << std::endl;
    std::cout << "var = " << var << std::endl;
    std::cout << "numOfPieces = " << numOfPieces << std::endl;

    int num = 0;
    srand(time(NULL));
	auto localPieces = fig::pieces[figTypes[ans]][var];
	std::shuffle(std::begin(localPieces), std::end(localPieces),
				 std::default_random_engine(
					 std::chrono::system_clock::now().time_since_epoch().count()));
	for(QVector<QPointF> v : localPieces)
    {
        QVector<QPoint> vec2;

        QTransform rotat;
        double angle = 15 * (rand() % 8);
        rotat.rotate(angle);
        std::for_each(std::begin(v), std::end(v),
                      [&rotat](QPointF & in)
        {

            in = rotat.map(in);
        });


        /// calc translate
        double low = v[0].y();
        double centX = 0;
        std::for_each(std::begin(v), std::end(v),
                      [&low, &centX](const QPointF & in)
        {
            low = std::max(low, in.y());
            centX += in.x();
        });
        centX /= v.size();

        for(const QPointF p : v)
        {
            vec2.push_back(QPoint((*pieceX)[num] * width + (p.x() - centX) * fig::pieceSize,
								  (*pieceY)[num] * height + (p.y() - low) * fig::pieceSize));
//            std::cout << vec2.back().x() << "\t" << vec2.back().y() << std::endl;
        }
        ++num;
//        std::cout << std::endl;
        pnt.drawPolygon(QPolygon(vec2));
    }


    pnt.end();
	static int figNum = 100;
    QString outPath = outDir + "/complexFigure"
					  + "_" + rightNumber(figNum++, 3)
					  + "_ans_" + QString::number(ans + 1)
                      + ".jpg";

    pic.save(outPath, nullptr, 100);
}

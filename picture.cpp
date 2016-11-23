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

void Picture::compose(int figTyp,
					  int varNum)
{
	figs[0] = myPolygon(8, 0);
	figs[1] = myPolygon(figTyp, 1);
	figs[2] = myPolygon(8, 2);

	figTypes[0] = 8;
	figTypes[1] = figTyp;
	figTypes[2] = 8;

	ans = 1;
	varSlice = varNum;
}

void Picture::drawSlices(const QString & path)
{
	Picture p;
	for(int i = 0; i < 8; ++i) /// figTypes
	{
		for(int j = 0; j < fig::pieces[i].size(); ++j)
		{
//			std::cout << fig::pieces.size() << '\t' << fig::pieces[0].size() << std::endl;
//			exit(0);
			p.compose(i, j);
			p.draw(path,
				   false,
				   false);
		}
	}
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
	/// 8 with hexagon, without empty
    std::vector<int> feeg(8);

    std::iota(std::begin(feeg), std::end(feeg), 0);
	std::shuffle(std::begin(feeg), std::end(feeg),
				 std::default_random_engine(
					 std::chrono::system_clock::now().time_since_epoch().count()));

    for(int i = 0; i < numFigs; ++i)
    {
        figs[i] = myPolygon(feeg[i], i);
        figTypes[i] = feeg[i];
    }


	std::random_device randDev;
	auto distrAns = std::uniform_int_distribution<int>{0, 2};
	ans = distrAns(randDev);

	auto distrVar = std::uniform_int_distribution<int>{0, fig::pieces[figTypes[ans]].size() - 1};
	varSlice = distrVar(randDev);
}


void Picture::draw(const QString & outDir, bool rotateFlag, bool mixFlag)
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


	int numOfPieces = fig::pieces[figTypes[ans]][varSlice].size(); /// always 4 now
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
	std::cout << "var = " << varSlice << std::endl;
    std::cout << "numOfPieces = " << numOfPieces << std::endl;

    int num = 0;
    srand(time(NULL));
	auto localPieces = fig::pieces[figTypes[ans]][varSlice];
	if(mixFlag)
	{
		std::shuffle(std::begin(localPieces), std::end(localPieces),
					 std::default_random_engine(
						 std::chrono::system_clock::now().time_since_epoch().count()));
	}
	for(QVector<QPointF> v : localPieces)
    {
        QVector<QPoint> vec2;


        QTransform rotat;
		double angle = 0;
		if(rotateFlag)
		{
			angle = 15 * (rand() % 8);
		}
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
		std::cout << 1 << std::endl;
        ++num;
//        std::cout << std::endl;
		pnt.drawPolygon(QPolygon(vec2));
    }


    pnt.end();
	static int figNum = 0;
    QString outPath = outDir + "/complexFigure"
					  + "_" + rightNumber(figNum++, 3)
					  + "_ans_" + QString::number(ans + 1)
                      + ".jpg";

    pic.save(outPath, nullptr, 100);
}

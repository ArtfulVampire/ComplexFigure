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

void Picture::composeExample(int figTyp,
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
			p.composeExample(i, j);
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

void Picture::composeExample()
{
	/// set:
	/// ans - number of correct figure
	/// varSlice - variant of pieces
	/// figTypes - other figures
	/// figs - polygons

	std::vector<int> feeg(8);

	std::iota(std::begin(feeg), std::end(feeg), 0);
	std::shuffle(std::begin(feeg), std::end(feeg),
				 std::default_random_engine(
					 std::chrono::system_clock::now().time_since_epoch().count()));

	for(int i = 0; i < numFigs; ++i)
	{
		figTypes[i] = feeg[i];
		figs[i] = myPolygon(feeg[i], i);
	}

	std::random_device randDev;
	auto distrAns = std::uniform_int_distribution<int>{0, 2};
	ans = distrAns(randDev);

	int numVars = fig::pieces[figTypes[ans]].size() - 1;
	auto distrVar = std::uniform_int_distribution<int>{0, numVars};
	varSlice = distrVar(randDev);
}

bool Picture::composeNew(int answerType, int inVarSlice)
{
	/// set:
	/// ans - number of correct figure
	/// varSlice - variant of pieces
	/// figTypes - other figures
	/// figs - polygons

	std::random_device randDev;
	auto distrAns = std::uniform_int_distribution<int>{0, 2};
	ans = distrAns(randDev);

	if(inVarSlice >= fig::pieces[answerType].size()) { return false; }
	else { varSlice = inVarSlice; }

	std::vector<int> feeg;
	for(int i = 0; i < 8; ++i)
	{
		if(i == answerType) { continue; }
		/// triangle and square forbid
		else if((answerType == 2 && i == 0) || (answerType == 0 && i == 2)) { continue; }
		else feeg.push_back(i);
	}
	std::shuffle(std::begin(feeg), std::end(feeg),
				 std::default_random_engine(
					 std::chrono::system_clock::now().time_since_epoch().count()));

	/// answer
	figTypes[ans] = answerType;
	figs[ans] = myPolygon(answerType, ans);
	/// another one
	figTypes[(ans + 1) % 3] = feeg[0];
	figs[(ans + 1) % 3] = myPolygon(feeg[0], (ans + 1) % 3);
	/// another two
	figTypes[(ans + 2) % 3] = feeg[1];
	figs[(ans + 2) % 3] = myPolygon(feeg[1], (ans + 2) % 3);



	return true;
}

void Picture::draw(const QString &outDir, bool rotateFlag, bool mixFlag)
{
	static int figNum = 1; /// start num of file

	QString outPath = outDir + "/cf_"
					  + rightNumber(figNum++, 3)
//					  + "_ans_" + QString::number(ans + 1)
					  + ".jpg";

	this->drawPic(rotateFlag, mixFlag).save(outPath, nullptr, 100);
}

QPixmap Picture::drawPic(bool rotateFlag, bool mixFlag)
{
	const double angleStep = 30;
    QPixmap pic(width, height);

//	pic.fill("green"); // debug
	pic.fill("black"); // release
    QPainter pnt;
    pnt.begin(&pic);
    pnt.setPen(color);
    pnt.setBrush(QBrush(color));

    const int fontSize = 36;
    pnt.setFont(QFont("Arial", fontSize));

	/// draw answer variants
    for(int i = 0; i < numFigs; ++i)
    {
        pnt.drawPolygon(figs[i]);
        pnt.drawText(figX[i] * width - fontSize / 3,
                     numY * height,
                     QString::number(i + 1));
    }


	int numOfPieces = fig::pieces[figTypes[ans]][varSlice].size(); /// always 4 now
	/// set (x, y) for pieces
    const std::vector<double> * pieceX;
	const std::vector<double> * pieceY;
    if(numOfPieces == 3)
    {
        pieceX = &pieceX_3;
		pieceY = &pieceY_3;
    }
    else if(numOfPieces == 4)
    {
        pieceX = &pieceX_4;
		pieceY = &pieceY_4;
	}

//	std::cout << "ans = " << ans + 1 << std::endl;
//	std::cout << "var = " << varSlice << std::endl;
//	std::cout << "numOfPieces = " << numOfPieces << std::endl;

	int num = 0;
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
			angle = angleStep * (rand() % 8);
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
		++num;
		pnt.drawPolygon(QPolygon(vec2));
    }


	pnt.end();
	return pic;
}

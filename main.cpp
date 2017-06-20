#include <QApplication>
#include "picture.h"
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	/// draw answers
//	Picture::drawSlices("/media/Files/Pictures/vars");
//	return 0;


    Picture peec;
	/// full random
//	for(int i = 0; i < 300; ++i)
//	{
//		peec.compose();
//		peec.draw("/media/Files/Pictures/NewCF");
//	}

	/// not full random
//	for(int fig = 0; fig < 8; ++fig)
//	{
//		for(int var = 0; var < 10; ++var)
//		{
//			if(peec.composeNew(fig, var))
//			{
//				peec.draw("/media/Files/Pictures/NewestCF");
//			}
//		}
//	}

	/// 0-19 means first and second exp
	/// 20-39 means second and third exp
	/// 40-59 means third and first exp
	std::vector<int> whichPair(3, 0);

	std::random_device randDev;
	auto distrAns = std::uniform_int_distribution<int>{0, 2};

	const QString prePath = "/media/Files/Pictures/NewestCF/cf_";
	int pairVariant = 0;

	for(int fig = 0; fig < 8; ++fig)
	{
		for(int var = 0; var < 10; ++var)
		{
			if(!peec.composeNew(fig, var)) { continue; }
			do
			{
				pairVariant = distrAns(randDev);

			} while(whichPair[pairVariant] == 20);
			whichPair[pairVariant]++;

			int num1 = pairVariant * 40 + whichPair[pairVariant] + whichPair[(pairVariant + 2) % 3];
			int num2 = ((pairVariant + 1) % 3) * 40 + whichPair[pairVariant] + whichPair[(pairVariant + 1) % 3];

			std::cout << pairVariant << "\t" << num1 << "\t" << num2
					  << "\t" << "wp = " << whichPair[0] << "\t" << whichPair[1] << "\t" << whichPair[2]
					  << "\t";

			std::cout << "1 OK\t";
			peec.drawPic("/media/Files/Pictures/NewestCF").save(
						prePath + QString::number(num1) + ".jpg");
			peec.composeNew(fig, var);
			std::cout << "2 OK\t";
			peec.drawPic("/media/Files/Pictures/NewestCF").save(
						prePath + QString::number(num2) + ".jpg");

			std::cout << std::endl;

			if(whichPair == std::vector<int>(3, 20))
			{
				std::cout << "finished" << std::endl;
				return 0;
			}
		}
	}


    return 0;
}

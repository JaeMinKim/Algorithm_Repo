#include <iostream>
#include <map>

using namespace std;

#define RECT_POINT_CNT	4

int main()
{
	map<int, int> pointX;
	map<int, int> pointY;
	map<int, int>::iterator iter;
	int runCnt = 0;

	cin>> runCnt;

	for (int run=0; run<runCnt; ++run)
	{
		for (int i=0; i<(RECT_POINT_CNT-1); i++)
		{
			int tmpX = 0, tmpY = 0;

			cin>> tmpX>> tmpY;

			if (pointX.find(tmpX) == pointX.end())    pointX[tmpX] = 0;
			if (pointY.find(tmpY) == pointY.end())    pointY[tmpY] = 0;

			pointX[tmpX]++;
			pointY[tmpY]++;
		}

		for (iter=pointX.begin(); iter!=pointX.end(); ++iter)
			if (iter->second == 1)    cout<< iter->first<< " ";

		for (iter=pointY.begin(); iter!=pointY.end(); ++iter)
			if (iter->second == 1)    cout<< iter->first<< endl;

		pointX.clear();
		pointY.clear();
	}

	return 0;
}

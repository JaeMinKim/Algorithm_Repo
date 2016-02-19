#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point
{
	private:
		double _x;
		double _y;
	public:
		Point(double x, double y) : _x(x), _y(y) {}
		double getX() { return _x; }
		double getY() { return _y; }

		Point operator+(const Point& p)
		{
			Point tmpPoint(_x + p._x, _y + p._y);
			return tmpPoint;
		}
};

class Circul
{
	protected:
		Point _p;
		double _rd;
	public:
		Circul(double x, double y, double rd) : _rd(rd), _p(x, y) {}
		bool isCircumference(double x, double y);
};

bool Circul::isCircumference(double x, double y)
{
	double result = 0;

	//(x - _p.getX())^2 + (y - _p.getY())^2 = _rd^2
	result = pow( (x - _p.getX()), 2.0 ) + pow( (y - _p.getY()), 2.0  );
	if ( result == pow(_rd, 2.0) )
			return true;

	return false;
}

class Obstacle : public Circul
{
	private:
		static vector<Obstacle*> obsList;

	public:
		Obstacle(int x, int y, int rd) : Circul(x, y, rd) {}
		bool isMeet(int x, int y) { return isCircumference(x, y); }
		void addObs()
		{
			obsList.push_back(this);
		}
		static int checkObsMeetFromList(int x, int y)
		{
			int idx = 0;

			for( idx=0; idx<obsList.size(); idx++ )
			{
				if (obsList[idx]->isMeet(x, y))
					return idx;
			}

			return -1;
		}
};
vector<Obstacle*> Obstacle::obsList;

class Ball
{
	private:
		Point _currPoint;
		Point _vector;
	public:
		Ball(Point currPoint, Point vector) : _currPoint(currPoint), _vector(vector) {}
		Point getNextPoint();
};





int main()
{




#if 0
	Obstacle o1(0, 0, 4);
	Obstacle o2(0, 0, 2);

	o1.addObs();
	o2.addObs();

	cout<< Obstacle::checkObsMeetFromList(0, 2)<< endl;
	cout<< Obstacle::checkObsMeetFromList(2, 2)<< endl;
#endif
}

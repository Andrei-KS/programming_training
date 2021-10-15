#ifndef __POINT_H__
#define __POINT_H__

class Point
{
public:
	virtual ~Point();
	Point(double x, double y);
	double GetX() const { return itsX; }
	double GetY() const { return itsY; }
	void SetX(double x);
	void SetY(double y);

private:
	double itsX;
	double itsY;
};

#endif //!__POINT_H__
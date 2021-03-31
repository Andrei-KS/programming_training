#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Shape.h"
#include "Point.h"

class Square : public Shape
{
public:
	virtual ~Square();
	Square();
	Square(const Point& center, double sideLength);
	Point GetCenter() const { return itsCenter; }
	double GetSideLenght()const { return itSideLength; }
	void SetCenter(const Point& center);
	void SetSideLength(const double sideLength);
	virtual void draw() override;

private:
	Point itsCenter;
	double itSideLength;
};

#endif // !__SQUARE_H__

#include "Point.h"

Point::~Point()
{
}

Point::Point(double x, double y)
	: itsX(x)
	, itsY(y)
{
}

void Point::SetX(double x)
{
	itsX = x;
}

void Point::SetY(double y)
{
	itsY = y;
}

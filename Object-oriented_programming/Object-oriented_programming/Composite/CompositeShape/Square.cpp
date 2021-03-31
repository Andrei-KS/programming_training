

#include "Square.h"
#include <iostream>

Square::~Square()
{
}

Square::Square()
	: itsCenter(Point(0,0))
	, itSideLength(0)
{
}

Square::Square(const Point& center, double sideLength)
	: itsCenter(center)
	, itSideLength(sideLength)
{
}

void Square::SetCenter(const Point& center)
{
	itsCenter = center;
}

void Square::SetSideLength(const double sideLength)
{
	itSideLength = sideLength;
}

void Square::draw()
{
	std::cout << "draw Square : {" << itsCenter.GetX() << ", " << itsCenter.GetY() << "} SL = " << itSideLength << std::endl;
}



#include "Circle.h"
#include <iostream>

Circle::~Circle()
{
}

Circle::Circle()
	: itsCenter(Point(0,0))
	, itsRadius(0)
{
}

Circle::Circle(const Point& center, double radius)
	: itsCenter(center)
	, itsRadius(radius)
{
}

void Circle::SetCenter(const Point& center)
{
	itsCenter = center;
}

void Circle::SetRadius(const double radius)
{
	itsRadius = radius;
}

void Circle::draw()
{
	std::cout << "draw Circle : {" << itsCenter.GetX() << ", " << itsCenter.GetY() << "} R = " << itsRadius << std::endl;
}

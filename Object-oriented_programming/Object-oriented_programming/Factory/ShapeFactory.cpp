

#include "ShapeFactory.h"
#include "Circle.h"
#include "Square.h"

Shape* ShapeFactory::makeCircle()
{
	return new Circle();
}

Shape* ShapeFactory::makeSquare()
{
	return new Square();
}

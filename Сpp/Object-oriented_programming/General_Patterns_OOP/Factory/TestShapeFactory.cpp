

#include "TestShapeFactory.h"
#include "ShapeFactory.h"
#include "MathConstants.h"

#include "Shape.h"
#include "Circle.h"
#include "Square.h"

#include <iostream>
#include <cassert>

void TestShapeFactory::TestShapeFactory()
{
	TestMakeCircle();
	TestMakeSquare();
}

void TestShapeFactory::TestMakeCircle()
{
	std::cerr << "TestMakeCircle" << std::endl;
	ShapeFactory sf;
	Shape* s = sf.make("Circle");
	assert(s);
	Circle* c = dynamic_cast<Circle*>(s);
	assert(c);
	c->SetRadius(5);
	assert(c->GetArea() == 5.0*5.0*MathConstants::PI);
}

void TestShapeFactory::TestMakeSquare()
{
	std::cerr << "TestMakeSquare" << std::endl;
	ShapeFactory sf;
	Shape* s = sf.make("Square");
	assert(s);
	Square* sq = dynamic_cast<Square*>(s);
	assert(sq);
	sq->SetSideLength(5);
	assert(sq->GetArea() == 5.0*5.0);
}

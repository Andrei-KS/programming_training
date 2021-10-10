

#include "TestCompositeShape.h"
#include "Circle.h"
#include "CompositeShape.h"
#include "Shape.h"
#include "Square.h"
#include <memory>
#include <iostream>

void TestCompositeShape::TestCompositeShape()
{
	CompositeShape cs;
	cs.add(std::make_unique<Circle>(Point(0, 0), 1));
	cs.add(std::make_unique<Circle>(Point(1, 0), 1));
	cs.add(std::make_unique<Circle>(Point(0, 1), 1));
	cs.add(std::make_unique<Square>(Point(0, 0), 2));
	cs.draw();
	std::cout << std::endl;
	cs.clear();
	cs.draw();
}

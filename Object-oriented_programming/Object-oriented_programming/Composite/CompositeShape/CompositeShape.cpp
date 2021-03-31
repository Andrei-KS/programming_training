

#include "CompositeShape.h"

CompositeShape::CompositeShape()
	: itsShapes(std::vector<std::unique_ptr<Shape>>())
{
}

CompositeShape::~CompositeShape()
{
	clear();
}

void CompositeShape::clear()
{
	for (std::vector<std::unique_ptr<Shape>>::iterator it = itsShapes.begin(); it != itsShapes.end(); it++)
	{
		(*it).reset();
	}
	itsShapes.clear();
}

void CompositeShape::add(std::unique_ptr<Shape> s)
{
	itsShapes.push_back(std::move(s));
}

void CompositeShape::draw()
{
	for (std::vector<std::unique_ptr<Shape>>::iterator it = itsShapes.begin(); it != itsShapes.end(); it++)
	{
		(*it)->draw();
	}
}

#ifndef __COMPOSITESHAPE_H__
#define __COMPOSITESHAPE_H__

#include "Shape.h"
#include <vector>
#include <memory>

class CompositeShape : public Shape
{
public:
	CompositeShape();
	~CompositeShape();
	void clear();
	void add(std::unique_ptr<Shape> s);
	virtual void draw() override;

private:
	std::vector<std::unique_ptr<Shape>> itsShapes;

};

#endif // !__COMPOSITESHAPE_H__
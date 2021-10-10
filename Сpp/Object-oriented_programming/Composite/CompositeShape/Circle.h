#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
	virtual ~Circle();
	Circle();
	Circle(const Point& center, double radius);
	Point GetCenter() const { return itsCenter; }
	double GetRadius() const { return itsRadius; }
	void SetCenter(const Point& center);
	void SetRadius(const double radius);
	virtual void draw() override;

private:
	Point itsCenter;
	double itsRadius;
};

#endif //!__CIRCLE_H__
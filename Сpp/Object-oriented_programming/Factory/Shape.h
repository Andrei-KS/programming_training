#ifndef __SHAPE_H__
#define __SHAPE_H__

class Shape
{
public:
	virtual ~Shape() {};
	Shape() {};
	virtual double GetArea() const = 0;
};

#endif // !__SHAPE_H__
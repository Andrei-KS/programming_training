#ifndef __SHAPEFACTORY_H__
#define __SHAPEFACTORY_H__

class Shape;

class ShapeFactory
{
public:
	Shape* makeCircle();
	Shape* makeSquare();
};

#endif // !__SHAPEFACTORY_H__
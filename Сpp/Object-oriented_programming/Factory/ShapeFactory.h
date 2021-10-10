#ifndef __SHAPEFACTORY_H__
#define __SHAPEFACTORY_H__

#include <string>
#include <exception>

class ShapeFactoryException : public std::exception
{
public:
	virtual const char* what() const throw();
	ShapeFactoryException(std::string message);
private:
	std::string itsMessage;
};

class Shape;

class ShapeFactory
{
public:
	Shape* make(std::string shapeName) throw(std::exception);
};

#endif // !__SHAPEFACTORY_H__
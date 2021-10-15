

#include "ShapeFactory.h"
#include "Circle.h"
#include "Square.h"

Shape* ShapeFactory::make(std::string shapeName) throw(std::exception)
{
	if (shapeName == "Circle")
	{
		return new Circle();
	}
	else if(shapeName == "Square")
	{
		return new Square();
	}
	else
	{
		throw ShapeFactoryException("ShapeFactory cannot creat " + shapeName);
	}
}

const char* ShapeFactoryException::what() const throw()
{
	return itsMessage.c_str();
}

ShapeFactoryException::ShapeFactoryException(std::string message)
	: itsMessage(message)
{
}

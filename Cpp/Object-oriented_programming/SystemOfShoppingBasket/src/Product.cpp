

#include "Product.h"
#include "..\include\Product.h"

Product::Product(const std::string& name, int price)
	: itsPrice(price)
	, itsName(name)
{
}

int Product::getPrice() const
{
	return itsPrice;
}

std::string Product::getName() const
{
	return itsName;
}

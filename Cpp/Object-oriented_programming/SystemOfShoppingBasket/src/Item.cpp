

#include "Item.h"
#include "Product.h"

Item::Item(Product p, int quantity)
	: itsProduct(p)
	, itsQuantity(quantity)
{
}

Product Item::getProduct() const
{
	return itsProduct;
}

int Item::getQuantity() const
{
	return itsQuantity;
}


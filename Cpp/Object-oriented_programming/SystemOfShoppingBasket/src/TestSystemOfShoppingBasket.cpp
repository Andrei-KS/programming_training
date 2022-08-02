

#include "TestSystemOfShoppingBasket.h"
#include <cassert>
#include "Order.h"
#include "Product.h"

void TestSystemOfShoppingBasket::execute()
{
	testOrderPrice();
}

void TestSystemOfShoppingBasket::testOrderPrice()
{
	Order* o = new Order("Bob");
	Product* toothpaste = new Product("Toothpaste", 129);
	o->addItem(*toothpaste, 1);
	assert(129 == o->total());
	Product* mouthwash = new Product("Mouthwash", 342);
	o->addItem(*mouthwash, 2);
	assert(813 == o->total());
}

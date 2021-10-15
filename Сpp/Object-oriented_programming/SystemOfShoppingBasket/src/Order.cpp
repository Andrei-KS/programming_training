

#include "Order.h"
#include "Item.h"
#include "Product.h"

Order::Order(std::string cusid)
	: itsCustomerId(cusid)
	, itsItems(std::vector<Item*>())
{
}

Order::~Order()
{
	for (std::vector<Item*>::iterator it = itsItems.begin(); it != itsItems.end(); it++)
	{
		delete (*it);
	}
	itsItems.clear();
}

void Order::addItem(Product p, int qty)
{
	Item* item = new  Item(p, qty);
	itsItems.push_back(item);
}

int Order::total()
{
	int SumOrder = 0;
	for (std::vector<Item*>::iterator it = itsItems.begin(); it != itsItems.end(); it++)
	{
		SumOrder += (*it)->getProduct().getPrice() * (*it)->getQuantity();
	}
	return SumOrder;
}

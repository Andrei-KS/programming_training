#ifndef __ORDER_H__
#define __ORDER_H__

#include <vector>
#include <string>

class Item;
class Product;
/**
* Description of Order.
*
* This class contains information about order
* @see Product, Item
* @version 0.1
*/
class Order
{
public:
	/**
	* Ñonstructor for creating a new order
	* @param cusid - customer id
	*/
	Order(std::string cusid);
	
	/**
	* destructor for created the order
	*/
	~Order();

	/**
	* Function adds a new item to order
	* @param p - object corresponding to the product
	* @param qty - quantity of products
	* @see Item, Product
	*/
	void addItem(Product p, int qty);

	/**
	* Function return whole sum order
	* @return whole sum order
	*/
	int total();

private:
	/**
	* items`s field
	* @see Item
	*/
	std::vector<Item*> itsItems;

	/**
	* customer`s id field
	*/
	std::string itsCustomerId;
};

#endif // !__ORDER_H__
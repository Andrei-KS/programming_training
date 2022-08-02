#ifndef __ITEM_H__
#define __ITEM_H__

#include "Product.h"

class Product;
/**
* Description of Item.
*
* This class contains information about one item in the order
* 
* @see Product, Order
* @version 0.1
*/
class Item
{
public:
	/**
	* Ñonstructor for creating a new item
	* @papram p - object corresponding to the product
	* @param quantity - quantity of products
	* @see Product
	*/
	Item(Product p, int quantity);

	/**
	* Function returns the object corresponding to the product
	* @return object corresponding to the product
	* @see Product
	*/
	Product getProduct() const;
	
	/**
	* Function returns the quantity of the product
	* @return quantity`s products
	*/
	int getQuantity() const;

private:
	/**
	* product field
	* @see Product
	*/
	Product itsProduct;

	/**
	* quantity`s products field
	*/
	int itsQuantity;
};

#endif // !__ITEM_H__
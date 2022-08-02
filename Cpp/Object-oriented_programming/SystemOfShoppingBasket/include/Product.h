#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <string>

/** 
* Description of Product.
* 
* This class contains information about product
* 
* @version 0.1
*/
class Product
{
public:
	/**
	* Ñonstructor for creating a new product
	* @param name - product`s name
	* @param price - price of one unit of product
	*/
	Product(const std::string& name, int price);
	
	/**
	* Function returns the price of one unit of product
	* @return price of one unit of product
	*/
	int getPrice() const;
	
	/**
	* Function returns the name of the product
	* @return Product`s name
	*/
	std::string getName() const;

private:
	/**
	* price field 
	*/
	int itsPrice;

	/**
	* Product`s name field
	*/
	std::string itsName;
};

#endif // !__PRODUCT_H__
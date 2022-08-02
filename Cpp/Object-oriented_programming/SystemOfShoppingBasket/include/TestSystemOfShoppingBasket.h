#ifndef __TESTSYSTEMOFSHOPPINGBASKET_H__
#define __TESTSYSTEMOFSHOPPINGBASKET_H__

/**
* Description of TestSystemOfShoppingBasket.
* 
* This is class contains tests for Order, Item and Product classes
* @see Order, Item, Product
* @version 0.1
*/
class TestSystemOfShoppingBasket
{
public:
	/**
	* Main function to start tests
	*/
	void execute();

protected:
	/**
	* Function checks correct work of calculate whole sum orders
	*/
	void testOrderPrice();
};

#endif // !__TESTSYSTEMOFSHOPPINGBASKET_H__
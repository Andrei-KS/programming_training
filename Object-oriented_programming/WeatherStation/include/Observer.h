#ifndef __OBSERVER_H__
#define __OBSERVER_H__

/**
* Description of class inteface Observer
* 
* This interface contain a polymorphic update function that called when Observable is changed
* 
* @see pattern Observer, Observable
*/
class Observer
{
public:
	/**
	* Destructor for created the TemperatureSensor
	*/
	virtual ~Observer() {}
	
	/**
	* This function is activated when Observable is changed
	* @param value - the value obtained from the observed subject 
	* @see Observable
	*/
	virtual void update(double value) = 0;
};

#endif // !__OBSERVER_H__
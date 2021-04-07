#ifndef __OBSERVABLE_H__
#define __OBSERVABLE_H__

#include "Observer.h"
#include <vector>

/**
* Description of class Observable
* 
* Observable registers observers and if it changes then notifies all registered observers 
* 
* @see pattern Observer, Observer
*/
class Observable
{
public:
	/**
	* Constructor for creating a new defualt Observable
	*/
	Observable();

	/**
	* Destructor for created the TemperatureSensor
	*/
	~Observable();

	/**
	* Observer registration function
	* @param observer - registered observer 
	*/
	void registerObserver(Observer* observer);

protected:
	/**
	* function to notify all registered observers
	* @param value - value passed to registered observers 
	*/
	void notifyObservers(double value);

private:
	/**
	* the field containing all registered observers 
	*/
	std::vector<Observer*> itsObservers;
};

#endif // !__OBSERVABLE_H__
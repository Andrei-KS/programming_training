

#include "Observable.h"

Observable::Observable()
	: itsObservers(std::vector<Observer*>())
{
}

Observable::~Observable()
{
	itsObservers.clear();
}

void Observable::registerObserver(Observer* observer)
{
	itsObservers.push_back(observer);
}

void Observable::notifyObservers(double value)
{
	for (std::vector<Observer*>::iterator it = itsObservers.begin(); it != itsObservers.end(); it++)
	{
		(*it)->update(value);
	}
}

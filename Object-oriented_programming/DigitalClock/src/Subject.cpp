

#include "Subject.h"

Subject::Subject()
	: itsObservers(std::vector<Observer*>())
{
}

Subject::~Subject()
{
	itsObservers.clear();
}

void Subject::registerObserver(Observer* observer)
{
	itsObservers.push_back(observer);
}

void Subject::notifyObservers()
{
	for (std::vector<Observer*>::iterator it = itsObservers.begin(); it != itsObservers.end(); it++)
	{
		(*it)->update();
	}
}

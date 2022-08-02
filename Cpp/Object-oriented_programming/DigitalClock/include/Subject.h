#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "Observer.h"
#include <vector>

class Subject
{
public:
	Subject();
	~Subject();
	void registerObserver(Observer* observer);

protected:
	void notifyObservers();

private:
	std::vector<Observer*> itsObservers;
};

#endif // !__SUBJECT_H__
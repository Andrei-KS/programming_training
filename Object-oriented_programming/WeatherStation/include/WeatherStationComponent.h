#ifndef __WEATHERSTATIONCOMPONENT_H__
#define __WEATHERSTATIONCOMPONENT_H__

class Observer;

/**
* 
*/
class WeatherStationComponent
{
public:
	/**
	* add Temperature Observer
	* @param - pointer to Observer
	*/
	virtual void addTempObserver(Observer* o) = 0;

	/*
	* add Barometric Pressure Observer
	* @param - pointer to Observer
	*/
	virtual void addBPObserver(Observer* o) = 0;

	/**
	* add Barometric Pressure Trend Observer
	* @param - pointer to Observer
	*/
	virtual void addBPTObserver(Observer* o) = 0;
};

#endif // !__WEATHERSTATIONCOMPONENT_H__
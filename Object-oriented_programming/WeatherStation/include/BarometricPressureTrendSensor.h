#ifndef __BAROMETRICPRESSURETRENDSENSOR_H__
#define __BAROMETRICPRESSURETRENDSENSOR_H__

#include "Observer.h"
#include "Observable.h"
#include <vector>
class BarometricPressureSensor;
/**
* Description of class BarometricPressureTrendSensor
* 
* It is observer of BarometricPressureSensor that calculate trend changing pressure
* the trend has three states: rise, decrease, stable 
* Rule of changing trend: 
* if the pressure rises or falls or falls at a rate of at least 0.06 inches per hour
* and changes by a total of 0.02 inches or more over the observation time (every three times),
* the change in pressure must be reported
*
* @see Observer, BarometricPressureSensor
*/
class BarometricPressureTrendSensor : public Observer, public Observable
{
public:
	/**
	* Constructor for creating a new BarometricPressureTrendSensor associated with the BarometricPressureSensor
	* @param bps - BarometricPressureSensor which will be associated with this object 
	*/
	BarometricPressureTrendSensor(BarometricPressureSensor* bps);

	/**
	* This function is activated when Observable is changed
	* @param value - the value obtained from the observed subject
	* @see Observable
	*/
	virtual void update(double value) override;

protected:

private:
	int itsCurIndex;
	std::vector<double> itsPressure;
	double itsSumAllLastValuesPressure;
};

#endif // !__BAROMETRICPRESSURETRENDSENSOR_H__
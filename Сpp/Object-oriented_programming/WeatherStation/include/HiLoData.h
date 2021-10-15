#ifndef __HILODATA_H__
#define __HILODATA_H__

/**
* This class is abstract interface of algorithm
* that determine High and Low value for every day
*/
class HiLoData
{
public:
	/**
	* Pass the current value to perform the calculation
	* @param value - current value
	* @param time - current time
	*/
	virtual void currentReading(double value, long time) = 0;

	/**
	* Pass the current value to perform the calculation at the beginning of the day
	* @param initial - current value
	* @param time - current time
	*/
	virtual void newDay(double initial, long time) = 0;

	/**
	* @return high value at current moment
	*/
	virtual double getHighValue() = 0;

	/**
	* @return a time of high value at current moment
	*/
	virtual long getHighTime() = 0;

	/**
	* @return low value at current moment
	*/
	virtual double getLowValue() = 0;

	/**
	* @return a time of low value at current moment
	*/
	virtual long getLowTime() = 0;
};

#endif // !__HILODATA_H__
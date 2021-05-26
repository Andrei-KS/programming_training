#ifndef __HILODATAIMP_H__
#define __HILODATAIMP_H__

#include "HiLoData.h"
#include <string>

class PersistentImp;
class Date;
class StationToolkit;

/**
* 
*/
class HiLoDataImp : public HiLoData
{
public:
	/**
	* 
	*/
	enum class Type
	{
		None = 0,
		Temperature = 1,
		MaxNumber
	};

	/**
	* 
	*/
	HiLoDataImp(StationToolkit* st, Type type, Date theDate, double init, long initTime);
	
	/**
	* @return high value at current moment
	*/
	virtual double getHighValue() override;

	/**
	* @return a time of high value at current moment
	*/
	virtual long getHighTime() override;

	/**
	* @return low value at current moment
	*/
	virtual double getLowValue() override;

	/**
	* @return a time of low value at current moment
	*/
	virtual long getLowTime() override;

	/**
	* Pass the current value to perform the calculation. 
	* Determines if the reading has changed the highest or lowest value
	* @param value - current value
	* @param time - current time
	*/
	virtual void currentReading(double value, long time) override;

	/**
	* Pass the current value to perform the calculation at the beginning of the day
	* @param initial - current value
	* @param time - current time
	*/
	virtual void newDay(double initial, long time) override;

private:
	/**
	* saves data to persistent storage defined by itsPI (PersistentImp*)
	* @see PersistentImp
	*/
	void store();

	/**
	* calculates a new key value from the date and internal parameters of this class: itsType
	* @param date - the date by which the key will be calculated
	*/
	void calculateStorageKey(const Date& date);

	/**  */
	double itsLowValue;
	/**  */
	long itsLowTime;
	/**  */
	double itsHightValue;
	/**  */
	long itsHightTime;
	/**  */
	Type itsType;

	/** Ñomputed storage key */
	std::string* itsStorageKey;
	/** Ñontains a class responsible for saving data */
	PersistentImp* itsPI;
};

#endif // !__HILODATAIMP_H__
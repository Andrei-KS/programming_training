#ifndef __HILODATA_H__
#define __HILODATA_H__

/**
* 
*/
class HiLoData
{
public:
	/**
	* 
	*/
	virtual void currentReading(double value, long time) = 0;

	/**
	* 
	*/
	virtual void newDay(double initial, long time) = 0;

	/**
	* 
	*/
	virtual double getHighValue() = 0;

	/**
	* 
	*/

};

#endif // !__HILODATA_H__
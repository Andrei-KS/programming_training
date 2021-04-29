#ifndef __TEMPERATURESENSORIMP_H__
#define __TEMPERATURESENSORIMP_H__

/**
* implements the pattern bridge separating the abstraction and the implementation of the temperature sensor
* @see pattern Bridge, TemperatureSensor
*/
class TemperatureSensorImp
{
public:
	/**
	* Destructor for created the TemperatureSensorImp
	*/
	virtual ~TemperatureSensorImp();

	/**
	* Function takes temperature readings from the temperature sensor
	* @return temperature values
	*/
	virtual double read() = 0;

};

#endif // !__TEMPERATURESENSORIMP_H__
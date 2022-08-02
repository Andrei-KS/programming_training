#ifndef __BAROMETRICPRESSURESENSORIMP_H__
#define __BAROMETRICPRESSURESENSORIMP_H__

/**
* implements the pattern bridge separating the abstraction and the implementation of the barometric pressure sensor
* @see pattern Bridge, TemperatureSensor
*/
class BarometricPressureSensorImp
{
public:
	/**
	* Destructor for created the BarometricPressureSensorImp
	*/
	virtual ~BarometricPressureSensorImp();

	/**
	* Function takes temperature readings from the barometric pressure sensor
	* @return barometric pressure values
	*/
	virtual double read() = 0;

};

#endif // !__BAROMETRICPRESSURESENSORIMP_H__
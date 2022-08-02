


#include "BarometricPressureTrendSensor.h"
#include "myLibMath.h"
#include "BarometricPressureSensor.h"

BarometricPressureTrendSensor::BarometricPressureTrendSensor(BarometricPressureSensor* bps)
	: itsPressure(std::vector<double>(3,0))
	, itsSumAllLastValuesPressure(0)
	, itsCurIndex(0)
{
	bps->registerObserver(this);
}

void BarometricPressureTrendSensor::update(double value)
{
	const double accuracy = 0.001;

	if (myLibMath::GreaterOrEqualDouble(std::abs(itsPressure.at(itsCurIndex) - value), 0.06, accuracy)
		&& myLibMath::GreaterOrEqualDouble(std::abs(itsSumAllLastValuesPressure/itsPressure.size() - value), 0.02, accuracy))
	{
		notifyObservers((value - itsPressure.at(itsCurIndex) > 0)? 1:-1);
	}
	else
	{
		notifyObservers(0);
	}

	itsCurIndex = (itsCurIndex + 1) % itsPressure.size();
	itsSumAllLastValuesPressure += value - itsPressure.at(itsCurIndex);
	itsPressure.at(itsCurIndex) = value;
}
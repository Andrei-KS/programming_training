

#include "TemperatureHiLo.h"

TemperatureHiLo::TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts)
{
	if (ts != nullptr)
	{
		ts->registerObserver(this);
	}
	else
	{
		throw("Error: TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts): ts is nullptr");
	}

	if (AClock != nullptr)
	{
		itsListener.itsTemperatureHiLo = this;
		itsListener.itsTemperatureSensor = ts;
		AClock->wakeupEveryDay(&itsListener);
	}
	else
	{
		throw("Error: TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts): AClock is nullptr");
	}
}

void TemperatureHiLo::update(double value)
{
	//TODO submit message to TemperatureHiLOData
}
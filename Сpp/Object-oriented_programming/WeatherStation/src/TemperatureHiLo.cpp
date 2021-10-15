

#include "TemperatureHiLo.h"
#include "HiLoData.h"

TemperatureHiLo::TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts, HiLoData* hld)
	: itsCurrentTime(0)
{
	if (ts != nullptr)
	{
		ts->registerObserver(this);
	}
	else
	{
		throw("Error: TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts, HiLoData* hld): ts is nullptr");
	}

	if (AClock != nullptr)
	{
		itsListener.itsTemperatureHiLo = this;
		itsListener.itsTemperatureSensor = ts;
		AClock->wakeupEveryDay(&itsListener);
	}
	else
	{
		throw("Error: TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts, HiLoData* hld): AClock is nullptr");
	}

	if (hld != nullptr)
	{
		itsHiLoDate = hld;
	}
	else
	{
		throw("Error: TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts, HiLoData* hld): hld is nullptr");
	}
}

void TemperatureHiLo::update(double value)
{
	itsHiLoDate->currentReading(value, itsCurrentTime);
}
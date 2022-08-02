

#include "..\include\TestAlarmClockImp.h"

TestAlarmClockImp::TestAlarmClockImp()
	: itsClockListners(std::vector<ClockListner*>())
{
}

TestAlarmClockImp::~TestAlarmClockImp()
{
}

void TestAlarmClockImp::registerClockListner(ClockListner* al)
{
	if (al != nullptr)
	{
		itsClockListners.push_back(al);
	}
}

void TestAlarmClockImp::run()
{
	size_t numberCall = 100;
	for (size_t i = 0; i < numberCall; i++)
	{
		for (std::vector<ClockListner*>::iterator itCL = itsClockListners.begin(); itCL != itsClockListners.end(); itCL++)
		{
			(*itCL)->tic();
		}
	}
}


#include "TestClockDriver.h"
#include "ClockDriver.h"
#include "MockTimeSink.h"
#include "MockTimeSource.h"
#include "MyAssert.h"

void TestClockDriver::testTimeChange()
{
	MockTimeSource* source = new MockTimeSource();
	MockTimeSink* sink = new MockTimeSink();
	ClockDriver* driver = new ClockDriver(source,sink);
	source->setTime(3, 4, 5);
	assert(3 == sink->getHours());
	assert(4 == sink->getMinutes());
	assert(5 == sink->getSeconds());

	source->setTime(7, 8, 9);
	assert(7 == sink->getHours());
	assert(8 == sink->getMinutes());
	assert(9 == sink->getSeconds());
}

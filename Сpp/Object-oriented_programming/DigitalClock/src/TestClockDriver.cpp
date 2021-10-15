

#include "TestClockDriver.h"
#include "MockTimeSink.h"
#include "MockTimeSource.h"
#include "MyAssert.h"

void TestClockDriver::assertSinksEquals(MockTimeSink* sink, int hours, int minutes, int seconds)
{
	assert(hours == sink->getHours());
	assert(minutes == sink->getMinutes());
	assert(seconds == sink->getSeconds());
}

void TestClockDriver::testTimeChange()
{
	MockTimeSource* source = new MockTimeSource();
	MockTimeSink* sink = new MockTimeSink(source);
	source->registerObserver(sink);

	source->setTime(3, 4, 5);
	assertSinksEquals(sink, 3, 4, 5);

	source->setTime(7, 8, 9);
	assertSinksEquals(sink, 7, 8, 9);

	delete source;
	delete sink;
}

void TestClockDriver::testMultiplesSinks()
{
	MockTimeSource* source = new MockTimeSource();
	MockTimeSink* sink = new MockTimeSink(source);
	MockTimeSink* sink2 = new MockTimeSink(source);
	source->registerObserver(sink);
	source->registerObserver(sink2);

	source->setTime(12, 13, 14);
	assertSinksEquals(sink, 12, 13, 14);
	assertSinksEquals(sink2, 12, 13, 14);

	delete source;
	delete sink;
	delete sink2;
}

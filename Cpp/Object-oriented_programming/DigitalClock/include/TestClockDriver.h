#ifndef __TESTCLOCKDRIVER_H__
#define __TESTCLOCKDRIVER_H__

class MockTimeSink;

class TestClockDriver
{
private:
	void assertSinksEquals(MockTimeSink* sink, int hours, int minutes, int seconds);

public:
	void testTimeChange();
	void testMultiplesSinks();
};

#endif // !__TESTCLOCKDRIVER_H__


#pragma once

#include "ActiveObjectEngine.h"
#include <string>
#include <exception>

class CommandWeakup;

class TestSleepCommand
{
	bool commandExecuted;
	friend class CommandWeakup;
public:
	TestSleepCommand();
	void testSleep() throw (std::exception);
};

class CommandWeakup : public Command
{
	TestSleepCommand* test;
public:
	CommandWeakup(TestSleepCommand* e);
	void execute() override;
};
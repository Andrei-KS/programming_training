
#pragma once

//#define __PRINT_DEBUG_MASSENG__

#include <list>
#include <exception>
#include <memory>

/*
* pattern active object
* it can act as an alternative to using multithreading 
*/

class Command;

class ActiveObjectEngine
{
	std::list<Command*> itsCommands;
public:
	void addCommand(Command* c);
	void run();
};

class Command
{
public:
	virtual void execute() throw (std::exception);
	virtual ~Command(){}
};
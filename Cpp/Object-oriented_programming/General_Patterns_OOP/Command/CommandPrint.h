// Object-oriented_programming.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <string>

// TODO: Reference additional headers your program requires here.

/*
* Pattern Command
* 
* class Command{
* public:
* 	virtual type do();
* }
* 
*/

class InterfacePrint {
public:
	virtual void print()=0;
};

class PrintStringToCommandLine : public InterfacePrint {
	std::string str;
public:
	PrintStringToCommandLine():str(std::string()){}
	PrintStringToCommandLine(std::string strIn);

	void print() override;
};
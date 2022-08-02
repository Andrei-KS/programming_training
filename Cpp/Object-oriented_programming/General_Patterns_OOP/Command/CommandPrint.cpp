#include "CommandPrint.h"

#include <iostream>


PrintStringToCommandLine::PrintStringToCommandLine(std::string strIn)
	: str(strIn)
{
}

void PrintStringToCommandLine::print()
{
	std::cout << str << "\n";
}

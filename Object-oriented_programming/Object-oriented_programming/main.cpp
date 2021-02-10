#include "Command/CommandPrint.h"

int main()
{
	InterfacePrint* printHello = new PrintStringToCommandLine("Hellow OOP\n");
	printHello->print();
	return 0;
}
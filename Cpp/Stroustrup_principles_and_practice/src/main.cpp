#include "RunCommandOfExample.h"
#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
	try
	{
		RunCommandOfExample::runCommandOfExample->itsArgC = argc;
		RunCommandOfExample::runCommandOfExample->itsArgV = argv;
		RunCommandOfExample::runCommandOfExample->excute();
	}
	catch (std::exception& e)
	{
		std::cout << "\033[1;31m" << "exception : " << e.what() << "\033[0m\n" << "\n";
	}
	catch (...)
	{
		//Do nothing
		return 1;
	}

	if (RunCommandOfExample::runCommandOfExample != nullptr)
	{
		delete RunCommandOfExample::runCommandOfExample;
	}
	return 0;
}
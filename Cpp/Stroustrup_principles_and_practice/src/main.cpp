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
    // more info about Colors and formatting can be get from 
    // https://misc.flogisoft.com/bash/tip_colors_and_formatting
    // https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes,
    // and https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal links
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
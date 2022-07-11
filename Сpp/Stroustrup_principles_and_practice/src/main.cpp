#include "RunCommandOfExample.h"

int main(int argc, char* argv[])
{
	//try
	//{
		RunCommandOfExample::runCommandOfExample->itsArgC = argc;
		RunCommandOfExample::runCommandOfExample->itsArgV = argv;
		RunCommandOfExample::runCommandOfExample->excute();
	//}
	//catch (...)
	//{
		//Do nothing
	//	return 1;
	//}

	if (RunCommandOfExample::runCommandOfExample != nullptr)
	{
		delete RunCommandOfExample::runCommandOfExample;
	}
	return 0;
}
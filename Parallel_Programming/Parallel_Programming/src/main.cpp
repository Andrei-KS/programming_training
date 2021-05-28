#include "RunCommandOfExample.h"

int main(int argc, char* argv[])
{
	RunCommandOfExample::runCommandOfExample->itsArgC = argc;
	RunCommandOfExample::runCommandOfExample->itsArgV = argv;
	RunCommandOfExample::runCommandOfExample->excute();
	return 0;
}
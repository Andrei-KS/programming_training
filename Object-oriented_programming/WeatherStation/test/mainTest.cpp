

#include "TestTemperatureSensorTest.h"
#include "TestBarometricPressureSensorTest.h"

int main(int argc, char** argv)
{
	TestBarometricPressureSensorTest tbpst;
	tbpst.excute();
	TestTemperatureSensorTest ttst;
	ttst.excute();
	return 0;
}
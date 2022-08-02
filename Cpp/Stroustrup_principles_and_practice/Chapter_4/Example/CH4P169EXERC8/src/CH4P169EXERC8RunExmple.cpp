/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/25/2021 21:50:12
	author														: Andrei-KS
*/

#include "CH4P169EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P169EXERC8RunExmple();

namespace {
}

int CH4P169EXERC8RunExmple::excute()
{
	cout << "How much grain to get: ";
	int needGrains = 0;
	cin >> needGrains;
	int currentGrains = 0;
	int nextCell = 1;
	while (currentGrains < needGrains)
	{
		currentGrains += 1 << nextCell;
		cout << "current cell\t: " << nextCell << "\n"
			<< "current grains\t: " << currentGrains << "\n\n";
		++nextCell;
	}
	cout << "Need to fill " << (nextCell - 1) << " cells.\n";
	return 0;
}
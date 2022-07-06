/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/24/2021 22:51:34
	author														: Andrei-KS
*/

#include "CH4P169EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P169EXERC3RunExmple();

namespace {
}

int CH4P169EXERC3RunExmple::excute()
{
	vector<double> distances;
	double sum = 0;
	double maxDistance = std::numeric_limits<double>::max();
	double minDistance = std::numeric_limits<double>::min();

	double distance = 0;
	cout << "Entry distance between cities: ";
	for (; cin >> distance;)
	{
		distances.push_back(distance);
		sum += distance;
		if (distance > maxDistance) maxDistance = distance;
		if (distance < minDistance) minDistance = distance;
		
		cout << "Entry next distance between cities: ";
	}

	cout << "Sum distances\t: " << sum << "\n"
		<< "Max distance\t: " << maxDistance << "\n"
		<< "Min distance\t: " << minDistance << "\n"
		<< "Mid distance\t: " << sum / distances.size() << "\n";
	return 0;
}
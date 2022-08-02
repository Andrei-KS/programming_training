/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/08/2022 15:09:07
	author														: Andrei-KS
*/

#include "CH10P377EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P377EXERC2RunExmple();

namespace {
	/*
	* A temperature reading
	* @author Andrei-KS
	*/
	struct Reading {
		/* hour after midnight [0:23] */
		int hour;

		/* in Fahrenheit */
		double temperature;
	};

	ostream& operator<<(ostream& ost, const Reading& reading)
	{
		return ost << '(' << reading.hour<< ','
			<< reading.temperature << ")\n";
	}

	void fill_to_file(vector<Reading>& readings, const string& file_name)
	{
		ofstream ost{ file_name };
		if (!ost)
		{
			error("can't open input file ", file_name);
		}

		for (const Reading& reading : readings)
		{
			ost << reading;
		}

		ost.close();
	}
}

int CH10P377EXERC2RunExmple::excute()
{
	vector<Reading> readings = {
		{0,60.6},
		{1,61.2},
		{2,60.7},
		{3,60.6},
		{4,60.3},
		{5,59.9},
		{6,59.7},
		{7,60.2},
		{8,60.36},
		{9,60.63},
		{10,61.11},
		{11,61.5},
		{12,62.01},
		{13,63.05},
		{14,64.0},
		{15,63.6},
		{16,62.5},
		{17,61.3},
		{18,60.8},
		{19,60.7},
		{20,60.5},
		{21,60.3},
		{22,60.1},
		{23,60.0},
		{0,60.62},
		{1,61.23},
		{2,60.74},
		{3,60.63},
		{4,60.32},
		{5,59.94},
		{6,59.71},
		{7,60.23},
		{8,60.36},
		{9,60.63},
		{10,61.11},
		{11,61.5},
		{12,62.01},
		{13,63.05},
		{14,64.02},
		{15,63.6},
		{16,62.53},
		{17,61.3},
		{18,60.84},
		{19,60.7},
		{20,60.55},
		{21,60.3},
		{22,60.1},
		{23,60.0},
	};

	fill_to_file(readings, "raw_temps.txt");
	return 0;
}
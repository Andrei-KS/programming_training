/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/08/2022 15:47:13
	author														: Andrei-KS
*/

#include "CH10P377EXERC3RunExmple.h"
#include <algorithm>
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P377EXERC3RunExmple();

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
		return ost << '(' << reading.hour << ','
			<< reading.temperature << ")\n";
	}

	istream& operator>>(istream& is, Reading& reading)
	{
		char ch1, ch2, ch3;
		int hour;
		double temperature;
		is >> ch1 >> hour >> ch2 >> temperature >> ch3;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ')')
		{
			error("bad reading");
		}

		reading.hour = hour;
		reading.temperature = temperature;
		return is;
	}

	void fill_from_file(vector<Reading>& readings, const string& file_name)
	{
		ifstream ist{ file_name };
		if(!ist)
		{
			error("can't open input file ", file_name);
		}

		for (Reading reading; ist >> reading;)
		{
			readings.push_back(reading);
		}
		if (ist.eof()) return;
		if (ist.bad())
		{
			error("bad input stream");
		}
		if (ist.fail())
		{
			error("fail input stream");
		}

		ist.close();
	}

	void fill_to_file(const vector<Reading>& readings, const string& file_name)
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

int CH10P377EXERC3RunExmple::excute()
{
	vector<Reading> readings;
	fill_from_file(readings, "raw_temps.txt");

	double mean_temperature = 0;
	for (const Reading& reading : readings)
	{
		mean_temperature += reading.temperature;
	}
	mean_temperature = mean_temperature / readings.size();

	double median_temperature = 0;
	std::sort(readings.begin(), readings.end(), [](const Reading& left, const Reading& right) {return left.temperature < right.temperature; });
	if (readings.size() > 0)
	{
		median_temperature = ((readings.size()%2 == 1) ? (readings[readings.size() / 2].temperature) : ((readings[readings.size()/2].temperature + readings[readings.size() / 2 + 1].temperature)/2));
	}


	cout << "Mean temperature: " << mean_temperature << "\n"
		<< "Median temperature: " << median_temperature << "\n";

	return 0;
}
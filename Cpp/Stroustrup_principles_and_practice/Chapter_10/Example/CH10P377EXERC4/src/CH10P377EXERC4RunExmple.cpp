/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/08/2022 18:01:26
	author														: Andrei-KS
*/

#include "CH10P377EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P377EXERC4RunExmple();

namespace {
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_C = -273.15;	// [c]
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_F = -459.67;	// [f]

	double ftoc(double f)
	{
		if (f < ABSOLUT_TEMPERATURE_ZERO_IN_F)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO_IN_F << "\n";
			error(os.str());
		}
		return (f - 32.0) * 5.0 / 9.0;
	}

	double ctof(double c)
	{
		if (c < ABSOLUT_TEMPERATURE_ZERO_IN_C)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO_IN_C << "\n";
			error(os.str());
		}
		return c * 9.0 / 5.0 + 32;
	}

	enum Temperature_measure_unit {
		NONE = 0,
		CELSIUS,
		FAHRENHEIT,
	};

	char Temperature_suffix[] = { '?','c','f' };

	/*
	* A temperature reading
	* @author Andrei-KS
	*/
	struct Reading {
		/* hour after midnight [0:23] */
		int hour;

		/**/
		double temperature;
		/**/
		Temperature_measure_unit type;
	};

	ostream& operator<<(ostream& ost, const Reading& reading)
	{
		return ost << '(' << reading.hour << ','
			<< reading.temperature << Temperature_suffix[reading.type] << ")";
	}

	istream& operator>>(istream& is, Reading& reading)
	{
		char ch1, ch2, ch3, ch4;
		int hour;
		double temperature;
		is >> ch1 >> hour >> ch2 >> temperature >> ch3 >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch4 != ')')
		{
			error("bad reading");
		}

		reading.hour = hour;
		reading.temperature = temperature;
		switch (ch3)
		{
			case 'c':
			{
				reading.type = Temperature_measure_unit::CELSIUS;
				break;
			}
			case 'f':
			{
				reading.type = Temperature_measure_unit::FAHRENHEIT;
				break;
			}
			default:
			{
				reading.type = Temperature_measure_unit::NONE;
				break;
			}
		}
		return is;
	}

	void fill_from_file(vector<Reading>& readings, const string& file_name)
	{
		ifstream ist{ file_name };
		if (!ist)
		{
			error("can't open input file ", file_name);
		}

		for (Reading reading; ist >> reading;)
		{
			if (reading.type == Temperature_measure_unit::CELSIUS)
			{
				reading.temperature = ctof(reading.temperature);
				reading.type = Temperature_measure_unit::FAHRENHEIT;
			}
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
			ost << reading << "\n";
		}

		ost.close();
	}

	void make_test_file(const string& file_name)
	{
		vector<Reading> readings = {
			{0,60.6,Temperature_measure_unit::CELSIUS},
			{1,61.2,Temperature_measure_unit::CELSIUS},
			{2,60.7,Temperature_measure_unit::CELSIUS},
			{3,60.6,Temperature_measure_unit::CELSIUS},
			{4,60.3,Temperature_measure_unit::CELSIUS},
			{5,59.9,Temperature_measure_unit::CELSIUS},
			{6,59.7,Temperature_measure_unit::CELSIUS},
			{7,60.2,Temperature_measure_unit::CELSIUS},
			{8,60.36,Temperature_measure_unit::CELSIUS},
			{9,60.63,Temperature_measure_unit::CELSIUS},
			{10,61.11,Temperature_measure_unit::CELSIUS},
			{11,61.5,Temperature_measure_unit::CELSIUS},
			{12,62.01,Temperature_measure_unit::CELSIUS},
			{13,63.05,Temperature_measure_unit::CELSIUS},
			{15,63.6,Temperature_measure_unit::CELSIUS},
			{14,64.0,Temperature_measure_unit::CELSIUS},
			{16,62.5,Temperature_measure_unit::CELSIUS},
			{17,61.3,Temperature_measure_unit::CELSIUS},
			{18,60.8,Temperature_measure_unit::CELSIUS},
			{19,60.7,Temperature_measure_unit::CELSIUS},
			{20,60.5,Temperature_measure_unit::CELSIUS},
			{21,60.3,Temperature_measure_unit::CELSIUS},
			{22,60.1,Temperature_measure_unit::CELSIUS},
			{23,60.0,Temperature_measure_unit::CELSIUS},
			{0,60.62,Temperature_measure_unit::CELSIUS},
			{1,61.23,Temperature_measure_unit::CELSIUS},
			{2,60.74,Temperature_measure_unit::CELSIUS},
			{3,60.63,Temperature_measure_unit::CELSIUS},
			{4,60.32,Temperature_measure_unit::CELSIUS},
			{5,59.94,Temperature_measure_unit::CELSIUS},
			{6,59.71,Temperature_measure_unit::CELSIUS},
			{7,60.23,Temperature_measure_unit::CELSIUS},
			{8,60.36,Temperature_measure_unit::CELSIUS},
			{9,60.63,Temperature_measure_unit::CELSIUS},
			{10,61.11,Temperature_measure_unit::CELSIUS},
			{11,61.5,Temperature_measure_unit::CELSIUS},
			{12,62.01,Temperature_measure_unit::CELSIUS},
			{13,63.05,Temperature_measure_unit::CELSIUS},
			{14,64.02,Temperature_measure_unit::CELSIUS},
			{15,63.6,Temperature_measure_unit::CELSIUS},
			{16,62.53,Temperature_measure_unit::CELSIUS},
			{17,61.3,Temperature_measure_unit::CELSIUS},
			{18,60.84,Temperature_measure_unit::CELSIUS},
			{19,60.7,Temperature_measure_unit::CELSIUS},
			{20,60.55,Temperature_measure_unit::CELSIUS},
			{21,60.3,Temperature_measure_unit::CELSIUS},
			{22,60.1,Temperature_measure_unit::CELSIUS},
			{23,60.0,Temperature_measure_unit::CELSIUS},
		};

		fill_to_file(readings, file_name);
	}

	void get_statistic_from_file(const string& file_name)
	{
		vector<Reading> readings;
		fill_from_file(readings, file_name);

		double mean_temperature = 0;
		for (Reading& reading : readings)
		{
			mean_temperature += reading.temperature;
		}
		mean_temperature = mean_temperature / readings.size();

		double median_temperature = 0;
		std::sort(readings.begin(), readings.end(), [](const Reading& left, const Reading& right) {return left.temperature < right.temperature; });
		if (readings.size() > 0)
		{
			median_temperature = ((readings.size() % 2 == 1) ? (readings[readings.size() / 2].temperature) : ((readings[readings.size() / 2].temperature + readings[readings.size() / 2 + 1].temperature) / 2));
		}


		cout << "Mean temperature: " << mean_temperature << "\n"
			<< "Median temperature: " << median_temperature << "\n";
	}
}

int CH10P377EXERC4RunExmple::excute()
{
	const char file_name[] = "raw_temps.txt";
	make_test_file(file_name);
	get_statistic_from_file(file_name);
	return 0;
}
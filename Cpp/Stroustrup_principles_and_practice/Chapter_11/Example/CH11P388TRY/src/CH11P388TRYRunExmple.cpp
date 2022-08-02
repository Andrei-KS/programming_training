/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/25/2022 12:24:38
	author														: Andrei-KS
*/

#include "CH11P388TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P388TRYRunExmple();

namespace {
	struct Recording {
		string last_name;
		string first_name;
		string telephon_number;
		string email;
	};

	void print_last_five_recording(const vector<Recording>& recording_table, ostream& ost)
	{
		const int LAST_NAME_FIELD_SIZE = 10;
		const int FIRST_NAME_FIELD_SIZE = 10;
		const int TELEPHON_NUMBER_FIELD_SIZE = 15;
		const int EMAIL_FIELD_SIZE = 25;
		const char DELIMIT_SYMBOL = '|';

		int table_size = recording_table.size();
		int current_recording_to_print = table_size < 5 ? (0) : (table_size -5);
		while (current_recording_to_print < table_size)
		{
			ost << setw(LAST_NAME_FIELD_SIZE) << recording_table[current_recording_to_print].last_name << DELIMIT_SYMBOL
				<< setw(FIRST_NAME_FIELD_SIZE) << recording_table[current_recording_to_print].first_name << DELIMIT_SYMBOL
				<< setw(TELEPHON_NUMBER_FIELD_SIZE) << recording_table[current_recording_to_print].telephon_number << DELIMIT_SYMBOL
				<< setw(EMAIL_FIELD_SIZE) << recording_table[current_recording_to_print].email << DELIMIT_SYMBOL << "\n";
			++current_recording_to_print;
		}
	}
}

int CH11P388TRYRunExmple::excute()
{
	vector<Recording> recording_table{
		{ "Lostson", "Grep", "8***30429*", "lostG@m.com"},
		{ "Lostson", "Mark", "8***30429*", "lostM@m.com"},
		{ "Hamersogar", "Lariet", "7***23405", "H_Lar@email.gov"},
		{ "Sumjin", "Gapur", "2***83424532", "Sumjin67@ramurat.com"},
		{ "Litu", "Pacunut", "***23456", ""},
		{ "KS", "Andrei", "**********", "Andrei-KS"},
	};
	print_last_five_recording(recording_table, cout);
	return 0;
}
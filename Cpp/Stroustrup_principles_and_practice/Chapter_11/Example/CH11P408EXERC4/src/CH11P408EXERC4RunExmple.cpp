/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/26/2022 18:53:21
	author														: Andrei-KS
*/

#include "CH11P408EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC4RunExmple();

namespace {
	const int AMOUNT_INTEGERS = 7;

	const int FIRST_FILD_WIDTH = 5;
	const int SECONDE_FILD_WIDTH = 12;
	const int THIRD_FILD_WIDTH = 12;
	const int FOURTH_FILD_WIDTH = 5;
	const int FIFTH_FILD_WIDTH = 7;
	const char DELIMIT_SYMBOL = ' ';

	enum class Entered_type {
		NONE,
		OCTAL,
		DECIMAL,
		HEXADECIMAL
	};

	vector<pair<Entered_type, int>> integers;
}

int CH11P408EXERC4RunExmple::excute()
{
	
	cout << "Please, enter " << AMOUNT_INTEGERS << " integer" << (AMOUNT_INTEGERS==1?"":"s") << " in any combination of octal, decimal, or hexadecimal, \n"
		<< "using the 0 and 0x base suffixes. These integers will be converted to decimal form.\n";
	
	Entered_type current_entered_type = Entered_type::NONE;
	for (int index = 0; index < AMOUNT_INTEGERS; index++)
	{
		current_entered_type = Entered_type::NONE;
		cout << setw(2) << index << ": ";
		char ch1, ch2, ch3;
		if (cin.get(ch1) && isdigit(ch1))
		{
			if (ch1 == '0')
			{
				if (cin.get(ch2))
				{
					if (ch2 == 'x')
					{
						cin.putback(ch2).putback(ch1);
						current_entered_type = Entered_type::HEXADECIMAL;
					}
					if (isdigit(ch2))
					{
						cin.putback(ch2).putback(ch1);
						current_entered_type = Entered_type::OCTAL;
					}
				}
			}
			else
			{
				cin.putback(ch1);
				current_entered_type = Entered_type::DECIMAL;
			}
		}

		if (current_entered_type == Entered_type::NONE)
		{
			if (!cin)
			{
				error("cin incorrect work");
			}
			cout << "Invalid entering. Please try again entering integer\n";
			index--;
			continue;
		}

		int number;
		switch (current_entered_type)
		{
		case Entered_type::OCTAL:
			cin >> oct >> number;
			break;
		case Entered_type::DECIMAL:
			cin >> dec >> number;
			break;
		case Entered_type::HEXADECIMAL:
			cin >> hex >> number;
			break;
		default:
			error("Something wrong");
			break;
		}
		integers.push_back({ current_entered_type,number });
		
		while (cin.get(ch1))
		{
			if (ch1 == '\n')
			{
				break;
			}
		}
	}

	cout << "\nOutput:\n";
	for (pair<Entered_type, int>& integer : integers)
	{
		cout << setw(FIRST_FILD_WIDTH) << showbase;
		switch (integer.first)
		{
		case Entered_type::OCTAL:
			cout << oct << integer.second << DELIMIT_SYMBOL << setw(SECONDE_FILD_WIDTH) << left << "octal";
			break;
		case Entered_type::DECIMAL:
			cout << dec << integer.second << DELIMIT_SYMBOL << setw(SECONDE_FILD_WIDTH) << left  << "decimal";
			break;
		case Entered_type::HEXADECIMAL:
			cout << hex << integer.second << DELIMIT_SYMBOL << setw(SECONDE_FILD_WIDTH)  << left << "hexadecimal";
			break;
		default:
			error("Something wrong");
			break;
		}
		cout << DELIMIT_SYMBOL << right << setw(THIRD_FILD_WIDTH) << "converts to "
			<< DELIMIT_SYMBOL << setw(FOURTH_FILD_WIDTH) << dec << integer.second
			<< DELIMIT_SYMBOL << setw(FIFTH_FILD_WIDTH) << "decimal\n";
	}
	return 0;
}
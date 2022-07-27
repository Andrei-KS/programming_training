/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/27/2022 15:47:52
	author														: Andrei-KS
*/

#include "CH11P408EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC5RunExmple();

namespace {
	const string exit_command = "!exit";
	const vector<string> character_classification_str = {
		"whitespace",
		"number base prefix",
		"decimal digit",
		"hexadecimal digit",
		"octal digit",
		"uppercase letter",
		"lowercase letter",
		"control character",
		"punct character",
		"printable"
	};

	constexpr short MASK_WHITESPACE				= 1;
	constexpr short MASK_NUMBER_BASE_PREFIX	= 1 << 1;
	constexpr short MASK_DECIMAL_DIGIT			= 1 << 2;
	constexpr short MASK_HEXADECIMAL_DIGIT		= 1 << 3;
	constexpr short MASK_OCTAL_DIGIT				= 1 << 4;
	constexpr short MASK_UPPERCASE_LETTER		= 1 << 5;
	constexpr short MASK_LOWERCASE_LETTER		= 1 << 6;
	constexpr short MASK_CONTROL_CHARACTER		= 1 << 7;
	constexpr short MASK_PUNCT_CHARACTER		= 1 << 8;
	constexpr short MASK_PRINTABLE				= 1 << 9;
	
	bool isoctal(const char ch)
	{
		return ch == '0' || ch == '1' || ch == '2' || ch == '3'
			|| ch == '4' || ch == '5' || ch == '6' || ch == '7';
	}
}

int CH11P408EXERC5RunExmple::excute()
{
	cout << "Program that reads strings and for each string outputs\n"
		<< "the character classification of each character.(" << exit_command << " is a command to leave a program)\n"
		<< "Please, enter strings:\n";
	string str;
	while (getline(cin, str))
	{
		if (str.compare(0, exit_command.size(), exit_command) == 0)
		{
			break;
		}
		const int added_end_space = 2;
		str += "\n" + string(added_end_space, ' ');

		short mask;
		char ch;
		short start = MASK_WHITESPACE;
		int str_size = str.size() - added_end_space;
		for (int index = 0; index < str_size; index++)
		{
			ch = str[index];
			mask = 0;

			if (isspace(ch))
			{
				mask |= MASK_WHITESPACE;
				start = MASK_WHITESPACE;
			}

			if (ch != '\n')
			{
				if (isdigit(ch))
				{
					if (ch == '0')
					{
						if ((start == MASK_WHITESPACE || start == MASK_HEXADECIMAL_DIGIT) && str[index + 1] == 'x' && isxdigit(str[index + 2]))
						{
							mask |= MASK_NUMBER_BASE_PREFIX;
							start = MASK_HEXADECIMAL_DIGIT;
						}
						if (start == MASK_WHITESPACE && (isoctal(str[index+1])))
						{
							mask |= MASK_NUMBER_BASE_PREFIX;
							start = MASK_OCTAL_DIGIT;
						}
					}
					if (start == MASK_OCTAL_DIGIT && isoctal(ch))
					{
						mask |= MASK_OCTAL_DIGIT;
					}
					else if (start == MASK_HEXADECIMAL_DIGIT)
					{
						mask |= MASK_HEXADECIMAL_DIGIT;
					}
					else
					{
						mask |= MASK_DECIMAL_DIGIT;
						start = MASK_DECIMAL_DIGIT;
					}
				}

				if (isupper(ch))
				{
					if (start == MASK_HEXADECIMAL_DIGIT && isxdigit(ch))
					{
						mask |= MASK_HEXADECIMAL_DIGIT;
					}
					else
					{
						mask |= MASK_UPPERCASE_LETTER;
						start = MASK_UPPERCASE_LETTER;
					}
				}

				if (islower(ch))
				{
					if (ch == 'x' && start == MASK_HEXADECIMAL_DIGIT && str[index - 1] == '0')
					{
						mask |= MASK_NUMBER_BASE_PREFIX | MASK_HEXADECIMAL_DIGIT;
					}
					else if (start == MASK_HEXADECIMAL_DIGIT && isxdigit(ch))
					{
						mask |= MASK_HEXADECIMAL_DIGIT;
					}
					else
					{
						mask |= MASK_LOWERCASE_LETTER;
						start = MASK_LOWERCASE_LETTER;
					}
				}

				if (iscntrl(ch))
				{
					mask |= MASK_CONTROL_CHARACTER;
					start = MASK_CONTROL_CHARACTER;
				}
				if (ispunct(ch))
				{
					mask |= MASK_PUNCT_CHARACTER;
				}
				if (isprint(ch))
				{
					mask |= MASK_PRINTABLE;
				}
			}

			cout << setw(2) << ch << " - ";
			int index_mask = 0;
			while (mask)
			{
				if (mask & 1)
				{
					cout << character_classification_str[index_mask] << (mask != 1?", ":"");
				}
				index_mask++;
				mask >>= 1;
			}
			cout << "\n";
		}
	}
	return 0;
}
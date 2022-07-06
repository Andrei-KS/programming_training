/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 01/09/2022 21:07:08
	author														: Andrei-KS
*/

#include "CH9P339EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P339EXERC2RunExmple();

namespace {
	class Name_pairs
	{
	public:
		/*
		* Reads a series of names from console
		*/
		void read_names();

		/*
		* Prompts the user for an age for each name
		*/
		void read_ages();

		/*
		* Prints out the (name[i],age[i]) pairs (one per line)
		* in the order determined by the name vector
		*/
		void print();

		/*
		* sorts the name vector in alphabetical order and
		* reorganizes the age vector to match.
		*/
		void sort();

	private:
		/* */
		vector<string> itsNames;

		/* */
		vector<double> itsAges;
	};

	void Name_pairs::read_names()
	{
		string answer;
		string name;
		while (true)
		{
			cout << "Do you want add new name to Name_pairs?(Yes/No)\n";
			cin >> answer;
			
			if (answer == "No")
			{
				return;
			}

			if (answer == "Yes")
			{
				cout << "Please, entry name: ";
				cin >> name;
				itsNames.push_back(name);
				itsAges.push_back(-1);
				continue;
			}

			cout << "Unknown answer.\n";
		}
	}

	void Name_pairs::read_ages()
	{
		for (size_t i = 0; i < itsNames.size(); i++)
		{
			cout << "Please, entry age for "<< itsNames[i] << ": ";
			cin >> itsAges[i];
		}
	}

	void Name_pairs::print()
	{
		for (size_t i = 0; i < itsNames.size(); i++)
		{
			cout << itsNames[i] << " " << itsAges[i] << "\n";
		}
	}

	void Name_pairs::sort()
	{
		for (size_t indexLeft = 0; indexLeft < itsNames.size(); indexLeft++)
		{
			for (size_t index = indexLeft + 1; index < itsNames.size(); index++)
			{
				if (itsNames[indexLeft] > itsNames[index])
				{
					swap(itsNames[indexLeft], itsNames[index]);
					swap(itsAges[indexLeft], itsAges[index]);
				}
			}
		}
	}
}

int CH9P339EXERC2RunExmple::excute()
{
	Name_pairs name_pairs;
	name_pairs.read_names();
	name_pairs.read_ages();
	name_pairs.print();
	name_pairs.sort();
	name_pairs.print();
	return 0;
}
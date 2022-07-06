/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 01/09/2022 23:29:11
	author														: Andrei-KS
*/

#include "CH9P339EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P339EXERC3RunExmple();

namespace {
	/*----------------------------------------------
	Declaration
	----------------------------------------------*/
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
		* sorts the name vector in alphabetical order and
		* reorganizes the age vector to match.
		*/
		void sort();

		// nonmodifying operations:
		/*
		* @return series of names
		*/
		const vector<string>& get_names() const { return itsNames; };

		/*
		* @return age for each name
		*/
		const vector<double>& get_ages() const { return itsAges; };

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

	/*
	* Prints out the (name[i],age[i]) pairs (one per line)
	* in the order determined by the name vector
	*/
	ostream& operator<<(ostream& os, const Name_pairs& name_pairs);

	bool operator==(const Name_pairs& left, const Name_pairs& right);
	bool operator!=(const Name_pairs& left, const Name_pairs& right);

	/*----------------------------------------------
	Implementation
	----------------------------------------------*/
	void Name_pairs::read_ages()
	{
		for (size_t i = 0; i < itsNames.size(); i++)
		{
			cout << "Please, entry age for " << itsNames[i] << ": ";
			cin >> itsAges[i];
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

	ostream& operator<<(ostream& os, const Name_pairs& name_pairs)
	{
		for (size_t index = 0; index < name_pairs.get_names().size(); index++)
		{
			os << "(" << (name_pairs.get_names())[index]
				<< ", " << (name_pairs.get_ages())[index] << ")\n";
		}
		return os;
	}

	bool operator==(const Name_pairs& left, const Name_pairs& right)
	{
		if (left.get_names().size() != right.get_names().size())
		{
			return false;
		}

		for (size_t index = 0; index < left.get_names().size(); index++)
		{
			if (left.get_names()[index] != right.get_names()[index] || left.get_ages()[index] != right.get_ages()[index])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const Name_pairs& left, const Name_pairs& right)
	{
		return !(left == right);
	}
}

int CH9P339EXERC3RunExmple::excute()
{
	Name_pairs name_pairs;
	name_pairs.read_names();
	name_pairs.read_ages();
	cout << name_pairs;
	Name_pairs name_pairs2 = name_pairs;
	cout << (name_pairs != name_pairs2 ? "no equal\n" : "equal\n");
	name_pairs.sort();
	cout << name_pairs;
	cout << (name_pairs != name_pairs2 ? "no equal\n" : "equal\n");
	return 0;
}
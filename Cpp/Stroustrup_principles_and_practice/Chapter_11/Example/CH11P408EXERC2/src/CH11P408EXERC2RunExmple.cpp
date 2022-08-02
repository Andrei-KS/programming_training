/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/26/2022 12:37:00
	author														: Andrei-KS
*/

#include "CH11P408EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC2RunExmple();

namespace {
	class Punct_stream {
	public:
		/*
		* This object will be associated with the character source
		* @param ist - istream that would give stream elements
		*/
		Punct_stream(istream& ist);

		/* make s the whitespace set
		* @param s - set of whitespace
		*/
		void whitespace(const string& s);

		/*
		* add to the whitespace set
		* @param c - the symbol that needs to be added to the whitespace set
		*/
		void add_white(char c);

		/*
		* check c is in whitespace set
		* @param c - symbol for checking
		*/
		bool is_whitespace(char c);

		/*
		*/
		void case_sensitive(bool b);
		
		/*
		*/
		bool is_case_sensitive(); 
		
		/*
		*/
		Punct_stream& operator>>(string& s);
		
		int get_current_line_number();

		/*
		*/
		operator bool();

	private:
		/* character source */
		istream& source;

		/* we let buffer do our formatting */
		istringstream buffer;

		/* characters considered “whitespace” */
		string white;

		/* is the stream case-sensitive? */
		bool sensitive;

		/* current line in related istream */
		int line_number;
	};

	Punct_stream::Punct_stream(istream& ist)
		: source{ ist }
		, sensitive{ true }
		, line_number{ 0 }
	{
	}

	void Punct_stream::whitespace(const string& s)
	{
		white = s;
	}

	void Punct_stream::add_white(char c)
	{
		white += c;
	}

	bool Punct_stream::is_whitespace(char c)
	{
		for (char w : white)
			if (c == w) return true;
		return false;
	}

	void Punct_stream::case_sensitive(bool b)
	{
		sensitive = b;
	}

	bool Punct_stream::is_case_sensitive()
	{ 
		return sensitive;
	}

	Punct_stream& Punct_stream::operator>>(string& s)
	{
		// try to read from buffer
		while (!(buffer >> s)) { 
			if (buffer.bad() || !source.good()) return *this;
			buffer.clear();
			string line;
			// get a line from source
			getline(source, line);
			line_number++;

			// do character replacement as needed:
			for (char& ch : line)
				if (is_whitespace(ch))
				{
					// to space
					ch = ' ';
				}
				else if (!sensitive)
				{
					// to lower case
					ch = tolower(ch);
				}

			// put string into stream
			buffer.str(line); 
		}
		return *this;
	}

	Punct_stream::operator bool()
	{
		return !(source.fail() || source.bad()) && buffer.good();
	}

	int Punct_stream::get_current_line_number()
	{
		return line_number;
	}
}

int CH11P408EXERC2RunExmple::excute()
{
	cout << "A program that given a file name and a word outputs each line that contains\n"
		<< "that word together with the line number.\n"
		<< "Please, enter name file: ";
	string file_name;
	cin >> file_name;
	
	ifstream file_in{ file_name };
	if (!file_in)
	{
		error("Can't open file", file_name);
	}
	Punct_stream ps(file_in);
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~'");
	ps.case_sensitive(true);

	cout << "Please, enter word: ";
	string word_to_search;
	cin >> word_to_search;


	for (string word; ps >> word || !file_in.eof();)
	{
		if (word == word_to_search)
		{
			cout << setw(5) << ps.get_current_line_number() << "\t" << word << "\n";
		}
	}

	return 0;
}
/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 11/04/2021 12:00:36
	author														: Andrei-KS
	source code link											: https://www.stroustrup.com/Programming/calculator00.cpp
*/

#include "CH6P250TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH6P250TRYRunExmple();

namespace {
	/*
	* Token class - this type is required for lexicographic analysis 
	* It has two parts (called members): kind and value
	*/
	class Token
	{
	public:
		/* kind of tokens */
		char kind;

		/* for numeric tokens: value */
		double value;

		/*
		* Make a Token from a char
		* @param ch - defines the kind of token to be created 
		*/
		Token(char ch):kind(ch), value(0) { }

		/*
		* Make a Token from a char and a double
		* @param ch - defines the kind of token to be created 
		* @param val - defines the value of token to be created 
		*/
		Token(char ch, double val)	:kind(ch), value(val) { }
	};

	/*
	* Reads characters and make tokens
	* @return Token
	* @see Token
	*/
	Token get_token();

	/*
	* Works with operations '+' and '-'.
	* Calls the term() and get_token() functions
	* @return double value
	* @see get_token(), term()
	*/
	double expression();

	/*
	* Work with operation '*', '/' and '%'
	* Calls the primary() and get_token() functions
	* @return double value
	* @see get_token(), primary()
	*/
	double term();

	/*
	* Work with numbers and brackets.
	* Calls the primary() and get_token() functions
	* @return double value
	* @see get_token(), expression()
	*/
	double primary();
	
	/*----------------------------------------------
		Implementation
	----------------------------------------------*/
	Token get_token()
	{
		char ch;
		cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

		switch (ch) {
			//not yet   case ';':    // for "print"
			//not yet   case 'q':    // for "quit"
		case '(': case ')': case '+': case '-': case '*': case '/':
			return Token(ch);        // let each character represent itself
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);         // put digit back into the input stream
			double val;
			cin >> val;              // read a floating-point number
			return Token('8', val);   // let '8' represent "a number"
		}
		default:
			error("Bad token");
		}
	}

	double expression()
	{
		double left = term();
		Token token = get_token();
		while (true)
		{
			switch (token.kind)
			{
			case '+':
			{
				left += term();
				token = get_token();
				break;
			}
			case '-':
			{
				left -= term();
				token = get_token();
				break;
			}
			default:
				return left;
			}
		}
	}

	double term()
	{
		double left = primary();
		Token token = get_token();
		while (true)
		{
			switch (token.kind)
			{
			case '*':
			{
				left *= primary();
				token = get_token();
				break;
			}
			case '/':
			{
				double d = primary();
				if (d == 0)
				{
					error("division by zero");
				}
				left /= d;
				token = get_token();
				break;
			}
			default:
				return left;
			}
		}
	}

	double primary()
	{
		Token token = get_token();
		switch (token.kind)
		{
		case '(':
		{
			double d = expression();
			token = get_token();
			if (token.kind != ')')
			{
				error("required ')'\n");
			}
			return d;
		}
		case '8':
			return token.value;
		default:
			error("primary expression required\n");
		}
	}
}

int CH6P250TRYRunExmple::excute()
{

	try
	{
		while (cin)
		{
			cout <<  expression() << "\n";
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cerr << "exception\n";
		keep_window_open();
		return 2;
	}
	return 0;
}
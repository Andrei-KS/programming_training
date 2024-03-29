/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 11/07/2021 12:52:50
	author														: Andrei-KS
*/

#include "CH6P264EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH6P264EXERC3RunExmple();

namespace {
	constexpr char EXIT_SYMBOL = 'x';
	constexpr char DISPLAY_SYMBOL = '=';
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
		Token(char ch) :kind(ch), value(0) { }

		/*
		* Make a Token from a char and a double
		* @param ch - defines the kind of token to be created
		* @param val - defines the value of token to be created
		*/
		Token(char ch, double val) :kind(ch), value(val) { }
	};

	/*
	* Token_stream class - this type is required for lexicographic analysis.
	* This class has the ability to receive from stream (cin)
	* and return tokens to the stream (cin).
	*
	* Important: We assume that tokens are returned to the
	* stream no more than one at a time.
	*
	* @see Token
	*/
	class Token_stream
	{
	public:
		/*
		* Creates an object of the Token Stream.
		*/
		Token_stream();

		/*
		* Retrieves a Token object from a stream.
		* @return Token object
		*/
		Token get();

		/*
		* Returns the Token back to the stream.
		* @param token - which will return to the stream.
		*/
		void putback(Token token);

	private:
		/* buffer busy indicator */
		bool full;

		/* the token is stored after returning with putback() */
		Token buffer;
	};

	/*
	* @param number - the factorial of this number will be returned 
	* @return the factorial of a number
	*/
	double factorial(int number)
	{
		if (number < 0)
		{
			error("The factorial does not work with negative number.");
		}
		double result = 1;
		while (number)
		{
			result *= number;
			--number;
		}
		return result;
	}

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

	Token_stream token_stream;

	/*----------------------------------------------
		Implementation
	----------------------------------------------*/
	Token_stream::Token_stream()
		:full(false),
		buffer(Token('\0'))
	{}

	Token Token_stream::get()
	{
		if (full)
		{
			full = false;
			return buffer;
		}
		return get_token();
	}

	void Token_stream::putback(Token token)
	{
		if (full) error("putback(): buffer is full");
		buffer = token;
		full = true;
	}

	Token get_token()
	{
		char ch;
		cin >> ch;							// note that >> skips whitespace (space, newline, tab, etc.)

		switch (ch) {
		case DISPLAY_SYMBOL:				// for "print"
		case EXIT_SYMBOL:					// for "quit"
		case '{':
		case '}':
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '!':
		{
			return Token(ch);				// let each character represent itself
		}
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.putback(ch);				// put digit back into the input stream
			double val;
			cin >> val;						// read a floating-point number
			return Token('8', val);		// let '8' represent "a number"
		}
		default:
			error("Bad token");
		}
	}

	double expression()
	{
		double left = term();
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case '+':
			{
				left += term();
				token = token_stream.get();
				break;
			}
			case '-':
			{
				left -= term();
				token = token_stream.get();
				break;
			}
			default:
				token_stream.putback(token);
				return left;
			}
		}
	}

	double term()
	{
		double left = primary();
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case '*':
			{
				left *= primary();
				token = token_stream.get();
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
				token = token_stream.get();
				break;
			}
			default:
				token_stream.putback(token);
				return left;
			}
		}
	}

	double check_token_to_factorial(double value)
	{
		double left = value;
		Token token = token_stream.get();
		if (token.kind == '!')
		{
			return factorial(left);
		}
		else
		{
			token_stream.putback(token);
			return left;
		}
	}

	double primary()
	{
		Token token = token_stream.get();
		while (true) {
			switch (token.kind)
			{
			case '{':
			{
				double d = expression();
				token = token_stream.get();
				if (token.kind != '}')
				{
					error("required '}'\n");
				}
				return check_token_to_factorial(d);
				return d;
			}
			case '(':
			{
				double d = expression();
				token = token_stream.get();
				if (token.kind != ')')
				{
					error("required ')'\n");
				}
				return check_token_to_factorial(d);
				return d;
			}
			case '8':
			{
				return check_token_to_factorial(token.value);
			}
			default:
				error("primary expression required\n");
			}
		}
	}
}

int CH6P264EXERC3RunExmple::excute()
{
	try
	{
		cout << "Welcome to the calculator!\nEnter floating point expressions.\n";
		cout << "The following operations are available:\n"
			<< "1. Algebraic operations: '+', '-', '*', '/', '(', ')', '!';\n"
			<< "2. Operation display result: '=';\n"
			<< "3. Command to exit the program: 'x'.\n";
		double val = 0;
		while (cin)
		{
			Token token = token_stream.get();
			if (token.kind == EXIT_SYMBOL) break; // exit from program
			if (token.kind == DISPLAY_SYMBOL)
			{
				cout << "= " << val << '\n';
			}
			else
			{
				token_stream.putback(token);
			}
			val = expression();
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
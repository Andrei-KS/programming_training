/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/10/2021 00:15:43
	author                                       : Andrei-KS
*/

#include "CH6P265EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH6P265EXERC7RunExmple();

namespace {
	// A grammar for bitwise logical expressions.
	// 
	// operations priority:
	// 1. '(', ')', '{', '}'
	// 2. '~', '!
	// 3. '&'
	// 4. '^'
	// 5. '|'
	// 
	// expression_or:
	//		expression_xor
	//		expression_xor | expression_or
	// 
	// expression_xor:
	//		expression_and
	//		expression_and ^ expression_xor
	// 
	// expression_and:
	//		expression_complement
	//		expression_complement & expression_and
	// 
	// expression_unary:
	//		primary
	//		~ expression_unary
	//		! expression_unary
	// 
	// primary:
	//		number
	//		( expression_or )
	//		~ primary
	//		! primary
	// 
	constexpr char EXIT_SYMBOL		= 'q';
	constexpr char DISPLAY_SYMBOL	= '=';
	int expression_or();
	int expression_xor();
	int expression_and();
	int primary();

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
		int value;

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
		Token(char ch, int val) :kind(ch), value(val) { }
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
		char ch;
		cin >> ch;							// note that >> skips whitespace (space, newline, tab, etc.)

		switch (ch)
		{
		case EXIT_SYMBOL:					// for "quit"
		case DISPLAY_SYMBOL:				// for "print"
		case '!':
		case '~':
		case '&':
		case '^':
		case '|':
		case '(':
		case ')':
		case '{':
		case '}':
			return Token(ch);
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
			cin.putback(ch);
			int val;
			cin >> val;
			return Token('8', val);
		}
		default:
			error("Bad token");
			break;
		}
	}

	void Token_stream::putback(Token token)
	{
		if (full) error("putback(): buffer is full");
		buffer = token;
		full = true;
	}

	int expression_or()
	{
		int left = expression_xor();
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case '|':
			{
				left |= expression_or();
				token = token_stream.get();
				break;
			}
			default:
				token_stream.putback(token);
				return left;
			}
		}
	}

	int expression_xor()
	{
		int left = expression_and();
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case '^':
			{
				left ^= expression_xor();
				token = token_stream.get();
				break;
			}
			default:
				token_stream.putback(token);
				return left;
			}
		}
	}

	int expression_and()
	{
		int left = primary();
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case '&':
			{
				left &= expression_and();
				token = token_stream.get();
				break;
			}
			default:
				token_stream.putback(token);
				return left;
			}
		}
	}

	int primary()
	{
		Token token = token_stream.get();
		switch (token.kind)
		{
		case '!':
		{
			return primary() == 0 ? 0xFFFF : 0x0000;
		}
		case '~':
		{
			return primary() ^ 0xFFFF;
		}
		case '{':
		{
			int d = expression_or();
			token = token_stream.get();
			if (token.kind != '}')
			{
				error("required '}'\n");
			}
			return d;
		}
		case '(':
		{
			int d = expression_or();
			token = token_stream.get();
			if (token.kind != ')')
			{
				error("required ')'\n");
			}
			return d;
		}
		case '8':
		{
			return token.value;
		}
		default:
			error("primary expression required\n");
		}

	}
}

int CH6P265EXERC7RunExmple::excute()
{
	try
	{
		int val = 0;
		while (cin)
		{
			Token token = token_stream.get();
			if (token.kind == EXIT_SYMBOL) break; // exit from program
			if (token.kind == DISPLAY_SYMBOL)
			{
				int mask = 0x8000;
				cout << "= ";
				while (mask)
				{
					cout << ((mask & val) ? 1 : 0);
					mask = mask >> 1;
				}
				cout << '\n';
			}
			else
			{
				token_stream.putback(token);
			}
			val = expression_or();
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
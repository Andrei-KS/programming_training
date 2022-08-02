/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 12/21/2021 10:40:18
	author														: Andrei-KS
	source code link											: https://www.stroustrup.com/Programming/calculator08buggy.cpp
*/

/*
	Simple calculator
	This program implements a basic expression calculator.
	Input from cin; output to cout.
	The grammar for input is:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement

	Statement:
		Declaration
		Expression

	Declaration:
		"let" Name "=" Expression

	Print :
		;

	Quit:
		q

	Expression :
		Term
		Expression + Term
		Expression — Term

	Term :
		Primary
		Term * Primary
		Term / Primary
		Term % Primary

	Primary :
		Expression!
		Number
		(Expression)
		{Expression}
		— Primary
		+ Primary
		FunctionOne(Expression)
		FunctionTwo(Expression,Expression)
		Name = Expression
		Name

	FunctionOne:
		sqrt

	FunctionTwo:
		pow

	Number :
		floating_point_literal

	Input comes from cin through the Token_stream called token_stream.
*/

/*
	Tests:
	1;				// 1
	1!;			// 1
	2!;			// 2
	1+2;			// 3
	1+3;			// 4
	2*3;			// 6
	(1+3)*3;		// 12
	(2!)!			//	2
	(3!)!			// 720
	2 3;			// error: expression is not complete
	-2;			// -2
	-2*3;			// -6
	-2*-3;		// 6
	2/4;			//	0.5
	(2/3)!;		//	error: info lost
*/
#include "CH8P300EXERC1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P300EXERC1RunExmple();

namespace {
	/*----------------------------------------------
	Declaration
	----------------------------------------------*/
	// Definition of kinds
	constexpr char QUIT_KIND = 'Q';
	constexpr char PRINT_KIND = 'P';
	constexpr char NUMBER_KIND = '8';	// we use ‘8’ to represent a number
	constexpr char NAME_KIND = 'a';
	constexpr char LET_KIND = 'L';
	constexpr char SQRT_KIND = '1';
	constexpr char POW_KIND = '2';
	constexpr char HELP_KIND = 'H';


	// Definition of symbols
	constexpr char QUIT_SYMBOL = 'q';
	constexpr char HELP_SYMBOL = 'h';
	constexpr char PRINT_SYMBOL = ';';

	// Definition of keywords
	const string DECL_KEY = "#";
	const string CONSTDECL_KEY = "const";
	const string QUIT_KEY = "exit";
	const string SQRT_KEY = "sqrt";
	const string POW_KEY = "pow";
	const string HELPING_KEY = "help";

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

		/* for string tokens: name */
		string name;

		/*
		* Make a Token from a char
		* @param ch - defines the kind of token to be created
		*/
		Token(char ch) :kind(ch), value(0), name("") { }

		/*
		* Make a Token from a char and a double
		* @param ch - defines the kind of token to be created
		* @param val - defines the value of token to be created
		*/
		Token(char ch, double val) :kind(ch), value(val), name("") { }

		/*
		* Make a Token from a char and a double
		* @param ch - defines the kind of token to be created
		* @param name - defines the name of token to be created
		*/
		Token(char ch, string name) :kind(ch), value(0), name(name) { }
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
		* Creates an object of the Token Stream.
		* @param st - a stream that gives data for processing
		*/
		Token_stream(istream& st);

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

		/*
		* @param c - discard characters up to and including a c
		*/
		void ignore(char c);

	private:
		/* buffer busy indicator */
		bool full;

		/* the token is stored after returning with putback() */
		Token buffer;

		/*  */
		istream* stream;
	};

	/*
	*
	*/
	class Variable
	{
	public:
		/* */
		string name;

		/* */
		double value;

		/* */
		bool constancy;

		/*
		*
		*/
		Variable(string n, double v, bool c)
			:name(n),
			value(v),
			constancy(c)
		{ }
	};

	/*
	*
	* @see Variable
	*/
	class Symbol_table
	{
	private:
		/* table contains all declared variables */
		vector<Variable> var_table;

	public:
		/*
		* @param name - name of returned value
		* @return the value of the Variable named name
		*/
		double get(string name);

		/*
		* set the Variable named s to d
		* @param name - the name of the variable to which the value will be assigned
		* @param value - the value that will be assigned to the variable named name
		*/
		void set(string name, double value);

		/*
		* add {var, val, constancy} to var_table
		* @param var - name of variable that will add to var_table
		* @param val - value of variable that will add to var_table
		* @param constancy - determines the possibility of changing
		* this variable in the future
		* @return val
		*/
		double declare(string var, double val, bool constancy);

		/*
		* @return true if var is already in var_table, otherwise false
		*/
		bool is_declared(string var);
	};

	/*
	* Makes a check if the next character is a factorial sign.
	* @param value - the number to which the factorial sign can be applied
	* @param ts - a stream that gives token for processing
	* @return if the next sign of the factorial then returns the factorial
	* of the value, otherwise it returns the value
	*/
	double check_token_to_factorial(double value, Token_stream& ts);

	/*
	* Work with numbers and brackets.
	* Calls the primary and get_token functions
	* @param ts - a stream that gives tokens for processing
	* @return double value
	* @see get_token, expression
	*/
	double primary(Token_stream& ts);

	/*
	* Work with operation '*', '/' and '%'
	* Calls the primary and get_token functions
	* @param ts - a stream that gives tokens for processing
	* @return double value
	* @see get_token, primary
	*/
	double term(Token_stream& ts);

	/*
	* Works with operations '+' and '-'.
	* Calls the term and get_token functions
	* @param ts - a stream that gives tokens for processing
	* @return double value
	* @see get_token, term
	*/
	double expression(Token_stream& ts);

	/*
	* assume we have seen "let”
	* handle: name = expression
	* declare a variable called "name” with the initial value "expression”
	* @param ts - a stream that gives tokens for processing
	* @return double value equal a declared variable
	* @see expression, Symbol_table
	*/
	double declaration(Token_stream& ts);

	/*
	* @param ts - a stream that gives tokens for processing
	* @return double value
	* @see expression
	*/
	double statement(Token_stream& ts);

	/*
	* factorial does not work with numbers that have a fractional part
	* @param number - the factorial of this number will be returned
	* @return the factorial of a number
	*/
	double factorial(int number);

	/*
	* factorial does not work with numbers that have a fractional part
	* @param number - the factorial of this number will be returned
	* @return the factorial of a number
	*/
	double factorial(double number);

	/*
	* Expression evaluation loop
	*/
	void calculate();

	/*----------------------------------------------
		Implementation
	----------------------------------------------*/
	Symbol_table symbol_table;

	Token_stream::Token_stream()
		:full(false),
		buffer(Token('\0')),
		stream(&cin)
	{}

	Token_stream::Token_stream(istream& st)
		:full(false),
		buffer(Token('\0')),
		stream(&st)
	{}

	Token Token_stream::get()
	{
		if (full)
		{
			full = false;
			return buffer;
		}
		char ch;
		// note if not use noskipws then >> skips whitespace symbols
		// (space, newline, tab, etc.)
		(*stream) >> noskipws >> ch;

		while (true) {
			switch (ch) {
			case '{':
			case '}':
			case '(':
			case ')':
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '!':
			case '=':
			case ',':
				{
					// let each character represent itself
					return Token(ch);
				}
			case QUIT_SYMBOL:
				{
					return Token(QUIT_KIND);
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
					// put digit back into the input stream
					(*stream).putback(ch);
					double val;
					(*stream) >> val;

					// let '8' represent "a number"
					return Token(NUMBER_KIND, val);
				}
			default:
				{
					if (ch == '#')
					{
						return Token(LET_KIND, ch);
					}
					if (isalpha(ch))
					{
						string s;
						s += ch;
						while ((*stream).get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
						{
							s += ch;
						}
						(*stream).putback(ch);

						// Checking of the declaration keyword
						if (s == CONSTDECL_KEY)
						{
							return Token(LET_KIND, s);
						}
						if (s == SQRT_KEY)
						{
							return Token(SQRT_KIND, s);
						}
						if (s == POW_KEY)
						{
							return Token(POW_KIND, s);
						}
						if (s == HELPING_KEY || (s.size() == 1 && tolower(s[0]) == HELP_SYMBOL))
						{
							return Token(HELP_KIND);
						}
						if (s == QUIT_KEY || (s.size() == 1 && tolower(s[0]) == QUIT_SYMBOL))
						{
							return Token(QUIT_KIND);
						}
						return Token(NAME_KIND, s);
					}
					if (ch == '\n' || ch == PRINT_SYMBOL)
					{
						return Token(PRINT_KIND);
					}
					if (isspace(ch))
					{
						(*stream) >> noskipws >> ch;
						continue;
					}
					error("Bad token");
				}
			}
		}
	}

	void Token_stream::putback(Token token)
	{
		if (full) error("putback(): buffer is full");
		buffer = token;
		full = true;
	}

	void Token_stream::ignore(char c)
	{
		if (full && c == buffer.kind)
		{
			full = false;
			return;
		}
		full = false;

		char ch = 0;
		while ((*stream) >> noskipws >> ch)
		{
			if (ch == c || ch == '\n')
			{
				return;
			}
		}
	}

	double Symbol_table::get(string name)
	{
		for (const Variable& v : var_table)
		{
			if (v.name == name)
			{
				return v.value;
			}
		}
		error("get: undefined name ", name);
	}

	void Symbol_table::set(string name, double value)
	{
		for (Variable& v : var_table)
		{
			if (v.name == name)
			{
				if (v.constancy)
				{
					error("set: '" + name + "' is const\n");
				}
				v.value = value;
				return;
			}
		}
		error("set: undefined variable ", name);
	}

	double Symbol_table::declare(string var, double val, bool constancy)
	{
		if (is_declared(var))
		{
			error(var, " declared twice");
		}
		var_table.push_back(Variable{ var, val, constancy, });
		return val;
	}

	bool Symbol_table::is_declared(string var)
	{
		for (const Variable& v : var_table)
		{
			if (v.name == var)
			{
				return true;
			}
		}
		return false;
	}

	double check_token_to_factorial(double value, Token_stream& ts)
	{
		double left = value;
		Token token = ts.get();
		if (token.kind == '!')
		{
			return check_token_to_factorial(factorial(left), ts);
		}
		else
		{
			ts.putback(token);
			return left;
		}
	}

	double primary(Token_stream& ts)
	{
		Token token = ts.get();
		while (true) {
			switch (token.kind)
			{
			case SQRT_KIND:
				{
					token = ts.get();
					if (token.kind != '(')
					{
						error("SQRT_KIND: required '('\n");
					}

					double value = expression(ts);
					if (value < 0)
					{
						error("SQRT_KIND: value < 0\n");
					}

					token = ts.get();
					if (token.kind != ')')
					{
						error("SQRT_KIND: required ')'\n");
					}

					return sqrt(value);
				}
			case POW_KIND:
				{
					token = ts.get();
					if (token.kind != '(')
					{
						error("POW_KIND: required '('\n");
					}

					double value = expression(ts);

					token = ts.get();
					if (token.kind != ',')
					{
						error("POW_KIND: required ','\n");
					}

					int order = narrow_cast<int>(expression(ts));

					token = ts.get();
					if (token.kind != ')')
					{
						error("POW_KIND: required ')'\n");
					}

					return pow(value, order);
				}
			case '{':
				{
					double d = expression(ts);
					token = ts.get();
					if (token.kind != '}')
					{
						error("{: required '}'\n");
					}
					return check_token_to_factorial(d, ts);
				}
			case '(':
				{
					double d = expression(ts);
					token = ts.get();
					if (token.kind != ')')
					{
						error("(: required ')'\n");
					}
					return check_token_to_factorial(d, ts);
				}
			case NUMBER_KIND:
				{
					return check_token_to_factorial(token.value, ts);
				}
			case '-':
				{
					return -check_token_to_factorial(primary(ts), ts);
				}
			case '+':
				{
					return check_token_to_factorial(primary(ts), ts);
				}
			case NAME_KIND:
				{
					string name = token.name;
					token = ts.get();
					if (token.kind == '=')
					{
						if (!symbol_table.is_declared(name))
						{
							error(name, "is not declared.\n");
						}
						symbol_table.set(name, expression(ts));
					}
					else
					{
						ts.putback(token);
					}
					return check_token_to_factorial(symbol_table.get(name), ts);
				}
			default:
				error("primary expression required.");
			}
		}
	}

	double term(Token_stream& ts)
	{
		double left = primary(ts);
		Token token = ts.get();
		while (true)
		{
			switch (token.kind)
			{
			case '*':
				{
					left *= primary(ts);
					token = ts.get();
					break;
				}
			case '/':
				{
					double d = primary(ts);
					if (d == 0)
					{
						error("/: division by zero");
					}
					left /= d;
					token = ts.get();
					break;
				}
			case '%':
				{
					double d = primary(ts);
					if (d == 0) error("%: division by zero");
					left = fmod(left, d);	//need include <cmath> for fmod 
					break;
				}
			default:
				ts.putback(token);
				return left;
			}
		}
	}

	double expression(Token_stream& ts)
	{
		double left = term(ts);
		Token token = ts.get();
		while (true)
		{
			switch (token.kind)
			{
			case '+':
				{
					left += term(ts);
					token = ts.get();
					break;
				}
			case '-':
				{
					left -= term(ts);
					token = ts.get();
					break;
				}
			default:
				ts.putback(token);
				return left;
			}
		}
	}

	double declaration(Token_stream& ts)
	{
		Token token = ts.get();
		bool constancy = token.name == "const";

		token = ts.get();
		if (token.kind != NAME_KIND)
		{
			error("name expected in declaration");
		}
		string var_name = token.name;

		Token token2 = ts.get();
		if (token2.kind != '=')
		{
			error("= missing in declaration of ", var_name);
		}

		double d = expression(ts);
		symbol_table.declare(var_name, d, constancy);
		return d;
	}

	double statement(Token_stream& ts)
	{
		Token token = ts.get();
		switch (token.kind)
		{
		case LET_KIND:
			{
				ts.putback(token);
				return declaration(ts);
			}
		default:
			ts.putback(token);
			return expression(ts);
		}
	}

	void clean_up_mess(Token_stream& ts)
	{
		ts.ignore(PRINT_SYMBOL);
	}

	void dispay_help_inforamtion()
	{
		cout << "The following options are available:\n"
			<< "1. Display help information: 'h'/\"help\".\n"
			<< "2. Algebraic operations: '+', '-', '*', '/', '(', ')', '!';\n"
			<< "3. Declaration: '"<< DECL_KEY << '\'' << ", '" << CONSTDECL_KEY << "';\n"
			<< "4. Operation display result: '" << PRINT_SYMBOL << "';\n"
			<< "5. Command to exit the program: '" << QUIT_SYMBOL << "'/\"" << QUIT_KEY << "\" .\n";
	}

	void calculate()
	{
		istream& cstream = cin;
		Token_stream ts(cstream);
		const string PROMPT = "> ";
		const string RESULT = "= ";
		bool statementDone = false;
		cout << "Welcome to the calculator!\nEnter floating point expressions.\n";
		dispay_help_inforamtion();

		while (cstream)
		{
			cout << PROMPT;
			Token token = ts.get();
			while (token.kind == PRINT_KIND)
			{
				token = ts.get();
				statementDone = false;
			}
			if (token.kind == HELP_KIND)
			{
				dispay_help_inforamtion();
				continue;
			}
			if (token.kind == QUIT_KIND)
			{
				return;
			}
			ts.putback(token);
			try
			{
				if (statementDone)
				{
					error("expression is not complete");
				}
				cout << RESULT << statement(ts) << '\n';
				statementDone = true;
			}
			catch (exception& e)
			{
				cerr << e.what() << '\n';
				clean_up_mess(ts);
			}
		}
	}

	double factorial(double number)
	{
		return factorial(narrow_cast<int>(number));
	}

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
}

int CH8P300EXERC1RunExmple::excute()
{
	try
	{
		// predefine names:
		symbol_table.declare("pi", 3.1415926535, true);
		symbol_table.declare("e", 2.7182818284, true);
		symbol_table.declare("k", 1000, false);

		calculate();

		keep_window_open();
		return 0;
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
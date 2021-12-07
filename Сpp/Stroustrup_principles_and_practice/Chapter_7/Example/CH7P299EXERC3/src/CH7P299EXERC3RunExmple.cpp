/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/02/2021 09:58:34
	author                                       : Andrei-KS
	source code link										: https://www.stroustrup.com/Programming/calculator08buggy.cpp
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

#include "CH7P299EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH7P299EXERC3RunExmple();

namespace {
	/*----------------------------------------------
	Declaration
	----------------------------------------------*/
	// Definition of kinds
	constexpr char QUIT_KIND		= 'Q';
	constexpr char PRINT_KIND		= ';';
	constexpr char NUMBER_KIND		= '8';	// we use ‘8’ to represent a number
	constexpr char NAME_KIND		= 'a';
	constexpr char LET_KIND			= 'L';
	constexpr char SQRT_KIND		= '1';
	constexpr char POW_KIND			= '2';


	// Definition of symbols
	constexpr char QUIT_SYMBOL		= 'q';
	constexpr char PRINT_SYMBOL	= PRINT_KIND;

	// Definition of keywords
	const string DECLKEY				= "#";
	const string CONSTDECLKEY		= "const";
	const string QUITKEY				= "exit";
	const string SQRTKEY				= "sqrt";
	const string POWKEY				= "pow";

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
	* @param name - name of returned value
	* @return the value of the Variable named name
	*/
	double get_value(string name);

	/*
	* set the Variable named s to d
	* @param name - the name of the variable to which the value will be assigned
	* @param value - the value that will be assigned to the variable named name
	*/
	void set_value(string name, double value);

	/*
	* add {var,val} to var_table
	* @param var - name of variable that will add to var_table
	* @param val - value of variable that will add to var_table
	* @return val
	*/
	double define_name(string var, double val);

	/*
	* @return true if var is already in var_table, otherwise false
	*/
	bool is_declared(string var);

	/*
	* Makes a check if the next character is a factorial sign.
	* @param value - the number to which the factorial sign can be applied
	* @return if the next sign of the factorial then returns the factorial
	* of the value, otherwise it returns the value
	*/
	double check_token_to_factorial(double value);

	/*
	* Work with numbers and brackets.
	* Calls the primary() and get_token() functions
	* @return double value
	* @see get_token(), expression()
	*/
	double primary();

	/*
	* Work with operation '*', '/' and '%'
	* Calls the primary() and get_token() functions
	* @return double value
	* @see get_token(), primary()
	*/
	double term();

	/*
	* Works with operations '+' and '-'.
	* Calls the term() and get_token() functions
	* @return double value
	* @see get_token(), term()
	*/
	double expression();

	/*
	* assume we have seen "let”
	* handle: name = expression
	* declare a variable called "name” with the initial value "expression”
	*/
	double declaration();

	/*
	* @return double value
	* @see expression()
	*/
	double statement();

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
	Token_stream token_stream;
	vector<Variable> var_table;

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
		cin >> ch;							// note that >> skips whitespace
												// (space, newline, tab, etc.)

		switch (ch) {
		case PRINT_SYMBOL:
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
				cin.putback(ch);							// put digit back into the input stream
				double val;
				cin >> val;									// read a floating-point number
				return Token(NUMBER_KIND, val);		// let '8' represent "a number"
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
					while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
					{
						s += ch;
					}
					cin.putback(ch);

					// Checking of the declaration keyword
					if (s == CONSTDECLKEY)
					{
						return Token(LET_KIND, s);
					}
					if (s == SQRTKEY)
					{
						return Token(SQRT_KIND, s);
					}
					if (s == POWKEY)
					{
						return Token(POW_KIND, s);
					}
					if (s == QUITKEY || (s.size() == 1 && s[0] == QUIT_SYMBOL))
					{
						return Token(QUIT_KIND);
					}
					return Token(NAME_KIND, s);
				}
				error("Bad token");
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
		while (cin >> ch)
		{
			if (ch == c)
			{
				return;
			}
		}
	}

	double get_value(string name)
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

	void set_value(string name, double value)
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

	double define_name(string var, double val, bool constancy)
	{
		if (is_declared(var))
		{
			error(var, " declared twice");
		}
		var_table.push_back(Variable{ var, val, constancy, });
		return val;
	}

	bool is_declared(string var)
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

	double check_token_to_factorial(double value)
	{
		double left = value;
		Token token = token_stream.get();
		if (token.kind == '!')
		{
			return check_token_to_factorial(factorial(left));
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
			case SQRT_KIND:
				{
					token = token_stream.get();
					if (token.kind != '(')
					{
						error("SQRT_KIND: required '('\n");
					}

					double value = expression();
					if (value < 0)
					{
						error("SQRT_KIND: value < 0\n");
					}

					token = token_stream.get();
					if (token.kind != ')')
					{
						error("SQRT_KIND: required ')'\n");
					}

					return sqrt(value);
				}
			case POW_KIND:
				{
					token = token_stream.get();
					if (token.kind != '(')
					{
						error("POW_KIND: required '('\n");
					}

					double value = expression();

					token = token_stream.get();
					if (token.kind != ',')
					{
						error("POW_KIND: required ','\n");
					}

					int order = narrow_cast<int>(expression());

					token = token_stream.get();
					if (token.kind != ')')
					{
						error("POW_KIND: required ')'\n");
					}

					return pow(value, order);
				}
			case '{':
				{
					double d = expression();
					token = token_stream.get();
					if (token.kind != '}')
					{
						error("required '}'\n");
					}
					return check_token_to_factorial(d);
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
				}
			case NUMBER_KIND:
				{
					return check_token_to_factorial(token.value);
				}
			case '-':
				{
					return -check_token_to_factorial(primary());
				}
			case '+':
				{
					return check_token_to_factorial(primary());
				}
			case NAME_KIND:
				{
					string name = token.name;
					token = token_stream.get();
					if (token.kind == '=')
					{
						if (!is_declared(name))
						{
							error(name, "is not declared.\n");
						}
						set_value(name, expression());
					}
					else
					{
						token_stream.putback(token);
					}
					return check_token_to_factorial(get_value(name));
				}
			default:
				error("primary expression required.\n");
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
						error("/: division by zero");
					}
					left /= d;
					token = token_stream.get();
					break;
				}
			case '%':
				{
					double d = primary();
					if (d == 0) error("%: division by zero");
					left = fmod(left, d);	//need include <cmath> for fmod 
					break;
				}
			default:
				token_stream.putback(token);
				return left;
			}
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

	double declaration()
	{
		Token token = token_stream.get();
		bool constancy = token.name == "const";
		
		token = token_stream.get();
		if (token.kind != NAME_KIND)
		{
			error("name expected in declaration");
		}
		string var_name = token.name;

		Token token2 = token_stream.get();
		if (token2.kind != '=')
		{
			error("= missing in declaration of ", var_name);
		}

		double d = expression();
		define_name(var_name, d, constancy);
		return d;
	}

	double statement()
	{
		Token token = token_stream.get();
		switch (token.kind)
		{
		case LET_KIND:
			{
				token_stream.putback(token);
				return declaration();
			}
		default:
			token_stream.putback(token);
			return expression();
		}
	}

	void clean_up_mess()
	{
		token_stream.ignore(PRINT_SYMBOL);
	}

	void calculate()
	{
		const string PROMPT = "> ";
		const string RESULT = "= ";
		bool statementDone = false;
		cout << "Welcome to the calculator!\nEnter floating point expressions.\n";
		cout << "The following operations are available:\n"
			<< "1. Algebraic operations: '+', '-', '*', '/', '(', ')', '!';\n"
			<< "2. Operation display result: '" << PRINT_SYMBOL << "';\n"
			<< "3. Command to exit the program: '" << QUIT_SYMBOL << "'/\"" << QUITKEY << "\" .\n";
		while (cin)
		{
			cout << PROMPT;
			Token token = token_stream.get();
			while (token.kind == PRINT_SYMBOL)
			{
				token = token_stream.get();
				statementDone = false;
			}
			if (token.kind == QUIT_KIND)
			{
				return;
			}
			token_stream.putback(token);
			try
			{
				if (statementDone)
				{
					error("expression is not complete");
				}
				cout << RESULT << statement() << '\n';
				statementDone = true;
			}
			catch (exception& e)
			{
				cerr << e.what() << '\n';
				clean_up_mess();
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

int CH7P299EXERC3RunExmple::excute()
{
	try
	{
		// predefine names:
		define_name("pi", 3.1415926535, true);
		define_name("e", 2.7182818284, true);
		define_name("k", 1000, false);

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
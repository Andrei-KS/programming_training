/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/12/2022 17:04:52
	author														: Andrei-KS
*/

/*
	Simple Roman calculator
	This program implements a basic expression calculator.
	Input from cin; output to cout.
	The grammar for input is:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement


	Print :
		;

	Quit:
		q

	Statement:
		Declaration
		Expression
		Logical expression

	Declaration:
		"let" Name "=" Expression

	Logical expression:
		Expression "==" Expression
		Expression "!=" Expression
		Expression "<"  Expression
		Expression "<=" Expression
		Expression ">"  Expression
		Expression ">=" Expression
	
	Expression:
		Term
		Expression "+" Term
		Expression "-" Term

	Logical Expression:


	Term:
		Primary
		Term "*" Primary
		Term "/" Primary

	Primary:
		Number
		(Expression)
		Name = Expression
		Name

	Number:
		Roman_int
*/

/*
	Test:
	I				// I
	I+I			//	II
	I+V			//	VI
	V+V			// X
	V-I			//	IV
	let alf=V	//	V
	alf			// V
	I > I			//	FLASE
	I >= I		//	TRUE
	I == I		// TRUE
*/
#include "CH10P378EXERC7RunExmple.h"
#include "std_lib_facilities.h"
#include "Roman_int.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P378EXERC7RunExmple();

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
	constexpr char HELP_KIND = 'H';
	constexpr char COMPARE_KIND = 'c';


	// Definition of symbols
	constexpr char QUIT_SYMBOL			= 'q';
	constexpr char HELP_SYMBOL			= 'h';
	constexpr char PRINT_SYMBOL		= ';';

	// Definition of keywords
	const string EQUAL_KEY				= "==";
	const string NO_EQUAL_KEY			= "!=";
	const string LESS_KEY				= "<";
	const string LESS_OR_EQUAL_KEY	= "<=";
	const string LARGER_KEY				= ">";
	const string LARGER_OR_EQUAL_KEY	= ">=";

	const string DECL_KEY				= "let";
	const string CONSTDECL_KEY			= "const";
	const string QUIT_KEY				= "exit";
	const string HELPING_KEY			= "help";
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
		Roman_int value;

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
		Token(char ch, Roman_int val) :kind(ch), value(val), name("") { }

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
		Roman_int value;

		/* */
		bool constancy;

		/*
		*
		*/
		Variable(string n, Roman_int v, bool c)
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
		Roman_int get(string name);

		/*
		* set the Variable named s to d
		* @param name - the name of the variable to which the value will be assigned
		* @param value - the value that will be assigned to the variable named name
		*/
		void set(string name, Roman_int value);

		/*
		* add {var, val, constancy} to var_table
		* @param var - name of variable that will add to var_table
		* @param val - value of variable that will add to var_table
		* @param constancy - determines the possibility of changing
		* this variable in the future
		* @return val
		*/
		Roman_int declare(string var, Roman_int val, bool constancy);

		/*
		* @return true if var is already in var_table, otherwise false
		*/
		bool is_declared(string var);
	};

	/*
	* Work with numbers and brackets.
	* Calls the primary() and get_token() functions
	* @return double value
	* @see get_token(), expression()
	*/
	Roman_int primary();

	/*
	* Work with operation '*', '/'
	* Calls the primary() and get_token() functions
	* @return double value
	* @see get_token(), primary()
	*/
	Roman_int term();

	/*
	* Works with operations '+' and '-'.
	* Calls the term() and get_token() functions
	* @return double value
	* @see get_token(), term()
	*/
	Roman_int expression();

	/*
	* The empty class that allows overriding operator<< and
	* print the calculating result for variable various types
	*/
	class Statement {
	};
	/*
	*/
	ostream& operator<<(ostream& ost, Statement statement);

	/*
	* Works with operations '==', '!=', '>', '>=', '<', and '<='.
	* Calls the expression() and get_token() functions
	* @return boolean value
	* @see get_token(), expression()
	*/
	bool logical_expression(const Roman_int& left, const Roman_int& right, const string& comparator_kind);

	/*
	* assume we have seen "let”
	* handle: name = expression
	* declare a variable called "name” with the initial value "expression”
	*/
	Roman_int declaration();

	/*
	* @return double value
	* @see expression()
	*/
	Roman_int statement();

	/*
	* Expression evaluation loop
	*/
	void calculate();

	/*----------------------------------------------
		Implementation
	----------------------------------------------*/
	Token_stream token_stream;
	Symbol_table symbol_table;

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
		// note if not use noskipws then >> skips whitespace symbols
		// (space, newline, tab, etc.)
		cin >> noskipws >> ch;

		while (true) {
			switch (ch) {
				case '=':
				{
					char ch2;
					if (cin.get(ch2) && ch2 == '=')
					{
						string s;
						s += ch;
						return  Token(COMPARE_KIND, s + ch2);
					}
					cin.putback(ch2);
				}
				case '(':
				case ')':
				case '+':
				case '-':
				case '*':
				case '/':
				{
					// let each character represent itself
					return Token(ch);
				}
				case '!':
				{
					if (cin.get(ch) && ch == '=')
					{
						return Token(COMPARE_KIND, "!=");
					}
					error("Bad token");
				}
				case '>':
				case '<':
				{
					string s;
					s += ch;
					char ch2;
					if (cin.get(ch2) && ch2 == '=')
					{
						return Token(COMPARE_KIND, s + ch2);
					}
					cin.putback(ch2);
					return Token(COMPARE_KIND, s);
				}
				case QUIT_SYMBOL:
				{
					return Token(QUIT_KIND);
				}
				default:
				{
					if (isalpha(ch))
					{
						string s;
						s += ch;
						while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
						{
							s += ch;
						}
						cin.putback(ch);

						if (Roman_int::is_valid(s))
						{
							return Token('8', Roman_int(s));
						}

						// Checking of the declaration keyword
						if (s == CONSTDECL_KEY || s == DECL_KEY)
						{
							return Token(LET_KIND, s);
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
						cin >> noskipws >> ch;
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
		while (cin >> noskipws >> ch)
		{
			if (ch == c || ch == '\n')
			{
				return;
			}
		}
	}

	Roman_int Symbol_table::get(string name)
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

	void Symbol_table::set(string name, Roman_int value)
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

	Roman_int Symbol_table::declare(string var, Roman_int val, bool constancy)
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

	Roman_int primary()
	{
		Token token = token_stream.get();
		while (true) {
			switch (token.kind)
			{
			case '(':
			{
				Roman_int d = expression();
				token = token_stream.get();
				if (token.kind != ')')
				{
					error("(: required ')'\n");
				}
				return d;
			}
			case NUMBER_KIND:
			{
				return token.value;
			}
			case NAME_KIND:
			{
				string name = token.name;
				token = token_stream.get();
				if (token.kind == '=')
				{
					if (!symbol_table.is_declared(name))
					{
						error(name, "is not declared.\n");
					}
					symbol_table.set(name, expression());
				}
				else
				{
					token_stream.putback(token);
				}
				return symbol_table.get(name);
			}
			default:
				error("primary expression required.\n");
			}
		}
	}

	Roman_int term()
	{
		Roman_int left = primary();
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
				Roman_int d = primary();
				if (d == 0)
				{
					error("/: division by zero");
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

	Roman_int expression()
	{
		Roman_int left = term();
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

	Roman_int declaration()
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

		Roman_int d = expression();
		symbol_table.declare(var_name, d, constancy);
		return d;
	}

	bool logical_expression(const Roman_int& left, const Roman_int& right, const string& comparator_kind)
	{
		if (comparator_kind == "==")
		{
			return left == right;
		}

		if (comparator_kind == "!=")
		{
			return left != right;
		}

		if (comparator_kind == ">")
		{
			return left > right;
		}

		if (comparator_kind == "<")
		{
			return left < right;
		}

		if (comparator_kind == ">=")
		{
			return left >= right;
		}

		if (comparator_kind == "<=")
		{
			return left <= right;
		}

		return false;
	}

	ostream& operator<<(ostream& ost, Statement statement)
	{
		Token token = token_stream.get();
		if (token.kind == LET_KIND)
		{
			token_stream.putback(token);
			return ost << declaration();
		}

		token_stream.putback(token);
		Roman_int left = expression();
		token = token_stream.get();
		if (token.kind == COMPARE_KIND)
		{
			char* result = (logical_expression(left, expression(), token.name) ? "TRUE" : "FALSE");
			return ost << result;
		}
		token_stream.putback(token);
		return ost << left;
	}

	void clean_up_mess()
	{
		token_stream.ignore(PRINT_SYMBOL);
	}

	void dispay_help_inforamtion()
	{
		cout << "The following operations are available:\n"
			<< "1. Display help information: 'h'/\"help\".\n"
			<< "2. Algebraic operations: '+', '-', '*', '/', '(', ')', '!';\n"
			<< "3. Operation display result: '" << PRINT_SYMBOL << "';\n"
			<< "4. Command to exit the program: '" << QUIT_SYMBOL << "'/\"" << QUIT_KEY << "\" .\n";
	}

	void calculate()
	{
		const string PROMPT = "> ";
		const string RESULT = "= ";
		bool statementDone = false;
		Statement statement;

		cout << "Welcome to the calculator!\nEnter floating point expressions.\n";
		dispay_help_inforamtion();

		while (cin)
		{
			cout << PROMPT;
			Token token = token_stream.get();
			while (token.kind == PRINT_KIND)
			{
				token = token_stream.get();
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
			token_stream.putback(token);
			try
			{
				if (statementDone)
				{
					error("expression is not complete");
				}
				cout << RESULT << statement << '\n';
				statementDone = true;
			}
			catch (exception& e)
			{
				cerr << e.what() << '\n';
				clean_up_mess();
			}
		}
	}
}

int CH10P378EXERC7RunExmple::excute()
{
	try
	{
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
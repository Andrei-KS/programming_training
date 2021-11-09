/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 11/07/2021 21:39:14
	author                                       : Andrei-KS
*/

#include "CH6P265EXERC6RunExmple.h"
#include "std_lib_facilities.h"
#include <cctype>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH6P265EXERC6RunExmple();

namespace {
	// Simple English grammar
	// 
	// Sentence:
	//		Simple sentence End sentence
	//		Simple sentence Conjunction Sentence
	// 
	// End sentence:
	//		"."
	// 
	// Simple sentence:
	// 	Article Noun Verb
	//		Noun Verb
	// 
	// Conjunction:
	//		"and"
	//		"or"
	//		"but"
	// 
	// Noun:
	//		"birds"
	//		"fish"
	//		"C++"
	// 
	// Verb:
	//		"rules"
	//		"fly"
	//		"swim"
	// 
	// Article:
	//		"the"
	//
	bool sentence();
	bool simple_sentence();

	constexpr char NONE_KIND			= 0;
	constexpr char CONJUNCTION_KIND	= 1;
	constexpr char NOUN_KIND			= 2;
	constexpr char VERB_KIND			= 3;
	constexpr char ARTICLE_KIND		= 4;
	constexpr char END_SENTENCE_KIND = 5;
	constexpr char TERMINATE_KIND		= 6;

	vector<string> conjunctions = {
		"and",
		"or",
		"but",
	};

	vector<string> nouns = {
		"birds",
		"fish",
		"C++",
	};

	vector<string> verbs = {
		"rules",
		"fly",
		"swim"
	};

	vector<string> articles = {
		"the",
		"The",
	};

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
		string value;

		/*
		* Make a Token from a char
		* @param ch - defines the kind of token to be created
		*/
		Token(char ch) :kind(ch), value("") { }

		/*
		* Make a Token from a char and a double
		* @param ch - defines the kind of token to be created
		* @param val - defines the value of token to be created
		*/
		Token(char ch, string val) :kind(ch), value(val) { }
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
		buffer(Token(NONE_KIND))
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

		if (ch == '|')
		{
			return Token(TERMINATE_KIND);
		}
		if (ch == '.')
		{
			return Token(END_SENTENCE_KIND);
		}
		if (isalpha(ch))
		{
			cin.putback(ch);
			string word;
			cin >> word;
			for (const string& w : conjunctions)
			{
				if (word == w)
				{
					return Token(CONJUNCTION_KIND, word);
				}
			}
			for (const string& w : nouns)
			{
				if (word == w)
				{
					return Token(NOUN_KIND, word);
				}
			}
			for (const string& w : verbs)
			{
				if (word == w)
				{
					return Token(VERB_KIND, word);
				}
			}
			for (const string& w : articles)
			{
				if (word == w)
				{
					return Token(ARTICLE_KIND, word);
				}
			}
		}

		error("Bad token");
	}

	void Token_stream::putback(Token token)
	{
		if (full) error("putback(): buffer is full");
		buffer = token;
		full = true;
	}

	bool sentence()
	{
		bool correct = simple_sentence();
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case CONJUNCTION_KIND:
			{
				return correct && simple_sentence();
			}
			case END_SENTENCE_KIND:
			{
				token_stream.putback(token);
				return correct;
			}
			default:
				token_stream.putback(token);
				return false;
			}
		}
	}

	bool simple_sentence()
	{
		Token token = token_stream.get();
		while (true)
		{
			switch (token.kind)
			{
			case ARTICLE_KIND:
			{
				token = token_stream.get();
				break;
			}
			case NOUN_KIND:
			{
				token = token_stream.get();
				return token.kind == VERB_KIND;
			}
			default:
				token_stream.putback(token);
				return false;
			}
		}
	}
}

int CH6P265EXERC6RunExmple::excute()
{
	try
	{
		bool isCorrect = false;
		while (cin)
		{
			Token token = token_stream.get();
			if (token.kind == TERMINATE_KIND) break; // exit from program
			if (token.kind == END_SENTENCE_KIND)
			{
				cout << "Sentence is " 
					<< (isCorrect? "correct" : "invalid") << ".\n";
				isCorrect = false;
			}
			isCorrect = sentence();
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
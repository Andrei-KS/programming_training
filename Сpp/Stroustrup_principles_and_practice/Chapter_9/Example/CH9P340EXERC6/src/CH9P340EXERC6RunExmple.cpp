/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/13/2022 07:29:57
	author                                       : Andrei-KS
*/

#include "CH9P340EXERC6RunExmple.h"
#include "std_lib_facilities.h"
#include "Chrono.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC6RunExmple();

namespace {
		/*----------------------------------------------
	Declaration
	----------------------------------------------*/
	/*
	* Class Book have members for the ISBN, title, author, and copyright date.
	* Also store data on whether or not the book is checked out.
	*/
	class Book
	{
	private:
		/* ISBNs have the form n-n-n-x where n is an integer and x is a digit or a letter. */
		string itsISBN;

		/* A title of book */
		string itsTitle;

		/* An author of book */
		string itsAuthor;

		/* A copyright date of book */
		Chrono::Date itsCopyrightDate;

		/* A field contains data about checking in/out of book.*/
		bool isCheckedIn;

		/*
		* A validation of data entered into a Book.
		* @return true if all is correct.
		* @see ISBN form
		*/
		bool is_valid() const;

	public:
		/* to throw as exception */
		class Invalid {};

		/* default constructor */
		Book();

		// the default copy operations are fine

		/* check for valid date and initialize */
		Book(const string& isbn, const string& title, const string& author, const Chrono::Date& copyrightDate);

		// nonmodifying operations:
		/* @return a ISBN of book */
		const string& isbn() const { return itsISBN; }

		/* @return a title of book */
		const string& title() const { return itsTitle; }

		/* @return a author of book */
		const string& author() const { return itsAuthor; }

		/* @return a copyright date of book */
		const Chrono::Date& copyrightDate() const { return itsCopyrightDate; }

		/*
		* Get data about checking in/out of book.
		* @return true if book is checked in.
		*/
		bool is_checked_in() const;


	};

	bool operator==(const Book& left, const Book& right);
	bool operator!=(const Book& left, const Book& right);
	
	std::ostream& operator<<(std::ostream& os, const Book& book);

	/*----------------------------------------------
	Implementation
	----------------------------------------------*/
	const Book& default_book()
	{
		static Book book = {
			"0-0-0-X",
			"",
			"",
			Chrono::Date::Date(2000,Chrono::Month::jan,1)
		};

		return book;
	}

	Book::Book()
		:itsISBN(default_book().isbn()),
		itsTitle(default_book().title()),
		itsAuthor(default_book().author()),
		itsCopyrightDate(default_book().copyrightDate()),
		isCheckedIn(default_book().is_checked_in())
	{}

	Book::Book(const string& isbn, const string& title, const string& author, const Chrono::Date& copyrightDate)
		:itsISBN(isbn),
		itsTitle(title),
		itsAuthor(author),
		itsCopyrightDate(copyrightDate),
		isCheckedIn(true)
	{
		if (!is_valid())
		{
			throw Invalid{};
		}
	}

	bool Book::is_valid() const
	{
		// ISBNs have the form n-n-n-x where n is an integer and x is a digit or a letter.
		int numberOfIsbnField = 1;
		for (size_t index = 0; index < itsISBN.size(); index++)
		{
			if (numberOfIsbnField > 4)
			{
				return false;
			}

			char symbol = itsISBN[index];
			if (symbol == '-')
			{
				numberOfIsbnField++;
				continue;
			}

			if (numberOfIsbnField == 4 && isalpha(symbol))
			{
				continue;
			}

			if (!isdigit(symbol))
			{
				return false;
			}
		}
		return true;
	}

	bool Book::is_checked_in() const
	{
		return isCheckedIn;
	}

	bool operator==(const Book& left, const Book& right)
	{
		return left.isbn() == right.isbn();
	}

	bool operator!=(const Book& left, const Book& right)
	{
		return !(left == right);
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		const int width = 15;
		return os << "Book info:\n"
			<< std::setw(width) << std::left << "Title" << ": " << book.title() << '\n'
			<< std::setw(width) << std::left << "Author" << ": " << book.author() << '\n'
			<< std::setw(width) << std::left << "ISBN" << ": " << book.isbn() << '\n'
			<< std::setw(width) << std::left << "Copyright Date" << ": " << book.copyrightDate() << '\n'
			<< std::setw(width) << std::left << "Checked in" << ": " << std::boolalpha << book.is_checked_in();
	}
}

int CH9P340EXERC6RunExmple::excute()
{
	Book book;
	Book book1("1-1-1-x", "1", "A", Chrono::Date());
	cout << book
		<< "\n" << book1;
	cout << '\n' << std::boolalpha << (book == book1);
	cout << '\n' << std::boolalpha << (book != book1);
	return 0;
}
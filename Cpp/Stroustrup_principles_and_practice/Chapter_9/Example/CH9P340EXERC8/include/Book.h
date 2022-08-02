#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>
#include "Chrono.h"

namespace MyLib
{
	using string = std::string;
	constexpr int WIDTH_NAME_FIELD_OSTREAM = 15;

	/*
	* An enum Genre specify its set of values
	* as symbolic constants. Where None corresponds to 0
	*/
	enum class Genre
	{
		None = 0,
		Fiction,
		Nonfiction,
		Periodical,
		Biography,
		Children,
	};

	/* The string array contain a string representation of genres */
	string Genre_string[];

	/*
		* Class Book have members for the ISBN, title, author, genre, and copyright date.
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

		/* A genre of book */
		Genre itsGenre;

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
		Book(const string& isbn, const string& title, const string& author, const Chrono::Date& copyrightDate, const Genre genre);

		// nonmodifying operations:
		/* @return a ISBN of book */
		const string& isbn() const { return itsISBN; }

		/* @return a title of book */
		const string& title() const { return itsTitle; }

		/* @return a author of book */
		const string& author() const { return itsAuthor; }

		/* @return a copyright date of book */
		const Chrono::Date& copyrightDate() const { return itsCopyrightDate; }

		/* @return a genre of book */
		const Genre& genre() const { return itsGenre; }

		/* @return a genre of book */
		const string& genre_str() const;

		/*
		* Get data about checking in/out of book.
		* @return true if book is checked in.
		*/
		bool is_checked_in() const;


	};

	bool operator==(const Book& left, const Book& right);
	bool operator!=(const Book& left, const Book& right);

	std::ostream& operator<<(std::ostream& os, const Book& book);
}

#endif // !__BOOK_H__
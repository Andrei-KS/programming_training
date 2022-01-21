#include "Book.h"
#include <ostream>
#include <iomanip>

namespace MyLib
{
	string Genre_string[] = {
	"None",
	"Fiction",
	"Nonfiction",
	"Periodical",
	"Biography",
	"Children",
	};

	const Book& default_book()
	{
		static Book book = {
			"0-0-0-X",
			"",
			"",
			Chrono::Date::Date(2000,Chrono::Month::jan,1),
			Genre::None,
		};

		return book;
	}

	Book::Book()
		:itsISBN(default_book().isbn()),
		itsTitle(default_book().title()),
		itsAuthor(default_book().author()),
		itsCopyrightDate(default_book().copyrightDate()),
		itsGenre(default_book().genre()),
		isCheckedIn(default_book().is_checked_in())
	{}

	Book::Book(const string& isbn, const string& title, const string& author, const Chrono::Date& copyrightDate, const Genre genre)
		:itsISBN(isbn),
		itsTitle(title),
		itsAuthor(author),
		itsCopyrightDate(copyrightDate),
		itsGenre(genre),
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

	const string& Book::genre_str() const
	{
		return Genre_string[static_cast<size_t>(genre())];
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
		const int width = WIDTH_NAME_FIELD_OSTREAM;
		return os << "Book info:\n"
			<< std::setw(width) << std::left << "Title" << ": " << book.title() << '\n'
			<< std::setw(width) << std::left << "Author" << ": " << book.author() << '\n'
			<< std::setw(width) << std::left << "Genre" << ": " << book.genre_str() << '\n'
			<< std::setw(width) << std::left << "ISBN" << ": " << book.isbn() << '\n'
			<< std::setw(width) << std::left << "Copyright Date" << ": " << book.copyrightDate() << '\n'
			<< std::setw(width) << std::left << "Checked in" << ": " << std::boolalpha << book.is_checked_in();
	}
}
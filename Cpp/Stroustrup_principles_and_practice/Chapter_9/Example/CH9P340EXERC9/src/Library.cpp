#include "Library.h"

namespace MyLib
{
	Library::Library()
		: itsBooks(),
		itsPatrons(),
		itsTransactions()
	{}

	bool Library::find(const Book& book, size_t& index) const
	{
		for (size_t index = 0; index < itsBooks.size(); index++)
		{
			if (itsBooks[index] == book)
			{
				return true;
			}
		}
		return false;
	}

	bool Library::find(const Patron& patron, size_t& index) const
	{
		for (size_t index = 0; index < itsPatrons.size(); index++)
		{
			if (itsPatrons[index] == patron)
			{
				return true;
			}
		}
		return false;
	}

	void Library::add_book(const Book& book)
	{
		size_t index = 0;
		if (!find(book, index))
		{
			itsBooks.push_back(book);
		}
	}

	void Library::add_patron(const Patron& patron)
	{
		size_t index = 0;
		if (!find(patron,index))
		{
			itsPatrons.push_back(patron);
		}
	}

	bool Library::is_book_checked_in(Book book) const
	{
		size_t index = 0;
		if (find(book, index))
		{
			return itsBooks[index].is_checked_in();
		}
		else
		{
			throw Invalid();
		}
	}

	bool Library::is_patron_valid(Patron patron) const
	{
		size_t index = 0;
		if (find(patron, index))
		{
			return itsPatrons[index].is_fee_paid();
		}

		return false;
	}

	Library::Transaction Library::get_book(Book book, Patron patron, Chrono::Date date) const
	{
		if (is_book_checked_in(book) && is_patron_valid(patron))
		{
			return Transaction{ book, patron, date };
		}
		else
		{
			throw Invalid{};
		}
		return Transaction{ Book(), Patron(), date };
	}

	vector<string> Library::get_patron_names_who_owe_fees() const
	{
		vector<string> ret;
		for (const Patron& patron : itsPatrons)
		{
			if (!patron.is_fee_paid())
			{
				ret.push_back(patron.name());
			}
		}
		return ret;
	}
}
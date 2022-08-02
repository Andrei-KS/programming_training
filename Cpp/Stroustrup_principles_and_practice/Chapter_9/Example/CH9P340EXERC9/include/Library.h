#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <vector>
#include "Book.h"
#include "Patron.h"
#include "Chrono.h"

namespace MyLib
{
	using namespace std;

	/*
	* Class Library have members for the Book, Patron and transaction vectors.
	* @see Book, Patron, Data
	*/
	class Library
	{
	public:
		/*
		* Transaction structure contains all information about library transaction
		*/
		struct Transaction
		{
			Book book;
			Patron patron;
			Chrono::Date data;
		};

	private:
		/* These all books are registered in this library */
		vector<Book> itsBooks;

		/* These all patrons are registered in this library */
		vector<Patron> itsPatrons;

		/* These all transactions is done */
		vector<Transaction> itsTransactions;

	public:
		/* to throw as exception */
		class Invalid {};

		/* default constructor */
		Library();

		// the default copy operations are fine

		/**/
		bool find(const Book& book, size_t& index) const;

		/**/
		bool find(const Patron& patron, size_t& index) const;

		// modifying operations:
		/*
		* Add book to the library
		* @param book - it will added to library
		*/
		void add_book(const Book& book);

		/*
		* Add patron to the library
		* @param patron - it will added to library
		*/
		void add_patron(const Patron& patron);


		// nonmodifying operations:
		/*
		* Get data about checking in/out of book.
		* @param book - this book will checked.
		* @return true if book is checked in.
		*/
		bool is_book_checked_in(Book book) const;

		/**/
		bool is_patron_valid(Patron patron) const;

		/**/
		Transaction get_book(Book book, Patron patron, Chrono::Date date) const;

		/**/
		vector<string> get_patron_names_who_owe_fees() const;
	};
}

#endif // !__LIBRARY_H__
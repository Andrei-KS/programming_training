/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/16/2022 13:28:45
	author                                       : Andrei-KS
*/

#include "CH9P340EXERC9RunExmple.h"
#include "Library.h"
#include <iostream>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC9RunExmple();

namespace {
}

int CH9P340EXERC9RunExmple::excute()
{
	MyLib::Library library;
	MyLib::Book book;
	library.add_book(book);
	std::cout << "Is book checked in in library? " << std::boolalpha << library.is_book_checked_in(book) << '\n';
	MyLib::Patron patron("Patron1", 1, 1);
	MyLib::Patron patron2("Patron2", 1, 1);
	patron.set_fee_paid(true);
	library.add_patron(patron);
	library.add_patron(patron2);
	MyLib::Library::Transaction transaction = library.get_book(book, patron, Chrono::Date(2022,Chrono::Month::jan,20));
	std::vector<std::string> names = library.get_patron_names_who_owe_fees();
	return 0;
}
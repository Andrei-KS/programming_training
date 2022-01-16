/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/16/2022 06:34:02
	author                                       : Andrei-KS
*/

#include "CH9P340EXERC7RunExmple.h"
#include "std_lib_facilities.h"
#include "Book.h"
#include "Chrono.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC7RunExmple();

namespace {
}

int CH9P340EXERC7RunExmple::excute()
{
	MyLib::Book book;
	MyLib::Book book1("1-1-1-x", "1", "A", Chrono::Date(),MyLib::Genre::Periodical);
	cout << book
		<< "\n" << book1;
	cout << '\n' << std::boolalpha << (book == book1);
	cout << '\n' << std::boolalpha << (book != book1);
	return 0;
}
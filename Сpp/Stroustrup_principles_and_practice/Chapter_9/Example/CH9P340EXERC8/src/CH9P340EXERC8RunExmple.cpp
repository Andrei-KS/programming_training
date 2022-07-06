/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 01/16/2022 07:38:57
	author														: Andrei-KS
*/

#include "CH9P340EXERC8RunExmple.h"
#include "std_lib_facilities.h"
#include "Patron.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC8RunExmple();

namespace {
}

int CH9P340EXERC8RunExmple::excute()
{
	MyLib::Patron patron;
	MyLib::Patron patron1("A", 1, 20);
	patron.set_fee_paid(true);
	return 0;
}
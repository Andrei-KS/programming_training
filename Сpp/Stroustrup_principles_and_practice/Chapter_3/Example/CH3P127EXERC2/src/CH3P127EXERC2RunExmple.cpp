/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 11:53:01
	author                                       : Andrei-KS
*/

#include "CH3P127EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P127EXERC2RunExmple();

namespace {
}

int CH3P127EXERC2RunExmple::excute()
{
	cout << "The program of converting ml to km.\n"
		<< "Please, entry ml value (and press 'Enter'):\n";
	double value_In_Ml;
	cin >> value_In_Ml;
	const double ML_TO_KM = 1.609;
	double value_In_Km = ML_TO_KM * value_In_Ml;
	cout << "Value in km: " << value_In_Km << "\n";
	return 0;
}


#include "ChangeClassificationTransaction.h"

ChangeClassificationTransaction::~ChangeClassificationTransaction()
{
}

ChangeClassificationTransaction::ChangeClassificationTransaction(int empId)
	: ChangeEmployeeTransaction(empId)
{
}

void ChangeClassificationTransaction::Change(Employee& e)
{
	e.SetClassification(GetClassification());
	e.SetSchedule(GetSchedule());
}

#include "..\..\header\Transaction\PaydayTransaction.h"


#include "../../header/Transaction/PaydayTransaction.h"
#include "../../header/Database/PayrollDatabase.h"
#include "../../header/Employee.h"
#include "../../header/Paycheck.h"

#include <list>

extern PayrollDatabase GpayrollDatabase;

PaydayTransaction::~PaydayTransaction()
{
	std::unordered_map<int, Paycheck*>::iterator it = itsPaychecks.begin();
	while (it != itsPaychecks.end())
	{
		delete it->second;
		it++;
	}
	itsPaychecks.clear();
}

PaydayTransaction::PaydayTransaction(const Date& date)
	: itsPayDate(date)
	, itsPaychecks(std::unordered_map<int, Paycheck*>())
{
}

void PaydayTransaction::Execute()
{
	std::list<int> empIds;
	GpayrollDatabase.GetAllEmployeeIds(empIds);

	std::list<int>::iterator it = empIds.begin();
	for (; it != empIds.end(); it++)
	{
		int empId = *it;
		if (Employee* e = GpayrollDatabase.GetEmployee(empId))
		{
			if (e->IsPayDay(itsPayDate))
			{
				Paycheck* pc = new Paycheck(itsPayDate);
				itsPaychecks[empId] = pc;
				e->Payday(*pc);
			}
		}
	}
}

Paycheck* PaydayTransaction::GetPaycheck(int empId) const
{
	std::unordered_map<int, Paycheck*>::const_iterator it = itsPaychecks.find(empId);
	if (it != itsPaychecks.end())
	{
		return it->second;
	}
	return nullptr;
}

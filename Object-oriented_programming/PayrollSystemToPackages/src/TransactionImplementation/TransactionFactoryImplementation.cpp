

#include "TransactionFactoryImplementation.h"
#include "AddCommissionedEmployee.h"
#include "AddHourlyEmployee.h"
#include "AddSalariedEmployee.h"
#include "DeleteEmployeeTransaction.h"
#include "Date/Date.h"
#include "PaydayTransaction.h"
#include "TimeCardTransaction.h"
#include "SalesReceiptTransaction.h"
#include "ChangeHourlyTransaction.h"
#include "ChangeCommissionedTransaction.h"
#include "ChangeSalariedTransaction.h"
#include "ChangeMailTransaction.h"
#include "ChangeDirectTransaction.h"
#include "ChangeHoldTransaction.h"
#include "ChangeMemberTransaction.h"
#include "ChangeUnaffiliatedTransaction.h"
#include "ChangeAddressTransaction.h"
#include "ChangeNameTransaction.h"

TransactionFactoryImplementation::TransactionFactoryImplementation()
{
}

TransactionFactoryImplementation::~TransactionFactoryImplementation()
{
}

Transaction* TransactionFactoryImplementation::makeAddCommissionedEmployee(int empId, std::string name,
	std::string address, double salary, double commissionRate)
{
	return new AddCommissionedEmployee(empId, name, address, salary, commissionRate);
}

Transaction* TransactionFactoryImplementation::makeAddHourlyEmployee(int empId, std::string name,
	std::string address, double hourlyRate)
{
	return new AddHourlyEmployee(empId, name, address, hourlyRate);
}

Transaction* TransactionFactoryImplementation::makeAddSalariedEmployee(int empId, std::string name,
	std::string address, double salary)
{
	return new AddSalariedEmployee(empId, name, address, salary);
}

Transaction* TransactionFactoryImplementation::makeDeleteEmployeeTransaction(int empId)
{
	return new DeleteEmployeeTransaction(empId);
}

Transaction* TransactionFactoryImplementation::makePaydayTransaction(const Date& date)
{
	return new PaydayTransaction(date);
}

Transaction* TransactionFactoryImplementation::makeTimeCardTransaction(const Date& date, double hours, int empId)
{
	return new TimeCardTransaction(date, hours, empId);
}

Transaction* TransactionFactoryImplementation::makeSalesReceiptTransaction(const Date& date, double amount, int empId)
{
	return new SalesReceiptTransaction(date, amount, empId);
}

Transaction* TransactionFactoryImplementation::makeChangeHourlyTransaction(int empId, double hourlyRate)
{
	return new ChangeHourlyTransaction(empId, hourlyRate);
}

Transaction* TransactionFactoryImplementation::makeChangeCommissionedTransaction(int empId, double salary, double commissionRate)
{
	return new ChangeCommissionedTransaction(empId, salary, commissionRate);
}

Transaction* TransactionFactoryImplementation::makeChangeSalariedTransaction(int empId, double salary)
{
	return new ChangeSalariedTransaction(empId, salary);
}

Transaction* TransactionFactoryImplementation::makeChangeMailTransaction(int empId, std::string address)
{
	return new ChangeMailTransaction(empId, address);
}

Transaction* TransactionFactoryImplementation::makeChangeDirectTransaction(int empId, std::string bank, std::string account)
{
	return new ChangeDirectTransaction(empId, bank, account);
}

Transaction* TransactionFactoryImplementation::makeChangeHoldTransaction(int empId)
{
	return new ChangeHoldTransaction(empId);
}

Transaction* TransactionFactoryImplementation::makeChangeMemberTransaction(int empId, int memberId, double dues)
{
	return new ChangeMemberTransaction(empId, memberId, dues);
}

Transaction* TransactionFactoryImplementation::makeChangeUnaffiliatedTransaction(int empId)
{
	return new ChangeUnaffiliatedTransaction(empId);
}

Transaction* TransactionFactoryImplementation::makeChangeAddressTransaction(int empId, std::string address)
{
	return new ChangeAddressTransaction(empId, address);
}

Transaction* TransactionFactoryImplementation::makeChangeNameTransaction(int empId, std::string name)
{
	return new ChangeNameTransaction(empId, name);
}
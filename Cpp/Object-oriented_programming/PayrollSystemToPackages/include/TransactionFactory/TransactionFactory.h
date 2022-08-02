#ifndef __TRANSACTIONFACTORY_H__
#define __TRANSACTIONFACTORY_H__

#include <string>

class Transaction;
class Date;

class TransactionFactory
{
public:
	TransactionFactory() {}
	virtual ~TransactionFactory() {}

	virtual Transaction* makeAddCommissionedEmployee(int empId, std::string name,
		std::string address, double salary, double commissionRate) = 0;
	virtual Transaction* makeAddHourlyEmployee(int empId, std::string name,
		std::string address, double hourlyRate) = 0;
	virtual Transaction* makeAddSalariedEmployee(int empId, std::string name,
		std::string address, double salary) = 0;
	virtual Transaction* makeDeleteEmployeeTransaction(int empId) = 0;
	virtual Transaction* makePaydayTransaction(const Date& date) = 0;

	virtual Transaction* makeTimeCardTransaction(const Date& date, double hours, int empId) = 0;
	virtual Transaction* makeSalesReceiptTransaction(const Date& date, double amount, int empId) = 0;
	virtual Transaction* makeChangeHourlyTransaction(int empId, double hourlyRate) = 0;
	virtual Transaction* makeChangeCommissionedTransaction(int empId, double salary, double commissionRate) = 0;
	virtual Transaction* makeChangeSalariedTransaction(int empId, double salary) = 0;

	virtual Transaction* makeChangeMailTransaction(int empId, std::string address) = 0;
	virtual Transaction* makeChangeDirectTransaction(int empId, std::string bank, std::string account) = 0;
	virtual Transaction* makeChangeHoldTransaction(int empId) = 0;
	virtual Transaction* makeChangeMemberTransaction(int empId, int memberId, double dues) = 0;
	virtual Transaction* makeChangeUnaffiliatedTransaction(int empId) = 0;
		
	virtual Transaction* makeChangeAddressTransaction(int empId, std::string address) = 0;
	virtual Transaction* makeChangeNameTransaction(int empId, std::string name) = 0;
};

#endif // !__TRANSACTIONFACTORY_H__
#ifndef __TRANSACTIONFACTORYIMPLEMENTATION_H__
#define __TRANSACTIONFACTORYIMPLEMENTATION_H__

#include "TransactionFactory/TransactionFactory.h"

class TransactionFactoryImplementation : public TransactionFactory
{
public:
	TransactionFactoryImplementation();
	virtual ~TransactionFactoryImplementation();

	virtual Transaction* makeAddCommissionedEmployee(int empId, std::string name,
		std::string address, double salary, double commissionRate) override;
	virtual Transaction* makeAddHourlyEmployee(int empId, std::string name,
		std::string address, double hourlyRate) override;
	virtual Transaction* makeAddSalariedEmployee(int empId, std::string name,
		std::string address, double salary) override;
	virtual Transaction* makeDeleteEmployeeTransaction(int empId) override;
	virtual Transaction* makePaydayTransaction(const Date& date) override;

	virtual Transaction* makeTimeCardTransaction(const Date& date, double hours, int empId) override;
	virtual Transaction* makeSalesReceiptTransaction(const Date& date, double amount, int empId) override;
	virtual Transaction* makeChangeHourlyTransaction(int empId, double hourlyRate) override;
	virtual Transaction* makeChangeCommissionedTransaction(int empId, double salary, double commissionRate) override;
	virtual Transaction* makeChangeSalariedTransaction(int empId, double salary) override;

	virtual Transaction* makeChangeMailTransaction(int empId, std::string address) override;
	virtual Transaction* makeChangeDirectTransaction(int empId, std::string bank, std::string account) override;
	virtual Transaction* makeChangeHoldTransaction(int empId) override;
	virtual Transaction* makeChangeMemberTransaction(int empId, int memberId, double dues) override;
	virtual Transaction* makeChangeUnaffiliatedTransaction(int empId) override;

	virtual Transaction* makeChangeAddressTransaction(int empId, std::string address) override;
	virtual Transaction* makeChangeNameTransaction(int empId, std::string name) override;
};

#endif // !__TRANSACTIONFACTORYIMPLEMENTATION_H__
#ifndef __ADDEMPLOYEETRANSACTION_H__
#define __ADDEMPLOYEETRANSACTION_H__

#include "TransactionApplication/Transaction.h"
#include <string>

class PaymentClassification;
class PaymentSchedule;
class PaymentMethod;

class AddEmployeeTransaction : public Transaction
{
public:
	virtual ~AddEmployeeTransaction();
	AddEmployeeTransaction(int empId, std::string name, std::string address);
	virtual PaymentClassification* GetClassification() const = 0;
	virtual PaymentSchedule* GetSchedule() const = 0;
	virtual PaymentMethod* GetMethod() const = 0;
	virtual void Execute() override;

private:
	int ItsEmpId;
	std::string itsName;
	std::string itsAddress;
};

#endif // !__ADDEMPLOYEETRANSACTION_H__
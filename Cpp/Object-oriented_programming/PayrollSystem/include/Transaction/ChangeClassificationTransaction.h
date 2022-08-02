#ifndef __CHANGECLASSIFICATIONTRANSACTION_H__
#define __CHANGECLASSIFICATIONTRANSACTION_H__

#include "ChangeEmployeeTransaction.h"

class PaymentClassification;
class PaymentSchedule;

class ChangeClassificationTransaction : public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeClassificationTransaction();
	ChangeClassificationTransaction(int empId);
	virtual void Change(Employee& e) override;
	virtual PaymentClassification* GetClassification() const = 0;
	virtual PaymentSchedule* GetSchedule() const = 0;
};

#endif // !__CHANGECLASSIFICATIONTRANSACTION_H__
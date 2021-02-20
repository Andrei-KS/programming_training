#ifndef __CHANGEHOURLYTRANSACTION_H__
#define __CHANGEHOURLYTRANSACTION_H__

#include "ChangeClassificationTransaction.h"

class ChangeHourlyTransaction : public ChangeClassificationTransaction
{
public:
	virtual ~ChangeHourlyTransaction();
	ChangeHourlyTransaction(int empId, double hourlyRate);
	virtual PaymentClassification* GetClassification() const override;
	virtual PaymentSchedule* GetSchedule() const override;

private:
	double itsHourlyRate;
};

#endif // !__CHANGEHOURLYTRANSACTION_H__
#ifndef __CHANGESALARIEDTRANSACTION_H__
#define __CHANGESALARIEDTRANSACTION_H__

#include "AbstractTransaction/ChangeClassificationTransaction.h"

class ChangeSalariedTransaction : public ChangeClassificationTransaction
{
public:
	virtual ~ChangeSalariedTransaction();
	ChangeSalariedTransaction(int empId, double salary);
	virtual PaymentClassification* GetClassification() const override;
	virtual PaymentSchedule* GetSchedule() const override;

private:
	double itsSalary;
};

#endif // !__CHANGESALARIEDTRANSACTION_H__

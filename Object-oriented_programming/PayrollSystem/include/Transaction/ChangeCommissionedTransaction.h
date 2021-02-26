#ifndef __ChangeCommissionedTransaction_H__
#define __ChangeCommissionedTransaction_H__

#include "ChangeClassificationTransaction.h"

class ChangeCommissionedTransaction : public ChangeClassificationTransaction
{
public:
	virtual ~ChangeCommissionedTransaction();
	ChangeCommissionedTransaction(int empId, double salary, double commissionRate);
	virtual PaymentClassification* GetClassification() const override;
	virtual PaymentSchedule* GetSchedule() const override;

private:
	double itsSalary;
	double itsCommissionRate;
};

#endif // !__ChangeCommissionedTransaction_H__



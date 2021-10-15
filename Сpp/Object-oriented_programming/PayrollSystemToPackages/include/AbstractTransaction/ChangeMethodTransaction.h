#ifndef __CHANGEMETHODTRANSACTION_H__
#define __CHANGEMETHODTRANSACTION_H__

#include "AbstractTransaction/ChangeEmployeeTransaction.h"

class PaymentMethod;

class ChangeMethodTransaction : public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeMethodTransaction();
	ChangeMethodTransaction(int empId);
	virtual void Change(Employee& e) override;
	virtual PaymentMethod* GetMethod() const = 0;
};

#endif // !__CHANGEMETHODTRANSACTION_H__
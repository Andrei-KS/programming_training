#ifndef __CHANGEHOLDTRANSACTION_H__
#define __CHANGEHOLDTRANSACTION_H__

#include "ChangeMethodTransaction.h"
#include <string>

class ChangeHoldTransaction : public ChangeMethodTransaction
{
public:
	virtual ~ChangeHoldTransaction();
	ChangeHoldTransaction(int empId);
	virtual PaymentMethod* GetMethod() const override;

};

#endif // !__CHANGEHOLDTRANSACTION_H__
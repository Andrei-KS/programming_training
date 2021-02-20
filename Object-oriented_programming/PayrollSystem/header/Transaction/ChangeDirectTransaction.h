#ifndef __CHANGEDIRECTTRANSACTION_H__
#define __CHANGEDIRECTTRANSACTION_H__

#include "ChangeMethodTransaction.h"
#include <string>

class ChangeDirectTransaction : public ChangeMethodTransaction
{
public:
	virtual ~ChangeDirectTransaction();
	ChangeDirectTransaction(int empId, std::string bank, std::string account);
	virtual PaymentMethod* GetMethod() const override;

private:
	std::string itsBank;
	std::string itsAccount;
};

#endif // !__CHANGEDIRECTTRANSACTION_H__
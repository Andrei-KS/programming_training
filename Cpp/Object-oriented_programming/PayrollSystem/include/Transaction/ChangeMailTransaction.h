#ifndef __CHANGEMAILTRANSACTION_H__
#define __CHANGEMAILTRANSACTION_H__

#include "ChangeMethodTransaction.h"
#include <string>

class ChangeMailTransaction : public ChangeMethodTransaction
{
public:
	virtual ~ChangeMailTransaction();
	ChangeMailTransaction(int empId, std::string address);
	virtual PaymentMethod* GetMethod() const override;

private:
	std::string itsAddress;
};

#endif // !__CHANGEMAILTRANSACTION_H__

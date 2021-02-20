#ifndef __CHANGEADDRESSTRANSACTION_H__
#define __CHANGEADDRESSTRANSACTION_H__

#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeAddressTransaction : public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeAddressTransaction();
	ChangeAddressTransaction(int empId, std::string address);
	virtual void Change(Employee& e) override;

private:
	std::string itsAddress;
};

#endif // !__CHANGEADDRESSTRANSACTION_H__
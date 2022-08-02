#ifndef __CHANGEEMPLOYEETRANSACTION_H__
#define __CHANGEEMPLOYEETRANSACTION_H__

#include "Transaction.h"
#include "../Employee.h"

class ChangeEmployeeTransaction : public Transaction
{
public:
	ChangeEmployeeTransaction(int empId);
	virtual ~ChangeEmployeeTransaction();
	virtual void Execute() override;
	virtual void Change(Employee& e) = 0;

private:
	int itsEmpId;
};

#endif // !__CHANGEEMPLOYEETRANSACTION_H__
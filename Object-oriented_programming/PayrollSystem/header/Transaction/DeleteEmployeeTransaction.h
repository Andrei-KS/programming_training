#ifndef __DELETEEMPLOYEETRANSACTION_H__
#define __DELETEEMPLOYEETRANSACTION_H__

#include "Transaction.h"

class DeleteEmployeeTransaction : public Transaction
{
public:
	virtual ~DeleteEmployeeTransaction();
	DeleteEmployeeTransaction(int empId);
	virtual void Execute() override;

private:
	int itsEmpId;

};

#endif // !__DELETEEMPLOYEETRANSACTION_H__
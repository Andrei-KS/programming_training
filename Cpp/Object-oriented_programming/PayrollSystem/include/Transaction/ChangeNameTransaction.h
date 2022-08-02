#ifndef __CHANGENAMETRANSACTION_H__
#define __CHANGENAMETRANSACTION_H__

#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeNameTransaction : public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeNameTransaction();
	ChangeNameTransaction(int empId, std::string name);
	virtual void Change(Employee& e) override;

private:
	std::string itsName;
};

#endif // !__CHANGENAMETRANSACTION_H__
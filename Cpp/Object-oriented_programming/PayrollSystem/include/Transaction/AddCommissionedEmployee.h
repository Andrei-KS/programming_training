#ifndef __ADDCOMMISSIONEDEMPLOYEE_H__
#define __ADDCOMMISSIONEDEMPLOYEE_H__

#include "AddEmployeeTransaction.h"

class AddCommissionedEmployee : public AddEmployeeTransaction
{
public:
	virtual ~AddCommissionedEmployee();
	AddCommissionedEmployee(int empId, std::string name,
		std::string address, double salary, double commissionRate);
	virtual PaymentClassification* GetClassification() const override;
	virtual PaymentSchedule* GetSchedule() const override;

private:
	double itsSalary;
	double itsCommissionRate;
};

#endif // !__ADDCOMMISSIONEDEMPLOYEE_H__
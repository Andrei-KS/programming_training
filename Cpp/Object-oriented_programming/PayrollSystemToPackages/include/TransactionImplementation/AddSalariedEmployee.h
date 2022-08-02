#ifndef __ADDSALARIEDEMPLOYEE_H__
#define __ADDSALARIEDEMPLOYEE_H__

#include "AbstractTransaction/AddEmployeeTransaction.h"

class AddSalariedEmployee : public AddEmployeeTransaction
{
public:
	virtual ~AddSalariedEmployee();
	AddSalariedEmployee(int empId, std::string name,
							std::string address, double salary);
	virtual PaymentClassification* GetClassification() const override;
	virtual PaymentSchedule* GetSchedule() const override;
	virtual PaymentMethod* GetMethod() const override;

private:
	double itsSalary;
};

#endif // !__ADDSALARIEDEMPLOYEE_H__
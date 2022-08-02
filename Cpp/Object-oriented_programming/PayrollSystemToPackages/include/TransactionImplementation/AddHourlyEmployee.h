#ifndef __ADDHOURLYEMPLOYEE_H__
#define __ADDHOURLYEMPLOYEE_H__

#include "AbstractTransaction/AddEmployeeTransaction.h"

class AddHourlyEmployee : public AddEmployeeTransaction
{
public:
	virtual ~AddHourlyEmployee();
	AddHourlyEmployee(int empId, std::string name,
		std::string address, double hourlyRate);
	virtual PaymentClassification* GetClassification() const override;
	virtual PaymentSchedule* GetSchedule() const override;
	virtual PaymentMethod* GetMethod() const override;

private:
	double itsHourlyRate;
};


#endif // !__ADDHOURLYEMPLOYEE_H__
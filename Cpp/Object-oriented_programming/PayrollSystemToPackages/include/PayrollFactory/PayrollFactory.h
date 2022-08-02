#ifndef __PAYROLLFACTORY_H__
#define __PAYROLLFACTORY_H__

#include <string>
#include "Date/Date.h"

class Affiliation;
class Employee;
class Paycheck;
class PaymentClassification;
class PaymentMethod;
class PaymentSchedule;

class PayrollFactory
{
public:
	PayrollFactory() {}
	virtual ~PayrollFactory() {}

	virtual Affiliation* makeNoAffiliation() = 0;
	virtual Affiliation* makeAffiliation(int memberId, double dues) = 0;
	virtual Employee* makeEmployee(int empId, std::string name, std::string address) = 0;
	virtual Paycheck* makePaycheck(const Date& payPeriodStartDate, const Date& payPeriodEndDate) = 0;

	virtual PaymentClassification* makeSalariedClassification(double salary) = 0;
	virtual PaymentClassification* makeHourlyClassification(double hourlyRate) = 0;
	virtual PaymentClassification* makeCommissionedClassification(double salary, double commissionRate) = 0;
	
	virtual PaymentMethod* makeHoldMethod() = 0;
	virtual PaymentMethod* makeDirectMethod(std::string bank, std::string account) = 0;
	virtual PaymentMethod* makeMailMethod(std::string address) = 0;

	virtual PaymentSchedule* makeWeeklySchedule() = 0;
	virtual PaymentSchedule* makeBiweeklySchedule() = 0;
	virtual PaymentSchedule* makeMonthlySchedule() = 0;

	static PayrollFactory* CurrentPayrollFactory;
};

#endif // !__PAYROLLFACTORY_H__
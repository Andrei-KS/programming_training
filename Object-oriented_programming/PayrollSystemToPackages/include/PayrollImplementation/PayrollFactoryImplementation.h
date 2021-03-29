#ifndef __PAYROLLFACTORYIMPLEMENTATION_H__
#define __PAYROLLFACTORYIMPLEMENTATION_H__

#include "PayrollFactory/PayrollFactory.h"

class PayrollFactoryImplementation : public PayrollFactory
{
public:
	PayrollFactoryImplementation();
	virtual ~PayrollFactoryImplementation();

	virtual Affiliation* makeNoAffiliation() override;
	virtual Affiliation* makeAffiliation(int memberId, double dues) override;
	virtual Employee* makeEmployee(int empId, std::string name, std::string address) override;
	virtual Paycheck* makePaycheck(const Date& payPeriodStartDate, const Date& payPeriodEndDate) override;

	virtual PaymentClassification* makeSalariedClassification(double salary) override;
	virtual PaymentClassification* makeHourlyClassification(double hourlyRate) override;
	virtual PaymentClassification* makeCommissionedClassification(double salary, double commissionRate) override;

	virtual PaymentMethod* makeHoldMethod() override;
	virtual PaymentMethod* makeDirectMethod(std::string bank, std::string account) override;
	virtual PaymentMethod* makeMailMethod(std::string address) override;

	virtual PaymentSchedule* makeWeeklySchedule() override;
	virtual PaymentSchedule* makeBiweeklySchedule() override;
	virtual PaymentSchedule* makeMonthlySchedule() override;
};

#endif // !__PAYROLLFACTORYIMPLEMENTATION_H__
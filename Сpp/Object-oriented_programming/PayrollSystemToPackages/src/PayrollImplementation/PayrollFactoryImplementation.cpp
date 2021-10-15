

#include "PayrollFactoryImplementation.h"
#include "PayrollDomain/NoAffiliation.h"
#include "UnionAffiliation.h"
#include "PayrollDomain/Employee.h"
#include "PayrollDomain/Paycheck.h"

#include "SalariedClassification.h"
#include "HourlyClassification.h"
#include "CommissionedClassification.h"

#include "HoldMethod.h"
#include "DirectMethod.h"
#include "MailMethod.h"

#include "WeeklySchedule.h"
#include "BiweeklySchedule.h"
#include "MonthlySchedule.h"

PayrollFactory* PayrollFactory::CurrentPayrollFactory = new PayrollFactoryImplementation();

PayrollFactoryImplementation::PayrollFactoryImplementation()
{
}

PayrollFactoryImplementation::~PayrollFactoryImplementation()
{
}

Affiliation* PayrollFactoryImplementation::makeNoAffiliation()
{
	return new NoAffiliation();
}

Affiliation* PayrollFactoryImplementation::makeAffiliation(int memberId, double dues)
{
	return new UnionAffiliation(memberId, dues);
}

Employee* PayrollFactoryImplementation::makeEmployee(int empId, std::string name, std::string address)
{
	return new Employee(empId, name, address);
}

Paycheck* PayrollFactoryImplementation::makePaycheck(const Date& payPeriodStartDate, const Date& payPeriodEndDate)
{
	return new Paycheck(payPeriodStartDate, payPeriodEndDate);
}

PaymentClassification* PayrollFactoryImplementation::makeSalariedClassification(double salary)
{
	return new SalariedClassification(salary);
}

PaymentClassification* PayrollFactoryImplementation::makeHourlyClassification(double hourlyRate)
{
	return new HourlyClassification(hourlyRate);
}

PaymentClassification* PayrollFactoryImplementation::makeCommissionedClassification(double salary, double commissionRate)
{
	return new CommissionedClassification(salary, commissionRate);
}

PaymentMethod* PayrollFactoryImplementation::makeHoldMethod()
{
	return new HoldMethod();
}

PaymentMethod* PayrollFactoryImplementation::makeDirectMethod(std::string bank, std::string account)
{
	return new DirectMethod(bank, account);
}

PaymentMethod* PayrollFactoryImplementation::makeMailMethod(std::string address)
{
	return new MailMethod(address);
}

PaymentSchedule* PayrollFactoryImplementation::makeWeeklySchedule()
{
	return new WeeklySchedule();
}

PaymentSchedule* PayrollFactoryImplementation::makeBiweeklySchedule()
{
	return new BiweeklySchedule();
}

PaymentSchedule* PayrollFactoryImplementation::makeMonthlySchedule()
{
	return new MonthlySchedule();
}
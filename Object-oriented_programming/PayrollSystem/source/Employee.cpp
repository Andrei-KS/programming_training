

#include "../header/Employee.h" 
#include "../header/Affiliation/NoAffiliation.h"
#include "../header/PaymentClassification/PaymentClassification.h"
#include "../header/PaymentSchedule/PaymentSchedule.h"
#include "../header/PaymentMethod/PaymentMethod.h"
#include "../header/Paycheck.h"

Employee::~Employee()
{
	delete itsClassification;
	delete itsSchedule;
	delete itsPaymentMethod;
	delete itsAffiliation;
}

Employee::Employee(int empId, std::string name, std::string address)
	: itsEmpId(empId)
	, itsName(name)
	, itsAddress(address)
	, itsAffiliation(new NoAffiliation())
	, itsClassification(nullptr)
	, itsSchedule(nullptr)
	, itsPaymentMethod(nullptr)
{
}

void Employee::SetName(std::string name)
{
	itsName = name;
}

void Employee::SetAddress(std::string address)
{
	itsAddress = address;
}

void Employee::SetClassification(PaymentClassification* pc)
{
	delete itsClassification;
	itsClassification = pc;
}

void Employee::SetMethod(PaymentMethod* pm)
{
	delete itsPaymentMethod;
	itsPaymentMethod = pm;
}

void Employee::SetSchedule(PaymentSchedule* ps)
{
	delete itsSchedule;
	itsSchedule = ps;
}

void Employee::SetAffiliation(Affiliation* af)
{
	delete itsAffiliation;
	itsAffiliation = af;
}

void Employee::Payday(Paycheck& pc) const
{
	double grossPay = itsClassification->CalculatePay(pc);
	double deductions = itsAffiliation->CalculateDeductions(pc);
	double netPay = grossPay - deductions;
	pc.SetGrossPay(grossPay);
	pc.SetDeductions(deductions);
	pc.SetNetPay(netPay);
	itsPaymentMethod->Pay(pc);
}

bool Employee::IsPayDay(const Date& payDate) const
{
	return itsSchedule->IsPayday(payDate);
}

Date Employee::GetPayPeriodStartDate(const Date& payPeriodEndDate) const
{
	return itsSchedule->GetPayPeriodStartDate(payPeriodEndDate);
}

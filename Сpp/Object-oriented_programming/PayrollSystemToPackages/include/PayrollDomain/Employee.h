#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

class PaymentSchedule;
class PaymentClassification;
class PaymentMethod;
class Affiliation;
class Paycheck;
class Date;

class Employee
{
public:
	virtual ~Employee();
	Employee(int empId, std::string name, std::string address);
	void SetName(std::string name);
	void SetAddress(std::string address);
	void SetClassification(PaymentClassification* pc);
	void SetMethod(PaymentMethod* pm);
	void SetSchedule(PaymentSchedule* ps);
	void SetAffiliation(Affiliation* af);
	int GetEmpId() const { return itsEmpId; }
	std::string GetName() const { return itsName; }
	std::string GetAddress() const { return itsAddress; }
	PaymentClassification* GetClassification() const { return itsClassification; }
	PaymentSchedule* GetSchedule() { return itsSchedule; }
	PaymentMethod* GetMethod() { return itsPaymentMethod; }
	Affiliation* GetAffiliation() { return itsAffiliation; }

	void Payday(Paycheck& pc) const;
	bool IsPayDay(const Date& payDate) const;
	Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const;

private:
	int itsEmpId;
	std::string itsName;
	std::string itsAddress;
	PaymentClassification* itsClassification;
	PaymentSchedule* itsSchedule;
	PaymentMethod* itsPaymentMethod;
	Affiliation* itsAffiliation;

};

#endif // !__EMPLOYEE_H__
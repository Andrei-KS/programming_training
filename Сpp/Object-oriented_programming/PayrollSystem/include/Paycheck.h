#ifndef __PAYCHECK_H__
#define __PAYCHECK_H__

#include "Date.h"
#include <unordered_map>
#include <string>

class Paycheck
{
public:
	virtual ~Paycheck();
	Paycheck(const Date& payPeriodStartDate, const Date& payPeriodEndDate);
	void SetGrossPay(double grossPay);
	void SetDeductions(double deductions);
	void SetNetPay(double netPay);
	void AddField(const std::string& nameFiled,const std::string& value);

	Date GetPayPeriodStartDate() const { return itsPayPeriodStartDate; }
	Date GetPayPeriodEndDate() const { return itsPayPeriodEndDate; }
	double GetGrossPay() const { return itsGrossPay; }
	double GetDeductions() const { return itsDeductions; }
	double GetNetPay() const { return itsNetPay; }
	std::string GetField(const std::string& nameField) const;

private:
	Date itsPayPeriodStartDate;
	Date itsPayPeriodEndDate;
	double itsGrossPay;
	double itsDeductions;
	double itsNetPay;
	std::unordered_map<std::string, std::string> itsFields;
};

#endif // !__PAYCHECK_H__
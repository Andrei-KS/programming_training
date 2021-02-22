#ifndef __PAYCHECK_H__
#define __PAYCHECK_H__

#include "Date.h"
#include <unordered_map>
#include <string>

class Paycheck
{
public:
	virtual ~Paycheck();
	Paycheck(const Date& date);
	void SetGrossPay(double grossPay);
	void SetDeductions(double deductions);
	void SetNetPay(double netPay);
	void AddField(const std::string& nameFiled,const std::string& value);

	Date GetPayDate() const { return itsPayDate; }
	double GetGrossPay() const { return itsGrossPay; }
	double GetDeductions() const { return itsDeductions; }
	double GetNetPay() const { return itsNetPay; }
	std::string GetField(const std::string& nameField) const;

private:
	Date itsPayDate;
	double itsGrossPay;
	double itsDeductions;
	double itsNetPay;
	std::unordered_map<std::string, std::string> itsFields;
};

#endif // !__PAYCHECK_H__
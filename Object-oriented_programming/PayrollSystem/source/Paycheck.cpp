

#include "../header/Paycheck.h"

Paycheck::~Paycheck()
{
}

Paycheck::Paycheck(const Date& date)
	: itsPayDate(date)
	, itsGrossPay(0)
	, itsDeductions(0)
	, itsNetPay(0)
	, itsFields(std::unordered_map<std::string, std::string>())
{
}

void Paycheck::SetGrossPay(double grossPay)
{
	itsGrossPay = grossPay;
}

void Paycheck::SetDeductions(double deductions)
{
	itsDeductions = deductions;
}

void Paycheck::SetNetPay(double netPay)
{
	itsNetPay = netPay;
}

void Paycheck::AddField(const std::string& nameFiled, const std::string& value)
{
	itsFields[nameFiled] = value;
}

std::string Paycheck::GetField(const std::string& nameField) const
{
	std::unordered_map<std::string, std::string>::const_iterator it = itsFields.find(nameField);
	if (it != itsFields.end())
	{
		return it->second;
	}
	return std::string();
}

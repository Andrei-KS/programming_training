

#include "CommissionedClassification.h"
#include "SalesReceipt.h"
#include "Date/Date.h"
#include "PayrollDomain/Paycheck.h"

CommissionedClassification::~CommissionedClassification()
{
	std::map<Date, SalesReceipt*>::iterator it = itsSalesReceipts.begin();
	while (it != itsSalesReceipts.end())
	{
		delete it->second;
		it++;
	}
	itsSalesReceipts.clear();
}

CommissionedClassification::CommissionedClassification(double salary, double commissionRate)
	: itsSalary(salary)
	, itsCommissionRate(commissionRate)
	, itsSalesReceipts(std::map<Date, SalesReceipt*>())
{
}

void CommissionedClassification::AddSalesReceipt(const Date& date, double amount)
{
	std::map<Date, SalesReceipt*>::const_iterator it = itsSalesReceipts.find(date);
	if (it != itsSalesReceipts.end())
	{
		delete it->second;
		itsSalesReceipts.erase(it);
	}
	itsSalesReceipts[date] = new SalesReceipt(date,amount);
}

SalesReceipt* CommissionedClassification::GetSalesReceipt(const Date& date) const
{
	std::map<Date, SalesReceipt*>::const_iterator it = itsSalesReceipts.find(date);
	if (it != itsSalesReceipts.end())
	{
		return it->second;
	}
	return nullptr;
}

double CommissionedClassification::CalculatePay(const Paycheck& pc) const
{
	double totalPay = GetSalary();
	Date payPeriodStartDate = pc.GetPayPeriodStartDate();
	Date payPeriodEndDate = pc.GetPayPeriodEndDate();

	std::map<Date, SalesReceipt*>::const_iterator it = itsSalesReceipts.begin();
	for (; it != itsSalesReceipts.end(); it++)
	{
		SalesReceipt* sr = (*it).second;
		if(Date::IsBetween(sr->GetDate(),payPeriodStartDate,payPeriodEndDate))
		{
			totalPay += CalculatePayForSalesReceipt(sr);
		}
	}
	return totalPay;
}

double CommissionedClassification::CalculatePayForSalesReceipt(SalesReceipt* sr) const
{
	return sr->GetAmount()*GetCommissionRate();
}

void CommissionedClassification::AddItem(Date& date, double value, PaymentClassification* thisObject)
{
	if (CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(thisObject))
	{
		cc->AddSalesReceipt(date, value);
	}
	else
	{
		throw("Tried to add salesreceipt to non-commissioned employee");
	}
}
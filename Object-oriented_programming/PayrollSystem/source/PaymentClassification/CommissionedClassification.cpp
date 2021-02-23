

#include "../../header/PaymentClassification/CommissionedClassification.h"
#include "../../header/PaymentClassification/SalesReceipt.h"
#include "../../header/Date.h"
#include "../../header/Paycheck.h"

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

void CommissionedClassification::AddSalesReceipt(SalesReceipt*sr)
{
	std::map<Date, SalesReceipt*>::const_iterator it = itsSalesReceipts.find(sr->GetDate());
	if (it != itsSalesReceipts.end())
	{
		delete it->second;
		itsSalesReceipts.erase(it);
	}
	itsSalesReceipts[sr->GetDate()] = sr;
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
	Date payPeriod = pc.GetPayDate();
	std::map<Date, SalesReceipt*>::const_iterator it = itsSalesReceipts.begin();
	for (; it != itsSalesReceipts.end(); it++)
	{
		SalesReceipt* sr = (*it).second;
		if (IsInPayPeriod(sr, payPeriod))
		{
			totalPay += CalculatePayForSalesReceipt(sr);
		}
	}
	return totalPay;
}

bool CommissionedClassification::IsInPayPeriod(SalesReceipt* sr, const Date& payPeriod) const
{
	Date payPeriodEndDate = payPeriod;
	Date payPeriodStartDate = payPeriod - 12;
	Date SalesReceiptDate = sr->GetDate();
	return (SalesReceiptDate >= payPeriodStartDate)
		&& (SalesReceiptDate <= payPeriodEndDate);
}

double CommissionedClassification::CalculatePayForSalesReceipt(SalesReceipt* sr) const
{
	return sr->GetAmount()*GetCommissionRate();
}

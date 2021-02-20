

#include "../../header/PaymentClassification/CommissionedClassification.h"
#include "../../header/PaymentClassification/SalesReceipt.h"

CommissionedClassification::~CommissionedClassification()
{
	std::map<long, SalesReceipt*>::iterator it = itsSalesReceipts.begin();
	while (it != itsSalesReceipts.end())
	{
		delete it->second;
		itsSalesReceipts.erase(it);
		it = itsSalesReceipts.begin();
	}
}

CommissionedClassification::CommissionedClassification(double salary, double commissionRate)
	: itsSalary(salary)
	, itsCommissionRate(commissionRate)
	, itsSalesReceipts(std::map<long, SalesReceipt*>())
{
}

void CommissionedClassification::AddSalesReceipt(SalesReceipt*sr)
{
	std::map<long, SalesReceipt*>::const_iterator it = itsSalesReceipts.find(sr->GetDate());
	if (it != itsSalesReceipts.end())
	{
		delete it->second;
		itsSalesReceipts.erase(it);
	}
	itsSalesReceipts[sr->GetDate()] = sr;
}

SalesReceipt* CommissionedClassification::GetSalesReceipt(long date) const
{
	std::map<long, SalesReceipt*>::const_iterator it = itsSalesReceipts.find(date);
	if (it != itsSalesReceipts.end())
	{
		return it->second;
	}
	return nullptr;
}

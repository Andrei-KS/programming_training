#ifndef __COMMISSIONEDCLASSIFICATION_H__
#define __COMMISSIONEDCLASSIFICATION_H__

#include "PaymentClassification.h"
#include <map>

class SalesReceipt;

class CommissionedClassification : public PaymentClassification
{
public:
	virtual ~CommissionedClassification();
	CommissionedClassification(double salary, double commissionRate);
	void AddSalesReceipt(SalesReceipt*sr);
	double GetGetSalary() const { return itsSalary; }
	double GetCommissionRate() const { return itsCommissionRate; }
	SalesReceipt* GetSalesReceipt(long date) const;

private:
	double itsSalary;
	double itsCommissionRate;
	std::map<long, SalesReceipt*> itsSalesReceipts;
};

#endif // !__COMMISSIONEDCLASSIFICATION_H__
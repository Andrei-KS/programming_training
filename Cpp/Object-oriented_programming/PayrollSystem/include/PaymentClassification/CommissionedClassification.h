#ifndef __COMMISSIONEDCLASSIFICATION_H__
#define __COMMISSIONEDCLASSIFICATION_H__

#include "PaymentClassification.h"
#include <map>

class Date;

class SalesReceipt;

class CommissionedClassification : public PaymentClassification
{
public:
	virtual ~CommissionedClassification();
	CommissionedClassification(double salary, double commissionRate);
	void AddSalesReceipt(const Date& date, double amount);
	double GetSalary() const { return itsSalary; }
	double GetCommissionRate() const { return itsCommissionRate; }
	SalesReceipt* GetSalesReceipt(const Date& date) const;
	virtual double CalculatePay(const Paycheck& pc) const override;
	double CalculatePayForSalesReceipt(SalesReceipt* sr) const;

private:
	double itsSalary;
	double itsCommissionRate;
	std::map<Date, SalesReceipt*> itsSalesReceipts;
};

#endif // !__COMMISSIONEDCLASSIFICATION_H__
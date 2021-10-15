#ifndef __HOURLYCLASSIFICATION_H__
#define __HOURLYCLASSIFICATION_H__

#include "PayrollDomain/PaymentClassification.h"
#include <map>

class TimeCard;
class Date;

class HourlyClassification : public PaymentClassification
{
public:
	virtual ~HourlyClassification();
	HourlyClassification(double hourlyRate);
	virtual void AddTimeCard(const Date& date, double hours);
	TimeCard* GetTimeCard(const Date& date) const;
	double GetHourlyRate() const { return itsHourlyRate; }
	virtual double CalculatePay(const Paycheck& pc) const override;
	double CalculatePayForTimeCard(TimeCard* tc) const;
	virtual void AddItem(Date& date, double value, PaymentClassification* thisObject) override;

private:
	double itsHourlyRate;
	std::map<Date,TimeCard*> itsTimeCards;
};

#endif // !__HOURLYCLASSIFICATION_H__
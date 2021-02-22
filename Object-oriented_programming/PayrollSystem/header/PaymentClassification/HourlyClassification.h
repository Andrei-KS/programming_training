#ifndef __HOURLYCLASSIFICATION_H__
#define __HOURLYCLASSIFICATION_H__

#include "PaymentClassification.h"
#include <map>

class TimeCard;
class Date;

class HourlyClassification : public PaymentClassification
{
public:
	virtual ~HourlyClassification();
	HourlyClassification(double hourlyRate);
	virtual void AddTimeCard(TimeCard* tc);
	TimeCard* GetTimeCard(const Date& date) const;
	double GetHourlyRate() const { return itsHourlyRate; }
	virtual double CalculatePay(const Paycheck& pc) const override;
	bool IsInPayPeriod(TimeCard* tc, const Date& payPeriod) const;
	double CalculatePayForTimeCard(TimeCard* tc) const;

private:
	double itsHourlyRate;
	std::map<Date,TimeCard*> itsTimeCards;
};

#endif // !__HOURLYCLASSIFICATION_H__
#ifndef __HOURLYCLASSIFICATION_H__
#define __HOURLYCLASSIFICATION_H__

#include "PaymentClassification.h"
#include <map>

class TimeCard;

class HourlyClassification : public PaymentClassification
{
public:
	virtual ~HourlyClassification();
	HourlyClassification(double hourlyRate);
	virtual void AddTimeCard(TimeCard* tc);
	TimeCard* GetTimeCard(long date) const;
	double GetHourlyRate() const { return itsHourlyRate; }
	

private:
	double itsHourlyRate;
	std::map<long,TimeCard*> itsTimeCards;
};

#endif // !__HOURLYCLASSIFICATION_H__
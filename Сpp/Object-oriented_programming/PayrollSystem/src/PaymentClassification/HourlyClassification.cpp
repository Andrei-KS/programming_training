

#include "PaymentClassification/HourlyClassification.h"
#include "PaymentClassification/TimeCard.h"
#include "Date.h"
#include "Paycheck.h"

#include <map>
#include <algorithm>

HourlyClassification::~HourlyClassification()
{
	std::map<Date, TimeCard*>::iterator it = itsTimeCards.begin();
	while (it != itsTimeCards.end())
	{
		delete it->second;
		it++;
	}
	itsTimeCards.clear();
}

HourlyClassification::HourlyClassification(double hourlyRate)
	: itsHourlyRate(hourlyRate)
	, itsTimeCards(std::map<Date,TimeCard*>())
{
}

TimeCard* HourlyClassification::GetTimeCard(const Date& date) const
{
	std::map<Date, TimeCard*>::const_iterator it = itsTimeCards.find(date);
	if (it != itsTimeCards.end())
	{
		return it->second;
	}
	return nullptr;
}

void HourlyClassification::AddTimeCard(const Date& date, double hours)
{
	std::map<Date, TimeCard*>::const_iterator it = itsTimeCards.find(date);
	if (it != itsTimeCards.end())
	{
		delete it->second;
		itsTimeCards.erase(it);
	}
	itsTimeCards[date] = new TimeCard(date,hours);
}

double HourlyClassification::CalculatePay(const Paycheck& pc) const
{
	double totalPay = 0;
	Date payPeriodStartDate = pc.GetPayPeriodStartDate();
	Date payPeriodEndDate = pc.GetPayPeriodEndDate();

	std::map<Date, TimeCard*>::const_iterator cit = itsTimeCards.begin();
	for (; cit != itsTimeCards.end(); cit++)
	{
		TimeCard* tc = (*cit).second;
		if (Date::IsBetween(tc->GetDate(), payPeriodStartDate, payPeriodEndDate))
		{
			totalPay += CalculatePayForTimeCard(tc);
		}
	}
	return totalPay;
}

double HourlyClassification::CalculatePayForTimeCard(TimeCard* tc) const
{
	double hours = tc->GetHours();
	double overtime = std::max(0.0, hours - 8.0);
	double startingTime = hours - overtime;
	const double multiplierOvertime = 1.5;
	return startingTime * itsHourlyRate + overtime * multiplierOvertime * itsHourlyRate;
}

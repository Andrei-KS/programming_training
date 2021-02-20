

#include "../../header/PaymentClassification/HourlyClassification.h"
#include "../../header/PaymentClassification/TimeCard.h"

HourlyClassification::~HourlyClassification()
{
	std::map<long, TimeCard*>::iterator it = itsTimeCards.begin();
	while (it != itsTimeCards.end())
	{
		delete it->second;
		itsTimeCards.erase(it);
		it = itsTimeCards.begin();
	}
}

HourlyClassification::HourlyClassification(double hourlyRate)
	: itsHourlyRate(hourlyRate)
	, itsTimeCards(std::map<long,TimeCard*>())
{
}

TimeCard* HourlyClassification::GetTimeCard(long date) const
{
	std::map<long, TimeCard*>::const_iterator it = itsTimeCards.find(date);
	if (it != itsTimeCards.end())
	{
		return it->second;
	}
	return nullptr;
}

void HourlyClassification::AddTimeCard(TimeCard* tc)
{
	std::map<long, TimeCard*>::const_iterator it = itsTimeCards.find(tc->GetDate());
	if (it != itsTimeCards.end())
	{
		delete it->second;
		itsTimeCards.erase(it);
	}
	itsTimeCards[tc->GetDate()] = tc;
}

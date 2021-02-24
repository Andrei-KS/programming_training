

#include "../../header/Affiliation/UnionAffiliation.h"
#include "../../header/Affiliation/ServiceCharge.h"
#include "../../header/Date.h"
#include "../../header/Paycheck.h"

UnionAffiliation::~UnionAffiliation()
{
	std::map<Date, ServiceCharge*>::iterator it = itsServiceCharges.begin();
	while (it != itsServiceCharges.end())
	{
		delete it->second;
		it++;
	}
	itsServiceCharges.clear();
}

UnionAffiliation::UnionAffiliation(int memberId, double dues)
	: itsMemberId(memberId)
	, itsDues(dues)
	, itsServiceCharges(std::map<Date, ServiceCharge*>())
{
}

void UnionAffiliation::SetDues(double dues)
{
	itsDues = dues;
}

void UnionAffiliation::AddServiceCharge(ServiceCharge* sc)
{
	std::map<Date, ServiceCharge*>::const_iterator it = itsServiceCharges.find(sc->GetDate());
	if (it != itsServiceCharges.end())
	{
		delete it->second;
		itsServiceCharges.erase(it);
	}
	itsServiceCharges[sc->GetDate()]=sc;
}

ServiceCharge* UnionAffiliation::GetServiceCharge(const Date& date) const
{
	std::map<Date, ServiceCharge*>::const_iterator it = itsServiceCharges.find(date);
	if (it != itsServiceCharges.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}

namespace
{
	int NumberOfFridaysInPayPeriod(const Date& payPeriodStart, const Date& payPeriodEnd)
	{
		int fridays = 0;
		for (Date day = payPeriodStart; day <= payPeriodEnd; ++day)
		{
			if (day.GetDayOfWeek() == Date::Friday)
			{
				fridays++;
			}
		}
		return fridays;
	}
}

double UnionAffiliation::CalculateDeductions(const Paycheck& pc) const
{
	double totalDues = 0;
	Date payPeriodStartDate = pc.GetPayPeriodStartDate();
	Date payPeriodEndDate = pc.GetPayPeriodEndDate();
	
	std::map<Date, ServiceCharge*>::const_iterator cit = itsServiceCharges.begin();
	for (; cit != itsServiceCharges.end(); cit++)
	{
		ServiceCharge* sc = (*cit).second;
		if (Date::IsBetween(sc->GetDate(), payPeriodStartDate, payPeriodEndDate))
		{
			totalDues += CalculatePayForServiceCharges(sc);
		}
	}
	int fridays = NumberOfFridaysInPayPeriod(payPeriodStartDate, payPeriodEndDate);
	totalDues += itsDues * fridays;
	return totalDues;
}

double UnionAffiliation::CalculatePayForServiceCharges(ServiceCharge* sc) const
{
	return sc->GetAmount();
}

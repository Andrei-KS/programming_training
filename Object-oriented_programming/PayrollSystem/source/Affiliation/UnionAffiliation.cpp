

#include "../../header/Affiliation/UnionAffiliation.h"
#include "../../header/Affiliation/ServiceCharge.h"
#include "../../header/Date.h"

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

double UnionAffiliation::CalculateDeductions(const Paycheck& pc) const
{
	return 0.0;
}



#include "../../header/Affiliation/UnionAffiliation.h"
#include "../../header/Affiliation/ServiceCharge.h"

UnionAffiliation::~UnionAffiliation()
{
	std::map<long, ServiceCharge*>::iterator it = itsServiceCharges.begin();
	while (it != itsServiceCharges.end())
	{
		delete it->second;
		itsServiceCharges.erase(it);
		it = itsServiceCharges.begin();
	}
}

UnionAffiliation::UnionAffiliation(int memberId, double dues)
	: itsMemberId(memberId)
	, itsDues(dues)
	, itsServiceCharges(std::map<long, ServiceCharge*>())
{
}

void UnionAffiliation::SetDues(double dues)
{
	itsDues = dues;
}

void UnionAffiliation::AddServiceCharge(ServiceCharge* sc)
{
	std::map<long, ServiceCharge*>::const_iterator it = itsServiceCharges.find(sc->GetDate());
	if (it != itsServiceCharges.end())
	{
		delete it->second;
		itsServiceCharges.erase(it);
	}
	itsServiceCharges[sc->GetDate()]=sc;
}

ServiceCharge* UnionAffiliation::GetServiceCharge(long date) const
{
	std::map<long, ServiceCharge*>::const_iterator it = itsServiceCharges.find(date);
	if (it != itsServiceCharges.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}

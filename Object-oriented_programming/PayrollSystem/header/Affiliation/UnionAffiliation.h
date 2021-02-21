#ifndef __UNIONAFFILIATION_H__
#define __UNIONAFFILIATION_H__

#include "Affiliation.h"
#include <map>

class ServiceCharge;
class Date;

class UnionAffiliation : public Affiliation
{
public:
	virtual ~UnionAffiliation();
	UnionAffiliation(int memberId, double dues);
	void SetDues(double dues);
	void AddServiceCharge(ServiceCharge* sc);
	ServiceCharge* GetServiceCharge(const Date& date) const;
	int GetMemberId() const { return itsMemberId; }
	double GetDues() const { return itsDues; }

private:
	int itsMemberId;
	double itsDues;
	std::map<Date,ServiceCharge*> itsServiceCharges;
};

#endif // !__UNIONAFFILIATION_H__
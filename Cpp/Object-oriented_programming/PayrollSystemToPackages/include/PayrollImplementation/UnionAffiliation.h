#ifndef __UNIONAFFILIATION_H__
#define __UNIONAFFILIATION_H__

#include "PayrollDomain/Affiliation.h"
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
	int GetMemberId() const override { return itsMemberId; }
	double GetDues() const { return itsDues; }
	virtual double CalculateDeductions(const Paycheck& pc) const override;
	double CalculatePayForServiceCharges(ServiceCharge* sc) const;
	virtual void AddItem(Date& date, double value, Affiliation* thisObject) override;

private:
	int itsMemberId;
	double itsDues;
	std::map<Date,ServiceCharge*> itsServiceCharges;
};

#endif // !__UNIONAFFILIATION_H__
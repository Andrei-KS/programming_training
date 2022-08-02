#ifndef __NOAFFILIATION_H__
#define __NOAFFILIATION_H__

#include "Affiliation.h"

class NoAffiliation : public Affiliation
{
public:
	virtual ~NoAffiliation();
	NoAffiliation();
	virtual double CalculateDeductions(const Paycheck& pc) const override { return 0.0; }
	virtual void AddItem(Date& date, double value, Affiliation* thisObject) override { throw("Tried to add servicecharge to non-unionaffiliation employee"); }
	virtual int GetMemberId() const { return -1; };
};

#endif // !__NOAFFILIATION_H__
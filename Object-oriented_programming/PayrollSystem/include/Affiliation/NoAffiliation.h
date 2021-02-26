#ifndef __NOAFFILIATION_H__
#define __NOAFFILIATION_H__

#include "Affiliation.h"

class NoAffiliation : public Affiliation
{
public:
	virtual ~NoAffiliation();
	NoAffiliation();
	virtual double CalculateDeductions(const Paycheck& pc) const override { return 0.0; }
};

#endif // !__NOAFFILIATION_H__
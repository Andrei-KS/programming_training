#ifndef __AFFILIATION_H_
#define __AFFILIATION_H_

class Paycheck;

class Affiliation
{
public:
	virtual ~Affiliation();
	Affiliation();
	virtual double CalculateDeductions(const Paycheck& pc) const = 0;
};

#endif // !__AFFILIATION_H_
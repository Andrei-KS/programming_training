#ifndef __AFFILIATION_H_
#define __AFFILIATION_H_

class Paycheck;
class Date;

class Affiliation
{
public:
	virtual ~Affiliation();
	Affiliation();
	virtual int GetMemberId() const = 0;
	virtual double CalculateDeductions(const Paycheck& pc) const = 0;
	virtual void AddItem(Date& date, double value, Affiliation* thisObject) = 0;
};

#endif // !__AFFILIATION_H_
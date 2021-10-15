#ifndef __MIALMETHOD_H__
#define __MIALMETHOD_H__

#include "PayrollDOmain/PaymentMethod.h"
#include <string>

class MailMethod : public PaymentMethod
{
public:
	virtual ~MailMethod();
	MailMethod(std::string address);
	void SetAddress(std::string address);
	std::string GetAddress() const { return itsAddress; }
	virtual void Pay(Paycheck& pc) const override;

private:
	std::string itsAddress;
};

#endif // !__MIALMETHOD_H__


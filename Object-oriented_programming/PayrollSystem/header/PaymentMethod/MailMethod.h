#ifndef __MIALMETHOD_H__
#define __MIALMETHOD_H__

#include "PaymentMethod.h"
#include <string>

class MailMethod : public PaymentMethod
{
public:
	virtual ~MailMethod();
	MailMethod(std::string address);
	void SetAddress(std::string address);
	std::string GetAddress() const { return itsAddress; }

private:
	std::string itsAddress;
};

#endif // !__MIALMETHOD_H__


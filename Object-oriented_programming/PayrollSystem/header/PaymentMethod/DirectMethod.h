#ifndef __DIRERCTMETHOD_H__
#define __DIRERCTMETHOD_H__

#include "PaymentMethod.h"
#include <string>

class DirectMethod : public PaymentMethod
{
public:
	virtual ~DirectMethod();
	DirectMethod(std::string bank, std::string account);
	void SetBank(const std::string& bank);
	void SetAccount(const std::string& account);
	std::string GetBank() const { return itsBank; }
	std::string GetAccount() const { return itsAccount; }

private:
	std::string itsBank;
	std::string itsAccount;
};

#endif // !__DIRERCTMETHOD_H__
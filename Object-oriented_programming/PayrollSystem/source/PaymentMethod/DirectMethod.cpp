#include "..\..\header\PaymentMethod\DirectMethod.h"
#include "..\..\header\PaymentMethod\DirectMethod.h"


#include "../../header/PaymentMethod/DirectMethod.h"

DirectMethod::~DirectMethod()
{
}

DirectMethod::DirectMethod(std::string bank, std::string account)
	: itsBank(bank)
	, itsAccount(account)
{
}

void DirectMethod::SetBank(const std::string& bank)
{
	itsBank = bank;
}

void DirectMethod::SetAccount(const std::string& account)
{
	itsAccount = account;
}

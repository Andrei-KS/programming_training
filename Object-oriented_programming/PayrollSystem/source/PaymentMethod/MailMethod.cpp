

#include "../../header/PaymentMethod/MailMethod.h"

MailMethod::~MailMethod()
{
}

MailMethod::MailMethod(std::string address)
	: itsAddress(address)
{
}

void MailMethod::SetAddress(std::string address)
{
	itsAddress = address;
}



#include "MailMethod.h"
#include "PayrollDomain/Paycheck.h"

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

void MailMethod::Pay(Paycheck& pc) const
{
	pc.AddField("Disposition", "Mail");
}

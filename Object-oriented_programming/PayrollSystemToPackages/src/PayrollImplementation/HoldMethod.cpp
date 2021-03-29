

#include "PayrollDomain/PaymentMethod.h"
#include "HoldMethod.h"
#include "PayrollDOmain/Paycheck.h"

HoldMethod::~HoldMethod()
{
}

HoldMethod::HoldMethod()
{
}

void HoldMethod::Pay(Paycheck& pc) const
{
	pc.AddField("Disposition", "Hold");
}

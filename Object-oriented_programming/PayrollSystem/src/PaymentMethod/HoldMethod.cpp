

#include "PaymentMethod/PaymentMethod.h"
#include "PaymentMethod\HoldMethod.h"
#include "Paycheck.h"

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

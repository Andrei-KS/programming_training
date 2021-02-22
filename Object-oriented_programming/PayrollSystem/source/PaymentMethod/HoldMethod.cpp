

#include "../../header/PaymentMethod/PaymentMethod.h"
#include "../../header/PaymentMethod\HoldMethod.h"
#include "../../header/Paycheck.h"

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

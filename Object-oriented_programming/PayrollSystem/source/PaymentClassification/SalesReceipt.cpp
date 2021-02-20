

#include "../../header/PaymentClassification/SalesReceipt.h"

SalesReceipt::~SalesReceipt()
{
}

SalesReceipt::SalesReceipt(long date, double amount)
	: itsDate(date)
	, itsAmount(amount)
{
}

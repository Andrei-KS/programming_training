

#include "SalesReceipt.h"

SalesReceipt::~SalesReceipt()
{
}

SalesReceipt::SalesReceipt(const Date& date, double amount)
	: itsDate(date)
	, itsAmount(amount)
{
}

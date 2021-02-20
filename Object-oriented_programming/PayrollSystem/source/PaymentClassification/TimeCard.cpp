

#include "../../header/PaymentClassification/TimeCard.h"

TimeCard::~TimeCard()
{
}

TimeCard::TimeCard(long date, double hours)
	: itsDate(date)
	, itsHours(hours)
{
}

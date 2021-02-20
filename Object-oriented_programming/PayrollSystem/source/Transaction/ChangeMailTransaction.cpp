

#include "../../header/Transaction/ChangeMailTransaction.h"
#include "../../header/PaymentMethod/MailMethod.h"

ChangeMailTransaction::~ChangeMailTransaction()
{
}

ChangeMailTransaction::ChangeMailTransaction(int empId, std::string address)
	: ChangeMethodTransaction(empId)
	, itsAddress(address)
{
}

PaymentMethod* ChangeMailTransaction::GetMethod() const
{
	return new MailMethod(itsAddress);
}

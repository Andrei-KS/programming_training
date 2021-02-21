#include "Test/PayrollTest.h"
#include "Test/DateTest.h"

int main()
{
	PayrollTest::TestAddSalariedEmployee();
	PayrollTest::TestAddHourlyEmployee();
	PayrollTest::TestAddCommissionedEmployee();
	PayrollTest::TestDeleteEmployee();

	PayrollTest::TestTimeCardTransaction();
	PayrollTest::TestSalesReceiptTransaction();
	PayrollTest::TestAddServiceCharge();

	PayrollTest::TestChangeNameTransaction();
	PayrollTest::TestAddressNameTransaction();
	PayrollTest::TestChangeHourlyTransaction();
	PayrollTest::TestChangeSalariedTransaction();
	PayrollTest::TestChangeCommissionedTransaction();
	PayrollTest::TestChangeMailTransaction();
	PayrollTest::TestChangeDirectTransaction();
	PayrollTest::TestChangeHoldTransaction();
	PayrollTest::TestChangeMemberTransaction();
	PayrollTest::TestChangeUnaffiliatedTransaction();

	DateTest::TestAmountOfDaysMonth();
	DateTest::TestAmountOfDaysYear();
	DateTest::TestOrderOfDate();
	DateTest::TestAddDays();
	DateTest::TestGetDate();

	return 0;
}
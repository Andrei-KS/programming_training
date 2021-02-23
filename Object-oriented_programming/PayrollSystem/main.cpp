#include "Test/PayrollTest.h"
#include "Test/DateTest.h"

int main()
{
	DateTest::TestAmountOfDaysMonth();
	DateTest::TestAmountOfDaysYear();
	DateTest::TestOrderOfDate();
	DateTest::TestAddDays();
	DateTest::TestGetDate();
	DateTest::TestSubtractionDays();

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

	PayrollTest::TestPaySingleSalariedEmployee();
	PayrollTest::TetsPaySingleSalariedEmployeeOnWrongDate();

	PayrollTest::TetsPaySingleHourlyEmployeeNoTimeCards();
	PayrollTest::TestPaySingleHourlyEmployeeOneTimeCard();
	PayrollTest::TestPaySingleHourlyEmployeeOvertimeOneTimeCard();
	PayrollTest::TestPaySingleHourlyEmployeeOnWrongDate();
	PayrollTest::TestPaySingleHourlyEmployeeTwoTimeCard();
	PayrollTest::TestPaySingleHourlyEmployeeWithTimeCardSpanningTwoPayPeriods();

	PayrollTest::TetsPaySingleCommissionedEmployeeNoSalesReceipt();
	PayrollTest::TestPaySingleCommissionedEmployeeOneSalesReceipt();
	PayrollTest::TestPaySingleCommissionedEmployeeOnWrongDate();
	PayrollTest::TestPaySingleCommissionedEmployeeTwoSalesReceipt();
	PayrollTest::TestPaySingleCommissionedEmployeeWithSalesReceiptSpanningTwoPayPeriods();

	return 0;
}
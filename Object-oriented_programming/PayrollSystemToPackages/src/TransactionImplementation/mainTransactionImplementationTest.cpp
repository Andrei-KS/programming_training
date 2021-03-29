#include "TransactionImplementationTest.h"

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

	PayrollTest::TestSalariedUnionMemberDues();
	PayrollTest::TestHourlyUnionMemberServiceCharge();
	PayrollTest::TestServiceChargesSpanningMultiplePayPeriods();
	PayrollTest::TestClearPayrollDatebase();

	return 0;
}
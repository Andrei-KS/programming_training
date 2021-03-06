#ifndef __TRANSACTIONIMPLEMENTATIONTEST_H__
#define __TRANSACTIONIMPLEMENTATIONTEST_H__

class PaydayTransaction;
class Date;

namespace PayrollTest
{
	void TestAddSalariedEmployee();
	void TestAddHourlyEmployee();
	void TestAddCommissionedEmployee();
	void TestDeleteEmployee();

	void TestTimeCardTransaction();
	void TestSalesReceiptTransaction();
	void TestAddServiceCharge();

	void TestChangeNameTransaction();
	void TestAddressNameTransaction();
	void TestChangeHourlyTransaction();
	void TestChangeSalariedTransaction();
	void TestChangeCommissionedTransaction();
	void TestChangeMailTransaction();
	void TestChangeDirectTransaction();
	void TestChangeHoldTransaction();
	void TestChangeMemberTransaction();
	void TestChangeUnaffiliatedTransaction();

	void ValidatePaycheck(PaydayTransaction& pt, int empId, const Date& payDate, double grossPay, double deductions, double netPay);

	void TestPaySingleSalariedEmployee();
	void TetsPaySingleSalariedEmployeeOnWrongDate();
	
	void TetsPaySingleHourlyEmployeeNoTimeCards();
	void TestPaySingleHourlyEmployeeOneTimeCard();
	void TestPaySingleHourlyEmployeeOvertimeOneTimeCard();
	void TestPaySingleHourlyEmployeeOnWrongDate();
	void TestPaySingleHourlyEmployeeTwoTimeCard();
	void TestPaySingleHourlyEmployeeWithTimeCardSpanningTwoPayPeriods();

	void TetsPaySingleCommissionedEmployeeNoSalesReceipt();
	void TestPaySingleCommissionedEmployeeOneSalesReceipt();
	void TestPaySingleCommissionedEmployeeOnWrongDate();
	void TestPaySingleCommissionedEmployeeTwoSalesReceipt();
	void TestPaySingleCommissionedEmployeeWithSalesReceiptSpanningTwoPayPeriods();

	void TestSalariedUnionMemberDues();
	void TestHourlyUnionMemberServiceCharge();
	void TestServiceChargesSpanningMultiplePayPeriods();
	void TestClearPayrollDatebase();
}

#endif // !__TRANSACTIONIMPLEMENTATIONTEST_H__
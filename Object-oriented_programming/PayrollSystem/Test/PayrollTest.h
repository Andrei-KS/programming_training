#ifndef __PAYROLLTEST_H__
#define __PAYROLLTEST_H__

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

	void TestPaySingleSalariedEmployee();
	void TetsPaySingleSalariedEmployeeOnWrongDate();
	
	void TetsPaySingleHourlyEmployeeNoTimeCards();
	void ValidateHourlyPaycheck(PaydayTransaction& pt, int empId, const Date& payDate, double pay);
	void TestPaySingleHourlyEmployeeOneTimeCard();
	void TestPaySingleHourlyEmployeeOvertimeOneTimeCard();
	void TestPaySingleHourlyEmployeeOnWrongDate();
	void TestPaySingleHourlyEmployeeTwoTimeCard();
	void TestPaySingleHourlyEmployeeWithTimeCardSpanningTwoPayPeriods();
}

#endif // !__PAYROLLTEST_H__
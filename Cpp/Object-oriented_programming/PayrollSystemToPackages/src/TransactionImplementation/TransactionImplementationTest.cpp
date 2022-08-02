

#include "TransactionImplementationTest.h"
#include "PayrollDatabase/PayrollDatabase.h"
#include "PayrollDomain/Employee.h"
#include "Date/Date.h"

#include "PayrollFactory/PayrollFactory.h"
#include "AddSalariedEmployee.h"
#include "AddHourlyEmployee.h"
#include "AddCommissionedEmployee.h"
#include "DeleteEmployeeTransaction.h"
#include "TimeCardTransaction.h"
#include "SalesReceiptTransaction.h"
#include "ServiceChargeTransaction.h"
#include "ChangeNameTransaction.h"
#include "ChangeAddressTransaction.h"
#include "ChangeHourlyTransaction.h"
#include "ChangeSalariedTransaction.h"
#include "ChangeCommissionedTransaction.h"
#include "ChangeMailTransaction.h"
#include "ChangeDirectTransaction.h"
#include "ChangeHoldTransaction.h"
#include "ChangeMemberTransaction.h"
#include "ChangeUnaffiliatedTransaction.h"
#include "PaydayTransaction.h"

#include <cassert>
#include <iostream>
#include "Mylib/MyAssert.h"

#include "PayrollImplementation/SalariedClassification.h"
#include "PayrollImplementation/HourlyClassification.h"
#include "PayrollImplementation/CommissionedClassification.h"

#include "PayrollImplementation/WeeklySchedule.h"
#include "PayrollImplementation/BiweeklySchedule.h"
#include "PayrollImplementation/MonthlySchedule.h"

#include "PayrollImplementation/HoldMethod.h"
#include "PayrollImplementation/DirectMethod.h"
#include "PayrollImplementation/MailMethod.h"

#include "PayrollImplementation/TimeCard.h"
#include "PayrollImplementation/SalesReceipt.h"
#include "PayrollImplementation/UnionAffiliation.h"
#include "PayrollImplementation/ServiceCharge.h"

#include "PayrollDomain/NoAffiliation.h"
#include "PayrollDomain/Paycheck.h"

extern PayrollDatabase GpayrollDatabase;

void PayrollTest::TestAddSalariedEmployee()
{
	int empId = 1;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.0);
	t.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert("Bob" == e->GetName());

	PaymentClassification* pc = e->GetClassification();
	SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
	assert(sc);
	assertEquals(1000.00, sc->GetSalary(), .001);
	
	PaymentSchedule* ps = e->GetSchedule();
	MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
	assert(ms);

	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}

void PayrollTest::TestAddHourlyEmployee()
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Elis", "AnotherHome", 5);
	t.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert("Elis" == e->GetName());

	PaymentClassification* pc = e->GetClassification();
	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	assert(hc);
	assertEquals(5.00, hc->GetHourlyRate(), .001);

	PaymentSchedule* ps = e->GetSchedule();
	WeeklySchedule* ws = dynamic_cast<WeeklySchedule*>(ps);
	assert(ws);

	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}

void PayrollTest::TestAddCommissionedEmployee()
{
	int empId = 3;
	AddCommissionedEmployee t(empId, "Eva", "AnotherHome", 700, 13.01);
	t.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert("Eva" == e->GetName());

	PaymentClassification* pc = e->GetClassification();
	CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc);
	assert(cc);
	assertEquals(700.00, cc->GetSalary(), .001);
	assertEquals(13.01, cc->GetCommissionRate(), .001);

	PaymentSchedule* ps = e->GetSchedule();
	BiweeklySchedule* bws = dynamic_cast<BiweeklySchedule*>(ps);
	assert(bws);

	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}

void PayrollTest::TestDeleteEmployee()
{
	std::cerr << "TestDeleteEmployee" << std::endl;
	int empId = 4;
	AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
	t.Execute();
	{
		Employee* e = GpayrollDatabase.GetEmployee(empId);
		assert(e);
	}
	DeleteEmployeeTransaction dt(empId);
	dt.Execute();
	{
		Employee* e = GpayrollDatabase.GetEmployee(empId);
		assert(e == nullptr);
	}
}

void PayrollTest::TestTimeCardTransaction()
{
	std::cerr << "TestTimeCardTransaction" << std::endl;
	int empId = 5;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	TimeCardTransaction tct(Date(31,10,2001), 8.0, empId);
	tct.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	PaymentClassification* pc = e->GetClassification();
	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	assert(hc);
	TimeCard* tc = hc->GetTimeCard(Date(31, 10, 2001));
	assert(tc);
	assertEquals(8.0, tc->GetHours(), 0.001);
}

void PayrollTest::TestSalesReceiptTransaction()
{
	std::cerr << "TestSalesReceiptTransaction" << std::endl;
	int empId = 6;
	AddCommissionedEmployee t(empId, "Jon", "Home", 2000, 1.25);
	t.Execute();

	SalesReceiptTransaction srt(Date(11, 9, 2001), 11.0, empId);
	srt.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	PaymentClassification* pc = e->GetClassification();
	CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc);
	assert(cc);
	SalesReceipt* sr = cc->GetSalesReceipt(Date(11, 9, 2001));
	assert(sr);
	assertEquals(11.0, sr->GetAmount(), 0.001);
}

void PayrollTest::TestAddServiceCharge()
{
	std::cerr << "TestAddServiceCharge" << std::endl;
	int emptId = 7;
	AddHourlyEmployee t(emptId, "Bill", "home", 15.25);
	t.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(emptId);
	assert(e);

	int memberId = 86;
	UnionAffiliation* af = new UnionAffiliation(memberId, 12.5);
	e->SetAffiliation(af);
	
	GpayrollDatabase.AddUnionMember(memberId, e);
	ServiceChargeTransaction sct(memberId, Date(11,1,2001), 12.95);
	sct.Execute();

	ServiceCharge* sc = af->GetServiceCharge(Date(11, 1, 2001));
	assert(sc);
	assertEquals(12.95, sc->GetAmount(), 0.001);
}

void PayrollTest::TestChangeNameTransaction()
{
	std::cerr << "TestChangeNameTransaction" << std::endl;
	int empId = 8;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	ChangeNameTransaction cnt(empId, "Bob");
	cnt.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	assert("Bob" == e->GetName());
}

void PayrollTest::TestAddressNameTransaction()
{
	std::cerr << "TestAddressNameTransaction" << std::endl;
	int empId = 9;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	ChangeAddressTransaction cat(empId, "AnotherHome");
	cat.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	assert("AnotherHome" == e->GetAddress());
}

void PayrollTest::TestChangeHourlyTransaction()
{
	std::cerr << "TestChangeHourlyTransaction" << std::endl;
	int empId = 10;
	AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
	t.Execute();
	ChangeHourlyTransaction cht(empId, 27.52);
	cht.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	PaymentClassification* pc = e->GetClassification();
	assert(pc);
	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	assert(hc);
	assertEquals(27.52, hc->GetHourlyRate(), 0.001);
	PaymentSchedule* ps = e->GetSchedule();
	WeeklySchedule* ws = dynamic_cast<WeeklySchedule*>(ps);
	assert(ws);
}

void PayrollTest::TestChangeSalariedTransaction()
{
	std::cerr << "TestChangeSalariedTransaction" << std::endl;
	int empId = 11;
	AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
	t.Execute();
	ChangeSalariedTransaction cst(empId, 3000);
	cst.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);

	PaymentClassification* pc = e->GetClassification();
	assert(pc);

	SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
	assert(sc);
	assertEquals(3000, sc->GetSalary(), .001);

	PaymentSchedule* ps = e->GetSchedule();
	MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
	assert(ms);
}

void PayrollTest::TestChangeCommissionedTransaction()
{
	std::cerr << "TestChangeCommissionedTransaction" << std::endl;
	int empId = 12;
	AddSalariedEmployee t(empId, "Lance", "Home", 2500);
	t.Execute();
	ChangeCommissionedTransaction cst(empId, 2000, 2.1);
	cst.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);

	PaymentClassification* pc = e->GetClassification();
	assert(pc);

	CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc);
	assert(cc);
	assertEquals(2000, cc->GetSalary(), .001);
	assertEquals(2.1, cc->GetCommissionRate(), .001);

	PaymentSchedule* ps = e->GetSchedule();
	BiweeklySchedule* bws = dynamic_cast<BiweeklySchedule*>(ps);
	assert(bws);
}

void PayrollTest::TestChangeMailTransaction()
{
	std::cerr << "TestChangeMailTransaction" << std::endl;
	int empId = 13;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.0);
	t.Execute();
	ChangeMailTransaction cmt(empId,"town, st.1");
	cmt.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);

	PaymentMethod* pm = e->GetMethod();
	MailMethod* mm = dynamic_cast<MailMethod*>(pm);
	assert(mm);
	assert("town, st.1" == mm->GetAddress());
}

void PayrollTest::TestChangeDirectTransaction()
{
	std::cerr << "TestChangeDirectTransaction" << std::endl;
	int empId = 14;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.0);
	t.Execute();
	ChangeDirectTransaction cdt(empId, "bank", "Account");
	cdt.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);

	PaymentMethod* pm = e->GetMethod();
	DirectMethod* dm = dynamic_cast<DirectMethod*>(pm);
	assert(dm);
	assert("bank" == dm->GetBank());
	assert("Account" == dm->GetAccount());
}

void PayrollTest::TestChangeHoldTransaction()
{
	std::cerr << "TestChangeHoldTransaction" << std::endl;
	int empId = 15;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.0);
	t.Execute();
	ChangeHoldTransaction cht(empId);
	cht.Execute();

	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);

	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}

void PayrollTest::TestChangeMemberTransaction()
{
	std::cerr << "TestChangeMemberTransaction" << std::endl;
	int empId = 16;
	int memberId = 7734;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	ChangeMemberTransaction cmt(empId, memberId, 99.42);
	cmt.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	Affiliation* af = e->GetAffiliation();
	assert(af);
	UnionAffiliation* uf = dynamic_cast<UnionAffiliation*>(af);
	assert(uf);
	assertEquals(99.42, uf->GetDues(), 0.001);
	Employee* member = GpayrollDatabase.GetUnionMember(memberId);
	assert(member);
	assert(e == member);
}

void PayrollTest::TestChangeUnaffiliatedTransaction()
{
	std::cerr << "TestChangeUnaffiliatedTransaction" << std::endl;
	int empId = 17;
	int memberId = 777;
	AddHourlyEmployee t(empId, "Boll", "Home", 15.25);
	t.Execute();
	
	ChangeMemberTransaction cmt(empId, memberId, 10);
	cmt.Execute();
	
	ChangeUnaffiliatedTransaction cuaft(empId);
	cuaft.Execute();
	
	Employee* e = GpayrollDatabase.GetEmployee(empId);
	assert(e);
	Affiliation* af = e->GetAffiliation();
	assert(af);
	NoAffiliation* nf = dynamic_cast<NoAffiliation*>(af);
	assert(nf);

}

void PayrollTest::ValidatePaycheck(PaydayTransaction& pt
	, int empId
	, const Date& payDate
	, double grossPay
	, double deductions
	, double netPay)
{
	Paycheck* pc = pt.GetPaycheck(empId);
	assert(pc);
	assert(pc->GetPayPeriodEndDate() == payDate);
	assertEquals(grossPay, pc->GetGrossPay(), 0.001);
	assert("Hold" == pc->GetField("Disposition"));
	assertEquals(deductions, pc->GetDeductions(), .001);
	assertEquals(netPay, pc->GetNetPay(), .001);
}

void PayrollTest::TestPaySingleSalariedEmployee()
{
	std::cerr << "TestPaySingleSalariedEmployee" << std::endl;
	int empId = 18;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
	t.Execute();
	Date payDate(30, 11, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 1000.00, 0.0, 1000.00);
}

void PayrollTest::TetsPaySingleSalariedEmployeeOnWrongDate()
{
	std::cerr << "TetsPaySingleSalariedEmployeeOnWrongDate" << std::endl;
	int empId = 19;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
	t.Execute();
	Date payDate(29, 11, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();
	Paycheck* pc = pt.GetPaycheck(empId);
	assert(pc == nullptr);
}

void PayrollTest::TetsPaySingleHourlyEmployeeNoTimeCards()
{
	std::cerr << "TetsPaySingleHourlyEmployeeNoTimeCards" << std::endl;
	int empId = 20;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate(9, 11, 2001); // Friday
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 0.0, 0.0, 0.0);
}

void PayrollTest::TestPaySingleHourlyEmployeeOneTimeCard()
{
	std::cerr << "TestPaySingleHourlyEmployeeOneTimeCard" << std::endl;
	int empId = 21;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate(9, 11, 2001); // Friday
	TimeCardTransaction tc(payDate, 2.0, empId);
	tc.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 30.5, 0.0, 30.5);
}

void PayrollTest::TestPaySingleHourlyEmployeeOvertimeOneTimeCard()
{
	std::cerr << "TestPaySingleHourlyEmployeeOvertimeOneTimeCard" << std::endl;
	int empId = 22;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate(9, 11, 2001); // Friday
	TimeCardTransaction tc(payDate, 9.0, empId);
	tc.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, (8+1.5)*15.25, 0.0, (8 + 1.5) * 15.25);
}

void PayrollTest::TestPaySingleHourlyEmployeeOnWrongDate()
{
	std::cerr << "TestPaySingleHourlyEmployeeOnWrongDate" << std::endl;
	int empId = 23;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate(8, 11, 2001); // Thursday 
	TimeCardTransaction tc(payDate, 9.0, empId);
	tc.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	Paycheck* pc = pt.GetPaycheck(empId);
	assert(pc == nullptr);
}

void PayrollTest::TestPaySingleHourlyEmployeeTwoTimeCard()
{
	std::cerr << "TestPaySingleHourlyEmployeeTwoTimeCard" << std::endl;
	int empId = 24;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate(9, 11, 2001); // Friday
	TimeCardTransaction tc(payDate, 2.0, empId);
	tc.Execute();
	TimeCardTransaction tc2(Date(8,11,2001), 5.0, empId);
	tc2.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 7*15.25, 0.0, 7 * 15.25);
}

void PayrollTest::TestPaySingleHourlyEmployeeWithTimeCardSpanningTwoPayPeriods()
{
	std::cerr << "TestPaySingleHourlyEmployeeWithTimeCardSpanningTwoPayPeriods" << std::endl;
	int empId = 25;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate(9, 11, 2001); // Friday
	Date dateInPreviousPayPeriod(2, 11, 2001);
	TimeCardTransaction tc(payDate, 2.0, empId);
	tc.Execute();
	TimeCardTransaction tc2(dateInPreviousPayPeriod, 5.0, empId);
	tc2.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 2 * 15.25, 0.0, 2 * 15.25);
}

void PayrollTest::TetsPaySingleCommissionedEmployeeNoSalesReceipt()
{
	std::cerr << "TetsPaySingleCommissionedEmployeeNoSalesReceipt" << std::endl;
	int empId = 26;
	AddCommissionedEmployee t(empId, "Bob", "Home", 1000, 2.2);
	t.Execute();
	Date payDate(24, 1, 2020); // second friday
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 1000.0, 0.0, 1000 - 0.0);
}

void PayrollTest::TestPaySingleCommissionedEmployeeOneSalesReceipt()
{
	std::cerr << "TestPaySingleCommissionedEmployeeOneSalesReceipt" << std::endl;
	int empId = 27;
	AddCommissionedEmployee t(empId, "Bob", "Home", 1000, 2.2);
	t.Execute();
	Date payDate(24, 1, 2020); // second friday
	SalesReceiptTransaction srt(payDate,500,empId);
	srt.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 1000.0 + 500 * 2.2, 0.0, 1000 + 500 * 2.2);
}

void PayrollTest::TestPaySingleCommissionedEmployeeOnWrongDate()
{
	std::cerr << "TestPaySingleCommissionedEmployeeOnWrongDate" << std::endl;
	int empId = 28;
	AddCommissionedEmployee t(empId, "Bob", "Home", 1000, 2.2);
	t.Execute();
	Date payDate(23, 1, 2020); // second friday
	SalesReceiptTransaction srt(payDate, 500, empId);
	srt.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	Paycheck* pc = pt.GetPaycheck(empId);
	assert(pc == nullptr);
}

void PayrollTest::TestPaySingleCommissionedEmployeeTwoSalesReceipt()
{
	std::cerr << "TestPaySingleCommissionedEmployeeTwoSalesReceipt" << std::endl;
	int empId = 29;
	AddCommissionedEmployee t(empId, "Bob", "Home", 1000, 2.2);
	t.Execute();
	Date payDate(24, 1, 2020); // second friday
	SalesReceiptTransaction srt(payDate, 500, empId);
	srt.Execute();
	SalesReceiptTransaction srt2(Date(13, 01, 2020), 100, empId);
	srt2.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 1000.0 + (100.0 + 500.0) * 2.2, 0.0, 1000 + (100.0 + 500.0) * 2.2);
}

void PayrollTest::TestPaySingleCommissionedEmployeeWithSalesReceiptSpanningTwoPayPeriods()
{
	std::cerr << "TestPaySingleCommissionedEmployeeWithSalesReceiptSpanningTwoPayPeriods" << std::endl;
	int empId = 30;
	AddCommissionedEmployee t(empId, "Bob", "Home", 1000, 2.2);
	t.Execute();
	Date payDate(24, 1, 2020); // second friday
	Date dateInPreviousPayPeriod(2, 1, 2020);
	SalesReceiptTransaction srt(payDate, 500, empId);
	srt.Execute();
	SalesReceiptTransaction srt2(dateInPreviousPayPeriod, 100, empId);
	srt2.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 1000.0 + 500 * 2.2, 0.0, 1000 + 500 * 2.2);
}

void PayrollTest::TestSalariedUnionMemberDues()
{
	std::cerr << "TestSalariedUnionMemberDues" << std::endl;
	int empId = 31;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
	t.Execute();
	int memberId = 7781;
	ChangeMemberTransaction cmt(empId, memberId, 9.42);
	cmt.Execute();
	Date payDate(30, 11, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();

	/*
	* membership fee is charged every Friday
	* November 2001 was 5 Fridays 
	*/
	ValidatePaycheck(pt, empId, payDate, 1000, 5 * 9.42, 1000 - 5 * 9.42);
}

void PayrollTest::TestHourlyUnionMemberServiceCharge()
{
	std::cerr << "TestHourlyUnionMemberServiceCharge" << std::endl;
	int empId = 32;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
	t.Execute();
	int memberId = 73;
	ChangeMemberTransaction cmt(empId, memberId, 9.42);
	cmt.Execute();
	Date payDate(9, 11, 2001);
	ServiceChargeTransaction sct(memberId, payDate, 19.42);
	sct.Execute();
	TimeCardTransaction tct(payDate, 8.0, empId);
	tct.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 15.24 * 8, 9.42 + 19.42, 15.24 * 8 - (9.42 + 19.42));
}

void PayrollTest::TestServiceChargesSpanningMultiplePayPeriods()
{
	std::cerr << "TestServiceChargesSpanningMultiplePayPeriods" << std::endl;
	int empId = 33;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
	t.Execute();
	int memberId = 74;
	ChangeMemberTransaction cmt(empId, memberId, 9.42);
	cmt.Execute();
	Date earlyDate(2, 11, 2001);
	Date payDate(9, 11, 2001);
	Date lateDate(16, 11, 2001);
	ServiceChargeTransaction sct(memberId, earlyDate, 100);
	sct.Execute();
	ServiceChargeTransaction sct2(memberId, lateDate, 200);
	sct2.Execute();
	TimeCardTransaction tct(payDate, 8.0, empId);
	tct.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empId, payDate, 15.24 * 8, 9.42, 15.24 * 8 - 9.42);
}

void PayrollTest::TestClearPayrollDatebase()
{
	GpayrollDatabase.clear();
}

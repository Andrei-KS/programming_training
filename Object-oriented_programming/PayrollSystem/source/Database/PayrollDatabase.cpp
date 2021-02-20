

#include "../../header/Database/PayrollDatabase.h"
#include "../../header/Employee.h"

PayrollDatabase GpayrollDatabase;

PayrollDatabase::~PayrollDatabase()
{
}

Employee* PayrollDatabase::GetEmployee(int empId)
{
	return itsEmployees[empId];
}

Employee* PayrollDatabase::GetUnionMember(int memberId)
{
	return itsEmployees[itsUnionMembers[memberId]];
}

void PayrollDatabase::AddEmployee(int empId, Employee* e)
{
	itsEmployees[empId] = e;
}

void PayrollDatabase::AddUnionMember(int memberId, Employee* e)
{
	itsUnionMembers[memberId] = e->GetEmpId();
	itsEmployeeToUnionMember[e->GetEmpId()] = memberId;
}

void PayrollDatabase::RemoveUnionMember(int memberId)
{
	std::unordered_map<int, int>::iterator it = itsUnionMembers.find(memberId);
	if (it != itsUnionMembers.end())
	{
		itsEmployeeToUnionMember.erase(it->second);
		itsUnionMembers.erase(it);
	}
}

void PayrollDatabase::DeleteEmployee(int empId)
{
	itsEmployees.erase(empId);
	std::unordered_map<int, int>::iterator it = itsEmployeeToUnionMember.find(empId);
	if (it != itsEmployeeToUnionMember.end())
	{
		itsUnionMembers.erase(it->second);
		itsEmployeeToUnionMember.erase(it);
	}
}

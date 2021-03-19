

#include "PayrollDatabase.h"
#include "PayrollDomain/Employee.h"

PayrollDatabase GpayrollDatabase;

PayrollDatabase::~PayrollDatabase()
{
	clear();
}

Employee* PayrollDatabase::GetEmployee(int empId) const
{
	std::unordered_map<int, Employee*>::const_iterator it = itsEmployees.find(empId);
	if (it != itsEmployees.end())
	{
		return it->second;
	}
	return nullptr;
}

Employee* PayrollDatabase::GetUnionMember(int memberId) const
{
	std::unordered_map<int, int>::const_iterator it = itsUnionMembers.find(memberId);
	if (it != itsUnionMembers.end())
	{
		return itsEmployees.at(it->second);
	}
	return nullptr;
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

void PayrollDatabase::clear()
{
	std::unordered_map<int, Employee*>::iterator it = itsEmployees.begin();
	while (it != itsEmployees.end())
	{
		delete it->second;
		it++;
	}
	itsEmployees.clear();
	itsUnionMembers.clear();
	itsEmployeeToUnionMember.clear();
}

void PayrollDatabase::DeleteEmployee(int empId)
{
	itsEmployees.erase(itsEmployees.find(empId));
	//itsEmployees.erase(empId);
	std::unordered_map<int, int>::iterator it = itsEmployeeToUnionMember.find(empId);
	if (it != itsEmployeeToUnionMember.end())
	{
		itsUnionMembers.erase(it->second);
		itsEmployeeToUnionMember.erase(it);
	}
}

void PayrollDatabase::GetAllEmployeeIds(std::list<int>& empIds) const
{
	empIds.clear();
	std::unordered_map<int, Employee*>::const_iterator it = itsEmployees.begin();
	while (it != itsEmployees.end())
	{
		empIds.push_back(it->second->GetEmpId());
		it++;
	}
}

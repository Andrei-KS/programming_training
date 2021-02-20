#ifndef __PAYROLLDATABASE_H__
#define __PAYROLLDATABASE_H__

#include <map>
#include <unordered_map>

class Employee;

class PayrollDatabase
{
public:
	virtual ~PayrollDatabase();
	Employee* GetEmployee(int empId);
	Employee* GetUnionMember(int memberId);
	void AddEmployee(int empId, Employee* e);
	void AddUnionMember(int memberId, Employee* e);
	void RemoveUnionMember(int memberId);
	void clear() { itsEmployees.clear(); }
	void DeleteEmployee(int empId);

private:
	std::unordered_map<int, Employee*> itsEmployees;
	std::unordered_map<int, int> itsUnionMembers;
	std::unordered_map<int, int> itsEmployeeToUnionMember;
};

#endif // !__PAYROLLDATABASE_H__

#include <cassert>
#include "myLibMath.h"

void TestEqualDouble_Equal()
{
	const double accuracy = 0.001;
	double lhs = 10.001;
	double rhs = 10.000;
	assert(myLibMath::EqualDouble(lhs, rhs,accuracy) == true);
}

void TestEqualDouble_NoEqual()
{
	const double accuracy = 0.001;
	double lhs = 10.002;
	double rhs = 10.000;
	assert(myLibMath::EqualDouble(lhs, rhs, accuracy) == false);
}

void TestLessOrEqualDouble_Less()
{
	const double accuracy = 0.001;
	double lhs = 5.000;
	double rhs = 10.000;
	assert(myLibMath::LessOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestLessOrEqualDouble_Equal()
{
	const double accuracy = 0.001;
	double lhs = 10.000;
	double rhs = 10.000;
	assert(myLibMath::LessOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestLessOrEqualDouble_EqualV2()
{
	const double accuracy = 0.001;
	double lhs = 10.001;
	double rhs = 10.000;
	assert(myLibMath::LessOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestLessOrEqualDouble_NoLessOrEqualDouble()
{
	const double accuracy = 0.001;
	double lhs = 15.000;
	double rhs = 10.000;
	assert(myLibMath::LessOrEqualDouble(lhs, rhs, accuracy) == false);
}

void TestLessOrEqualDouble_NoLessOrEqualDoubleV2()
{
	const double accuracy = 0.001;
	double lhs = 10.002;
	double rhs = 10.000;
	assert(myLibMath::LessOrEqualDouble(lhs, rhs, accuracy) == false);
}

void TestGreaterOrEqualDouble_Greater()
{
	const double accuracy = 0.001;
	double lhs = 15.000;
	double rhs = 10.000;
	assert(myLibMath::GreaterOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestGreaterOrEqualDouble_Equal()
{
	const double accuracy = 0.001;
	double lhs = 10.000;
	double rhs = 10.000;
	assert(myLibMath::GreaterOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestGreaterOrEqualDouble_EqualV2()
{
	const double accuracy = 0.001;
	double lhs = 10.001;
	double rhs = 10.000;
	assert(myLibMath::GreaterOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestGreaterOrEqualDouble_EqualV3()
{
	const double accuracy = 0.001;
	double lhs = 9.999;
	double rhs = 10.000;
	assert(myLibMath::GreaterOrEqualDouble(lhs, rhs, accuracy) == true);
}

void TestGreaterOrEqualDouble_NoGreaterOrEqualDouble()
{
	const double accuracy = 0.001;
	double lhs = 5.000;
	double rhs = 10.000;
	assert(myLibMath::GreaterOrEqualDouble(lhs, rhs, accuracy) == false);
}

void TestGreaterOrEqualDouble_NoGreaterOrEqualDoubleV2()
{
	const double accuracy = 0.001;
	double lhs = 9.998;
	double rhs = 10.000;
	assert(myLibMath::GreaterOrEqualDouble(lhs, rhs, accuracy) == false);
}

int main()
{
	TestEqualDouble_Equal();
	TestEqualDouble_NoEqual();

	TestLessOrEqualDouble_Less();
	TestLessOrEqualDouble_Equal();
	TestLessOrEqualDouble_EqualV2();
	TestLessOrEqualDouble_NoLessOrEqualDouble();
	TestLessOrEqualDouble_NoLessOrEqualDoubleV2();

	TestGreaterOrEqualDouble_Greater();
	TestGreaterOrEqualDouble_Equal();
	TestGreaterOrEqualDouble_EqualV2();
	TestGreaterOrEqualDouble_EqualV3();
	TestGreaterOrEqualDouble_NoGreaterOrEqualDouble();
	TestGreaterOrEqualDouble_NoGreaterOrEqualDoubleV2();

	return 0;
}
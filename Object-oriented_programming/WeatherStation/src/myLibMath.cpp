

#include "myLibMath.h"
bool myLibMath::EqualDouble(double lhs, double rhs, double accuracy)
{
	return abs(lhs - rhs) < accuracy;
}

bool myLibMath::LessOrEqualDouble(double lhs, double rhs, double accuracy)
{
	return lhs < rhs || EqualDouble(lhs,rhs,accuracy);
}

bool myLibMath::GreaterOrEqualDouble(double lhs, double rhs, double accuracy)
{
	return lhs > rhs || EqualDouble(lhs, rhs, accuracy);
}
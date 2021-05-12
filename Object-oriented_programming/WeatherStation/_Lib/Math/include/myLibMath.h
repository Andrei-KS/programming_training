#ifndef __MYLIBMATH_H__
#define __MYLIBMATH_H__

#include <cmath>
namespace myLibMath
{
	/**
	* Ñomparison of numbers for equality
	* 
	* Comparison of two double numbers for equality can be performed only with some precision due to their machine representation
	* @param lhs - the number is to the left of the equal sign 
	* @param rhs - the number is to the right of the equal sign 
	* @param accuracy - the accuracy with which the calculations will be carried out
	* @return true if the left value is equal to the right one with the specified precision, false if otherwise 
	*/
	bool EqualDouble(double lhs, double rhs, double accuracy);
	
	/**
	* Means "less than or equal to"
	* 
	* Comparison of two double numbers for equality can be performed only with some precision due to their machine representation
	* @param lhs - the number is to the left of the "less that or equal to" sign
	* @param rhs - the number is to the right of the "less that or equal to" sign
	* @param accuracy - the accuracy with which the calculations will be carried out 
	* @return true if the left value is less that or equal to the right one with the specified precision, false if otherwise
	*/
	bool LessOrEqualDouble(double lhs, double rhs, double accuracy);
	
	/**
	* Means "greater than or equal to"
	*
	* Comparison of two double numbers for equality can be performed only with some precision due to their machine representation
	* @param lhs - the number is to the left of the "greater that or equal to" sign
	* @param rhs - the number is to the right of the "greater that or equal to" sign
	* @param accuracy - the accuracy with which the calculations will be carried out
	* @return true if the left value is greater that or equal to the right one with the specified precision, false if otherwise
	*/
	bool GreaterOrEqualDouble(double lhs, double rhs, double accuracy);
}

#endif // !__MYLIBMATH_H__
#ifndef __UTESTMATH_H__
#define __UTESTMATH_H__

#include "myUTest.h"

/**
* Description of class UTestMath
* This class check function class myLibMath
* @see myLibMath
*/
class UTestMath : public myUTest
{
public:
	/**
	* function to run all tests
	*/
	virtual void excute() override;

protected:
	/**
	* 
	*/
	void TestEqualDouble_Equal();

	/**
	* 
	*/
	void TestEqualDouble_NoEqual();

	/**
	*
	*/
	void TestLessOrEqualDouble_Less();

	/**
	*
	*/
	void TestLessOrEqualDouble_Equal();

	/**
	*
	*/
	void TestLessOrEqualDouble_EqualV2();

	/**
	*
	*/
	void TestLessOrEqualDouble_NoLessOrEqualDouble();

	/**
	*
	*/
	void TestLessOrEqualDouble_NoLessOrEqualDoubleV2();

	/**
	*
	*/
	void TestGreaterOrEqualDouble_Greater();

	/**
	*
	*/
	void TestGreaterOrEqualDouble_Equal();

	/**
	*
	*/
	void TestGreaterOrEqualDouble_EqualV2();

	/**
	*
	*/
	void TestGreaterOrEqualDouble_EqualV3();

	/**
	*
	*/
	void TestGreaterOrEqualDouble_NoGreaterOrEqualDouble();

	/**
	*
	*/
	void TestGreaterOrEqualDouble_NoGreaterOrEqualDoubleV2();
};

#endif // !__UTESTMATH_H__
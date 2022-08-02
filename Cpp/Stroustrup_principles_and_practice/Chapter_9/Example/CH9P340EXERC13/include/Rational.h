#ifndef __RATIONAL_H__
#define __RATIONAL_H__

namespace MyLib
{
	/*
	*/
	class Rational
	{
	private:
		/**/
		int mNumerator;
		/**/
		int mDenominator;

	public:
		/* to throw as exception */
		class Invalid {};

		/* check for valid date and initialize */
		Rational(int numerator,int denominator);

		/* default constructor */
		Rational();

		// the default copy operations are fine

		// nonmodifying operations:
		/**/
		int numerator() const { return mNumerator; }

		/**/
		int denominator() const { return mDenominator; }

		operator double() { return static_cast<double>(mNumerator) / mDenominator; }
	};

	bool is_rational(int numerator, int denominator);
	void swap(int& left, int& right);
	int greatest_common_divisor(int left, int right);
	int least_common_multiple(int left, int right);

	bool operator==(const Rational& left, const Rational& right);
	bool operator!=(const Rational& left, const Rational& right);

	Rational operator+(const Rational& left, const Rational& right);
	Rational operator-(const Rational& left, const Rational& right);
	Rational operator*(const Rational& left, const Rational& right);
	Rational operator/(const Rational& left, const Rational& right);

} // namespace MyLib

#endif // !__RATIONAL_H__
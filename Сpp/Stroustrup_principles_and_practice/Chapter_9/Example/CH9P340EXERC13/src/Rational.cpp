#include "Rational.h"

namespace MyLib
{
	Rational::Rational(int numerator, int denominator)
		: mNumerator(numerator),
		mDenominator(denominator)
	{
		if (!is_rational(mNumerator, mDenominator))
		{
			throw Invalid{};
		}
		if (mNumerator == 0)
		{
			mDenominator = 1;
			return;
		}
		if (mDenominator < 0)
		{
			mDenominator *= -1;
			mNumerator *= -1;
		}

		int gcd = greatest_common_divisor(mNumerator, mDenominator);
		mNumerator /= gcd;
		mDenominator /= gcd;
	}

	const Rational& zero_rational()
	{
		// start of 21st century
		static Rational rational{0,1};
		return rational;
	}

	Rational::Rational()
		: mNumerator(zero_rational().numerator()),
		mDenominator(zero_rational().denominator())
	{
	}

	bool is_rational(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			return false;
		}
	}

	void swap(int& left, int& right)
	{
		left = left ^ right;
		right = left ^ right;
		left = left ^ right;
	}

	int greatest_common_divisor(int left, int right)
	{
		left = left < 0 ? -left : left;
		right = right < 0 ? -right : right;
		if (left < right)
		{
			swap(left, right);
		}
		while (left % right != 0)
		{
			left = left % right;
			swap(left, right);
		}
		return right;
	}

	int least_common_multiple(int left, int right)
	{
		return (left / greatest_common_divisor(left, right)) * right;
	}

	bool operator==(const Rational& left, const Rational& right)
	{
		return left.numerator() == right.numerator() && left.denominator() == right.denominator();
	}

	bool operator!=(const Rational& left, const Rational& right)
	{
		return !(left == right);
	}

	Rational operator+(const Rational& left, const Rational& right)
	{
		int gcdDenominator = greatest_common_divisor(left.denominator(), right.denominator());
		int lcmDenominator = least_common_multiple(left.denominator(), right.denominator());
		int leftMultiplier = right.denominator() / gcdDenominator;
		int rightMultiplier = left.denominator() / gcdDenominator;
		return Rational(left.numerator() * leftMultiplier + right.numerator() * rightMultiplier, lcmDenominator);
	}

	Rational operator-(const Rational& left, const Rational& right)
	{
		return left + Rational(-right.numerator(), right.denominator());
	}

	Rational operator*(const Rational& left, const Rational& right)
	{
		if (left == zero_rational() || right == zero_rational())
		{
			return zero_rational();
		}

		int gcdLeft = greatest_common_divisor(left.numerator(), right.denominator());
		int gcdRight = greatest_common_divisor(right.numerator(), left.denominator());

		return Rational((left.numerator()/gcdLeft) * (right.numerator()/gcdRight),(left.denominator()/gcdRight)*(right.denominator()/gcdLeft));
	}

	Rational operator/(const Rational& left, const Rational& right)
	{
		if (right == zero_rational())
		{
			throw Rational::Invalid();
		}
		return left * Rational(right.denominator(), right.numerator());
	}
}
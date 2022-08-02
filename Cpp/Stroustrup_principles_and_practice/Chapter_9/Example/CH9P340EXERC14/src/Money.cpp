#include "Money.h"

namespace MyLib
{
	Money::Money(long int amountCents)
		: itsAmount(amountCents)
	{}

	const Money& default_money()
	{
		static Money money(0);
		return money;
	}

	Money::Money()
		: itsAmount(default_money().amount())
	{}

	double rounding_to_hundredths(double value)
	{
		long int integerPart = static_cast<long int>(value);
		double fractionalPart = value - integerPart;
		long int hundredths = fractionalPart * 100;
		long int thousandths = fractionalPart * 1000;
		hundredths += ((thousandths - hundredths *10l) >= 5l ? 1l : 0l);
		return integerPart + static_cast<double>(hundredths)/100;
	}

	bool operator==(const Money& left, const Money& right)
	{
		return left.amount() == right.amount();
	}

	bool operator!=(const Money& left, const Money& right)
	{
		return !(left == right);
	}

	Money operator+(const Money& left, const Money& right)
	{
		return Money(left.amount() + right.amount());
	}

	Money operator-(const Money& left, const Money& right)
	{
		return Money(left.amount() - right.amount());
	}

	Money operator*(const Money& left, const double right)
	{
		return Money(rounding_to_hundredths(static_cast<double>(left.amount())/100 * right)*100);
	}

	Money operator*(const double left,const Money& right)
	{
		return Money(rounding_to_hundredths(static_cast<double>(right.amount()) / 100 * left) * 100);
	}

	Money operator/(const Money& left, double right)
	{
		return left * (1./right);
	}
}
#include "Money.h"

namespace MyLib
{
	Money::Money(const long int amountCents, const Currency currency)
		: itsAmount(amountCents),
		itsCurrency(currency)
	{}

	const Money& default_money()
	{
		static Money money(0,Currency::USD);
		return money;
	}

	Money::Money()
		: itsAmount(default_money().amount()),
		itsCurrency(default_money().currency())
	{}

	long int rounding_to_hundredths(double value)
	{
		long int integerPart = static_cast<long int>(value);
		double fractionalPart = value - integerPart;
		long int hundredths = fractionalPart * 100;
		long int thousandths = fractionalPart * 1000;
		hundredths += ((thousandths - hundredths *10l) >= 5l ? 1l : 0l);
		return integerPart*100 + hundredths;
	}

	Money currency_exchange(const Money& sources, const Currency type)
	{
		if (sources.currency() == type)
		{
			return sources;
		}
		// USD 1 = 76.48 RUB
		// EUR 1 = 86.28 RUB
		// CYN 1 = 12.02 RUB
		constexpr double USD_TO_RUB = 76.48;
		constexpr double EUR_TO_RUB = 86.28;
		constexpr double CNY_TO_RUB = 12.02;

		double exchange_multiplier = -1;
		if (sources.currency() == Currency::USD && type == Currency::RUB) exchange_multiplier = USD_TO_RUB;
		if (sources.currency() == Currency::EUR && type == Currency::RUB) exchange_multiplier = EUR_TO_RUB;
		if (sources.currency() == Currency::CNY && type == Currency::RUB) exchange_multiplier = CNY_TO_RUB;
		if (sources.currency() == Currency::USD && type == Currency::EUR) exchange_multiplier = USD_TO_RUB / EUR_TO_RUB;
		if (sources.currency() == Currency::USD && type == Currency::CNY) exchange_multiplier = USD_TO_RUB / CNY_TO_RUB;
		if (sources.currency() == Currency::EUR && type == Currency::USD) exchange_multiplier = EUR_TO_RUB / USD_TO_RUB;
		if (sources.currency() == Currency::EUR && type == Currency::CNY) exchange_multiplier = EUR_TO_RUB / CNY_TO_RUB;
		if (sources.currency() == Currency::CNY && type == Currency::USD) exchange_multiplier = CNY_TO_RUB / USD_TO_RUB;
		if (sources.currency() == Currency::CNY && type == Currency::EUR) exchange_multiplier = CNY_TO_RUB / EUR_TO_RUB;
		if (exchange_multiplier < 0)
		{
			throw Money::Invalid();
		}

		return Money(rounding_to_hundredths(static_cast<double>(sources.amount()) / 100 * exchange_multiplier), sources.currency());
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
		Money rightInLeftCurrency = currency_exchange(right, left.currency());
		return Money(left.amount() + rightInLeftCurrency.amount(),left.currency());
	}

	Money operator-(const Money& left, const Money& right)
	{
		Money rightInLeftCurrency = currency_exchange(right, left.currency());
		return Money(left.amount() - rightInLeftCurrency.amount(), left.currency());
	}

	Money operator*(const Money& left, const double right)
	{
		return Money(rounding_to_hundredths(static_cast<double>(left.amount())/100 * right),left.currency());
	}

	Money operator*(const double left,const Money& right)
	{
		return Money(rounding_to_hundredths(static_cast<double>(right.amount()) / 100 * left), right.currency());
	}

	Money operator/(const Money& left, double right)
	{
		return left * (1./right);
	}
}
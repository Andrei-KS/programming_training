#ifndef __MONEY_H__
#define __MONEY_H__

#include <iostream>

namespace MyLib
{
	enum class Currency
	{
		USD = 1,
		EUR,
		CNY,
		RUB
	};

	/*
	*/
	class Money
	{
	private:
		/*the amount of monetary units of the minimum denomination of the currency */
		long int itsAmount;

		/**/
		Currency itsCurrency;

	public:
		/* to throw as exception */
		class Invalid {};

		/* 
		*check for valid date and initialize
		*@param amount amountCents - the number of monetary units of the minimum denomination of the currency 
		*/
		explicit Money(const long int amountCents,const Currency);

		/* default constructor */
		explicit Money();

		// the default copy operations are fine

		// nonmodifying operations:
		/**/
		long amount() const { return itsAmount; }
		/**/
		Currency currency() const { return itsCurrency; }
	};

	/*
	* function use the 4/5 rounding rule for rounding double to hundredths.
	* .5 of a hundredths rounds up, anything less than .5 rounds down
	* @param value - will be rounded 
	* @return rounding result 
	*/
	long int rounding_to_hundredths(double value);
	
	/**/
	Money currency_exchange(const Money& sources, const Currency type);
	
	bool operator==(const Money& left, const Money& right);
	bool operator!=(const Money& left, const Money& right);

	Money operator+(const Money& left, const Money& right);
	Money operator-(const Money& left, const Money& right);

	Money operator*(const Money& left, const double right);
	Money operator*(const double left, const Money& right);
	Money operator/(const Money& left, double right);

	std::ostream& operator<<(std::ostream& os, const Money& money);
	std::istream& operator>>(std::istream& is, Money& money);
}

#endif // !__MONEY_H__
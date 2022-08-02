#ifndef __MONEY_H__
#define __MONEY_H__

namespace MyLib
{
	/*
	*/
	class Money
	{
	private:
		/*the amount of monetary units of the minimum denomination of the currency */
		long int itsAmount;



	public:
		/* to throw as exception */
		class Invalid {};

		/* 
		*check for valid date and initialize
		*@param amount amountCents - the number of monetary units of the minimum denomination of the currency 
		*/
		explicit Money(long int amountCents);

		/* default constructor */
		explicit Money();

		// the default copy operations are fine

		// nonmodifying operations:
		/**/
		long amount() const { return itsAmount; }
	};

	/*
	* function use the 4/5 rounding rule for rounding double to hundredths.
	* .5 of a hundredths rounds up, anything less than .5 rounds down
	* @param value - will be rounded 
	* @return rounding result 
	*/
	double rounding_to_hundredths(double value);

	bool operator==(const Money& left, const Money& right);
	bool operator!=(const Money& left, const Money& right);

	Money operator+(const Money& left, const Money& right);
	Money operator-(const Money& left, const Money& right);

	Money operator*(const Money& left, const double right);
	Money operator*(const double left, const Money& right);
	Money operator/(const Money& left, double right);
}

#endif // !__MONEY_H__
#ifndef __PATRON_H__
#define __PATRON_H__

#include <string>

namespace MyLib
{
	using string = std::string;

	class Patron
	{
	private:
		/* a name of patron */
		string itsName;

		/* a library card number of patron */
		size_t itsLibraryCardNumber;

		/* a library fees of patron */
		double itsLibraryFees;

		/* a data about a fee is paid or not */
		bool isFeePaid;

	public:
		/* to throw as exception */
		class Invalid {};

		/* default constructor */
		Patron();

		// the default copy operations are fine

		/* check for valid date and initialize */
		Patron(const string& name, const size_t libraryCardNumber, const double libraryFees);

		// modifying operations:

		/* @return a name of patron */
		const string& name() const { return itsName; }
		
		/* @return a library card number of patron */
		const size_t& libraryCardNumber() const { return itsLibraryCardNumber; }

		/* @return a library fees of patron */
		const double libraryFees() const { return itsLibraryFees; }

		/*
		* get data about a fee is paid or not.
		* @return true if a fee is paid.
		*/
		const bool is_fee_paid() const { return isFeePaid; }

		// modifying operations:

		/*
		* set sum of fee
		* @param libraryFees - is sum of fee
		*/
		void set_library_fees(double libraryFees) { itsLibraryFees = libraryFees; }

		/*
		* set flag of fee payment
		* @param value - true if fee is paid, otherwise false
		*/
		void set_fee_paid(bool value) { isFeePaid = value; }
	};

	bool operator==(const Patron& lPatron, const Patron& rPatron);
	bool operator!=(const Patron& lPatron, const Patron& rPatron);
}

#endif // !__PATRON_H__
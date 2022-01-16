#include "Patron.h"

namespace MyLib
{
	const Patron& default_patron()
	{
		static Patron patron = {
			"",
			0,
			0,
		};

		return patron;
	}

	Patron::Patron()
		: itsName(default_patron().name()),
		itsLibraryCardNumber(default_patron().libraryCardNumber()),
		itsLibraryFees(default_patron().libraryFees()),
		isFeePaid(default_patron().is_fee_paid())
	{}

	Patron::Patron(const string& name, const size_t libraryCardNumber, const double libraryFees)
		: itsName(name),
		itsLibraryCardNumber(libraryCardNumber),
		itsLibraryFees(libraryFees),
		isFeePaid(false)
	{}
}
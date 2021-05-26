#ifndef __DATE_H__
#define __DATE_H__

/**
* Description of class Date
* Methods of this class allow you to extend the functionality of working with dates.
*/
class Date
{
public:
	/**
	* Constructor for creating a new Date with today date
	*/
	Date();

	/**
	* Constructor for creating a new Date
	* @param day - day of month 
	* @param month - month number 
	* @param year - year number 
	*/
	Date(char day, char month, short year);
	
	/**
	* Destructor for created the Date
	*/
	~Date();
	
	/**
	* 
	*/
	char GetDay() const;
	
	/**
	* 
	*/
	char GetMonth() const;
	
	/**
	* 
	*/
	short GetYear() const { return itsYear; }
	
	/**
	* 
	*/
	char GetDayOfWeek() const;
	
	/**
	* 
	*/
	short GetAmountOfDaysPassedInCurrentYear() const { return itsDays; }

	
	/**
	* 
	*/
	static short AmountOfDaysMonth(int monthNumber, int year);
	
	/**
	* 
	*/
	static short AmountOfDayYear(int year);
	
	/**
	* 
	*/
	static bool IsYearleap(int year);
	
	/**
	* 
	*/
	static bool IsBetween(const Date& theDate, const Date& startDate, const Date& endDate);

	friend bool operator<(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);
	friend bool operator>(const Date& left, const Date& right);
	friend bool operator<=(const Date& left, const Date& right);
	friend bool operator>=(const Date& left, const Date& right);

	friend Date operator+(const Date& left, const int& right);
	friend Date operator-(const Date& left, const int& right);
	
	Date& operator+=(const int& right);
	Date& operator-=(const int& right);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	/** the field contains the correspondence between the day of the week and the number  */
	enum
	{
		Monday = 1,
		Tuesday = 2,
		Wednesday = 3,
		Thursday = 4,
		Friday = 5,
		Saturday = 6,
		Sunday = 7,
		AmountDaysPerWeek = 7
	};

private:
	/** the field contains the number of the day of the year  */
	short itsDays;

	/** the field contains the year number  */
	short itsYear;
};

#endif // !__DATE_H__
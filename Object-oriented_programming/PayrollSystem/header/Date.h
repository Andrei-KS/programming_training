#ifndef __DATE_H__
#define __DATE_H__

//enum class Date

class Date
{
public:
	~Date();
	Date(char day, char month, short year);

	char GetDay() const;
	char GetMonth() const;
	short GetYear() const { return itsYear; }
	char GetDayOfWeek() const;

	friend bool operator<(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);
	friend bool operator>(const Date& left, const Date& right);
	friend bool operator<=(const Date& left, const Date& right);
	friend bool operator>=(const Date& left, const Date& right);

	friend const Date operator+(const Date& left, const int& right);
	friend const Date operator-(const Date& left, const int& right);

	static short AmountOfDaysMonth(int monthNumber, int year);
	static short AmountOfDayYear(int year);
	static bool IsYearleap(int year);
	
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
	short itsDays;
	short itsYear;
};

#endif // !__DATE_H__
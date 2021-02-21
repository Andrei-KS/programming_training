#ifndef __DATE_H__
#define __DATE_H__

class Date
{
public:
	~Date();
	Date(char day, char month, short year);

	char GetDay() const;
	char GetMonth() const;
	short GetYear() const { return itsYear; }

	friend bool operator<(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);
	friend bool operator>(const Date& left, const Date& right);
	friend bool operator<=(const Date& left, const Date& right);
	friend bool operator>=(const Date& left, const Date& right);

	friend const Date operator+(const Date& left, const int& right);
	friend const Date operator+(const int& left, const Date& right);

	static short AmountOfDaysMonth(int monthNumber, int year);
	static short AmountOfDayYear(int year);
	static bool IsYearleap(int year);

	static const short StartDaysYear[];
	static const short StartDaysLeapYear[];

private:
	short itsDays;
	short itsYear;
};

#endif // !__DATE_H__
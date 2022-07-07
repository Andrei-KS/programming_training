/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/07/2022 15:13:12
	author														: Andrei-KS
*/

#include "CH10P376DRILL2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P376DRILL2RunExmple();

namespace {
	struct Point {
		double x;
		double y;
	};

	istream& operator>>(istream& is, Point& point)
	{
		double x, y;
		char ch1, ch2, ch3;


		is >> ch1 >> x >> ch2 >> y >> ch3;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ')')
		{ //format error
			is.clear(ios_base::failbit);
			return is;
		}

		point.x = x;
		point.y = y;
		return is;
	}

	ostream& operator<<(ostream& os, const Point& point)
	{
		return os << '(' << point.x
			<< ", " << point.y
			<< ')' << std::endl;
	}

	void fill_from_file(vector<Point>& points, const string& name)
	{
		ifstream ist{ name };
		if (!ist)
		{
			error("can't open input file", name);
		}

		for (Point point; ist >> point;)
		{
			points.push_back(point);
		}

		ist.close();
	}

	void fill_to_file(vector<Point>& points, const string& name)
	{
		ofstream ost{ name };
		if (!ost)
		{
			error("can't open input file", name);
		}

		for (const Point& point : points)
		{
			ost << point;
		}

		ost.close();
	}

	void printPoints(const vector<Point>& points)
	{
		for (const Point& point : points)
		{
			std::cout << point;
		}
	}
}

int CH10P376DRILL2RunExmple::excute()
{
	std::cout << "Please enter seven (x,y) pairs\n";
	int number_of_points = 7;
	vector<Point> original_points;
	for (Point point; original_points.size() < number_of_points;)
	{
		std::cin >> point;
		if (std::cin)
		{
			original_points.push_back(point);
		}
		else if (std::cin.fail())
		{
			// if entering is fail, we will discard remaining entered and start new entering symbols
			std::cin.clear();
			std::cin.seekg(std::ios_base::end);
			int remaining_numbers_pairs = number_of_points - original_points.size();
			std::cout << "Sorry, that is invalid pairs; please try again (need to enter " 
				<< remaining_numbers_pairs << " more pair" << (remaining_numbers_pairs>1?"s":"") << ")\n";
		}
		else
		{
			error("no input");
		}

	}

	printPoints(original_points);
	return 0;
}
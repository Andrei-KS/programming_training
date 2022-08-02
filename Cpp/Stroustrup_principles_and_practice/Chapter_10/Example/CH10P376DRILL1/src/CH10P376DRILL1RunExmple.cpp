/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/07/2022 14:04:34
	author														: Andrei-KS
*/

#include "CH10P376DRILL1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P376DRILL1RunExmple();

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

int CH10P376DRILL1RunExmple::excute()
{
	vector<Point> points_test{ {1,1}, {1,2}, {2,1} };
	fill_to_file(points_test, "TEST_1");

	vector<Point> points_test2;
	fill_from_file(points_test2, "TEST_1");

	printPoints(points_test2);

	return 0;
}
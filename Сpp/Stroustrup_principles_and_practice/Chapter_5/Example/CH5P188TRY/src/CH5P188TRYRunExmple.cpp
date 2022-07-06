/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/28/2021 00:45:17
	author														: Andrei-KS
*/

#include "CH5P188TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P188TRYRunExmple();

namespace {
	int area(int length, int width)
	{
		if (length < 0) error("length cannot equal to negative.");
		if (width < 0) error("width cannot equal to negative.");
		return length * width;
	}
	
	int framed_area(int length, int width)
	{
		constexpr int frame_length = 2;
		constexpr int frame_width = 2;
		if (length < 0) error("length cannot less than 0.");
		if (width < 0) error("width cannot less than 0.");
		ostringstream os;
		if (length < frame_length )
		{
			os << "length cannot less than " << frame_length;
			error(os.str());
		}
		if (width < frame_width)
		{
			os << "width cannot less than " << frame_width;
			error(os.str());
		}
		return area(length - frame_width, width - frame_width);
	}

	int f(int x, int y, int z)
	{
		constexpr int value = 3;
		int area1 = area(x, y);
		if (area1 <= 0) error("area cannot less than 0.");
		int area2 = framed_area(value, z);
		int area3 = framed_area(y, z);
		if (area3 == 0) error("area3 cannot equal zero.");
		double ratio = double(area1) / area3;
		return ratio;
	}
}

int CH5P188TRYRunExmple::excute()
{
	cout << f(4, 5, 6);
	return 0;
}
/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/29/2021 10:18:22
	author														: Andrei-KS
*/

#include "CH5P211TASKRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P211TASKRunExmple();

namespace {
}

int CH5P211TASKRunExmple::excute()
{
	try {
		{
			cout << "Success!\n";
		}
		{
			cout << "Success!\n";
		}
		{
			cout << "Success" << "!\n";
		}
		{
			cout << "success" << '\n';
		}
		{
			int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
		}
		{
			vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
		}
		{
			bool cond = true;  if (cond) cout << "Success!\n"; else cout << "Fail!\n";
		}
		{
			bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
		}
		{
			string s = "ape"; bool c = "fool" < s; if (c) cout << "Success!\n";
		}
		{
			string s = "ape"; if (s != "fool") cout << "Success!\n";
		}
		{
			string  s = "ape";  if (s != "fool")  cout << "Success ! \n";
		}
		{
			string  s = "ape";  if (s != "fool")  cout << "Success! \n";
		}
		{
			vector<char> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success! \n";
		}
		{
			vector<char> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success! \n";
		}
		{
			string s = "Success! \n"; for (int i = 0; i < 11; ++i) cout << s[i];
		}
		{
			if (true) cout << "Success! \n"; else cout << "Fail ! \n";
		}
		{
			int x = 2000; int с = x; if (с == 2000) cout << "Success ! \n";
		}
		{
			string s = "Success! \n"; for (int i = 0; i < 10; ++i) cout << s[i];
		}
		{
			vector<int> v(5); for(int i = 0; i <= v.size(); ++i); cout << "Success! \n";
		}
		{
			int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success! \n";
		}
		{
			int x = 2; double d = 4.5;  if (d == 2 * x + 0.5) cout << "Success! \n";
		}
		{
			string s = "Success ! \n";  for (int i = 0; i <= 10; ++i)  cout << s[i];
		}
		{
			int  i = 0;  while (i < 10)  ++i;  if (9 < i)  cout << "Success! \n";
		}
		{
			int  x = 4; double d = 5 / (x - 2);  if (d = 2 * x + 0.5)  cout << "Success! \n";
		}
		{
			cout << "Success! \n";
		}
		keep_window_open();
		return 0;
	}
	catch (exception& e)
	{
		cerr << "Error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown error!\n";
		keep_window_open();
		return 2;
	}
	return 0;
}
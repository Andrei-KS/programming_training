/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/13/2023 09:29:22
	author                                          : Andrei-KS
*/

#include "CH21P799DRILL1_10RunExmple.h"
#include <numeric>
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P799DRILL1_10RunExmple();

namespace {
}

int CH21P799DRILL1_10RunExmple::excute()
{
  string sFileName{ "CH21P799DRILL1_10Data" };
  ifstream ifsFile{ sFileName };
  if (!ifsFile.is_open())
  {
    error("Can't open " + sFileName);
  }

  istream_iterator<double> iid{ ifsFile };
  istream_iterator<double> eos;

  cout << "\n--- read data from " << sFileName << ": ---\n";
  vector<double> vd{ iid,eos };
  ifsFile.close();
  ostream_iterator<double> oid{ cout,"\n" };
  copy(vd.begin(), vd.end(), oid);

  cout << "\n--- vd to vi: ---\n";
  vector<int> vi;
  for_each(vd.begin(), vd.end(), [&vi](double value) {vi.push_back(static_cast<int>(value)); });
  ostream_iterator<int> oii{ cout, "\n" };
  copy(vi.begin(), vi.end(), oii);

  cout << "\n--- pair(vd[i],vi[i]): ---\n";
  int iStartIndex = 0;
  int iEndIndex = min(static_cast<int>(vd.size()), static_cast<int>(vi.size()));
  for (int iIndex = iStartIndex; iIndex < iEndIndex; ++iIndex)
  {
    cout << "(" << vd[iIndex]
      << "," << vi[iIndex]
      << ")\n";
  }

  cout << "\n--- sum of the elements of vd ---\n";
  double dSumvd = accumulate(vd.begin(), vd.end(), 0.0, [](double dCurrentValue, double dNextValue) {return dCurrentValue + dNextValue; });
  cout << dSumvd;

  cout << "\n--- sum(vd) - sum(vi): ---\n";
  double dSumvi = accumulate(vi.begin(), vi.end(), 0.0, [](double dCurrentValue, double dNextValue) {return dCurrentValue + dNextValue; });
  cout << dSumvd << " - " << dSumvi << " = " << (dSumvd - dSumvi);

  cout << "\n--- reverse(vd): ---\n";
  reverse(vd.begin(), vd.end());
  copy(vd.begin(), vd.end(), oid);

  cout << "\n--- mean value of vd: ---\n";
  if (!vd.size()) error("vd doesn't have elements!");
  double dMeanValuevd = dSumvd / vd.size();
  cout << dMeanValuevd;

  cout << "\n--- vd2: ---\n";
  vector<double> vd2;
  for_each(vd.begin(), vd.end(), [&vd2,dMeanValuevd](double value) {if(value < dMeanValuevd) vd2.push_back(value); });
  copy(vd2.begin(), vd2.end(), oid);

  cout << "\n--- sort(vd) ---\n";
  sort(vd);
  copy(vd.begin(), vd.end(), oid);

	return 0;
}
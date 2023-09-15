/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 14:57:59
	author                                          : Andrei-KS
*/

#include "CH21P792TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P792TRYRunExmple();

namespace {
  void good_version()
  {
    string from, to;
    // get sourceand target file names
    cin >> from >> to;
    // open input stream
    ifstream is{ from };
    // open output stream
    ofstream os{ to };
    //make input iterator for stream
    istream_iterator<string> ii{ is };
    // input sentinel
    istream_iterator<string> eos;
    // make output iterator for stream
    ostream_iterator<string> oo{ os,"\n" };
    // b is a vector initialized from input
    vector<string> b{ ii,eos };
    // sort the buffer
    sort(b.begin(), b.end());
    // copy buffer to outp
    copy(b.begin(), b.end(), oo);
    cout << "the good version is correct complited\n";
  }

  void bad_version()
  {
    string from, to;
    // get sourceand target file names
    cin >> from >> to;
    // open input stream
    ifstream is{ from };
    // open output stream
    ofstream os{ to };
    //make input iterator for stream
    istream_iterator<string> ii{ is };
    // input sentinel
    istream_iterator<string> eos;
    // make output iterator for stream
    ostream_iterator<string> oo{ os,"\n" };
    
    // don’t guess about the amount of input!
    size_t max_size = 5;
    vector<string> b{ max_size };
    copy(ii, eos, b.begin());
    
    // sort the buffer
    sort(b.begin(), b.end());

    // copy buffer to outp
    copy(b.begin(), b.end(), oo);
    cout << "the bad version is correct complited\n";
  }
}

int CH21P792TRYRunExmple::excute()
{
  good_version();
  bad_version();
	return 0;
}
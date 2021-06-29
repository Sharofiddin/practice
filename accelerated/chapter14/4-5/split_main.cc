#include <cctype>
#include <iostream>
#include "../Str.h"
#include "../Vec.h"

#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

#ifndef _MSC_VER
using std::isspace;
#endif

int main()
{
	Str s;

	// read and split each line of input
	while (getline(cin, s)) {
		Vec<Str> v = split(s);

		// write each word in `v'
#ifdef _MSC_VER
		for (std::Vec<string>::size_type i = 0; i != v.size(); ++i)
#else
		for (Vec<string>::size_type i = 0; i != v.size(); ++i)
#endif
			cout << v[i] << endl;
	}
	return 0;
}


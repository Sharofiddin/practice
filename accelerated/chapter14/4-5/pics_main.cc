#include <algorithm>
#include <iostream>
#include <iterator>
#include "Str.h"
#include "Vec.h"
#include <string>

#include "pics.h"

using std::cout;
using std::copy;
using std::endl;
using std::ostream_iterator;

int main()
{
	Vec<Str> p;
	p.push_back("this is an");
	p.push_back("example");
	p.push_back("to");
	p.push_back("illustrate");
	p.push_back("framing");

	ostream_iterator<Str>ofile(cout, "\n");
	copy(p.begin(), p.end(), ofile);
	cout << endl;

	Vec<Str> f = frame(p);
	copy(f.begin(), f.end(), ofile);	cout << endl;

	Vec<Str> h = hcat(frame(p), p);
	copy(h.begin(), h.end(), ofile);
	cout << endl;

	return 0;
}

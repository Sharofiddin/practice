#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "5-8.h" 

using std::cout;
using std::copy;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::vector;

int main()
{
	vector<string> p;
	p.push_back("this is an");
	p.push_back("example");
	p.push_back("to");
	p.push_back("illustrate");
	p.push_back("framing");

	ostream_iterator<string>ofile(cout, "\n");
	cout << endl;


	vector<string> h = hcat(p,frame(p));
	copy(h.begin(), h.end(), ofile);
	cout << endl;

	return 0;
}

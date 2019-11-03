#include <algorithm>
#include <string>
#include <vector>

#include "6-1.h"

using std::string;
using std::vector;

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
#ifdef _MSC_VER
	for(std::vector<string>::size_type i = 0; i != v.size(); ++i)
#else
	for(vector<string>::size_type i = 0; i != v.size(); ++i)
#endif
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	// write the top border
	ret.push_back(border);
	typedef vector<string>::const_iterator c_iter;
	// write each interior row, bordered by an asterisk and a space
	for (c_iter it = v.begin(); it != v.end(); ++it) {
		ret.push_back("* " + *it +
		              string(maxlen - it->size(), ' ') + " *");
	}

	// write the bottom border
	ret.push_back(border);
	return ret;
}

vector<string>
hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	typedef vector<string>::const_iterator c_iter;
	c_iter left_it = left.begin();
	c_iter right_it = right.begin();
	// continue until we've seen all rows from both pictures
	while (left_it != left.end() || right_it != right.end()) {
		// construct new `string' to hold characters from both pictures
		string s;

		// copy a row from the left-hand side, if there is one
		if (left_it != left.end())
			s = *(left_it++);

		// pad to full width
		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand side, if there is one
		if (right_it != right.end())
			s += *(right_it++);

		// add `s' to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}


#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include "split.h"
#include <iostream>

using std::cout;
using std::find_if;
using std::string;
using std::vector;
using std::list;

#ifndef _MSC_VER
using std::isspace;
#endif

// `true' if the argument is whitespace, `false' otherwise
bool space(char c)
{
	return isspace(c);
}

// `false' if the argument is whitespace, `true' otherwise
bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) {

		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in `[i,' `j)'
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

list<string> split_to_list( const string &line)
{
cout << "splitting line to list ...\n";
typedef string::const_iterator iter;
	list<string> ret;

	iter i = line.begin();
	while (i != line.end()) {

		// ignore leading blanks
		i = find_if(i, line.end(), not_space);

		// find end of next word
		iter j = find_if(i, line.end(), space);

		// copy the characters in `[i,' `j)'
		if (i != line.end())
			ret.push_back(string(i, j));
		i = j;	
}
cout << "line is splitted,\n list size " << ret.size() << '\n';
return ret;
}
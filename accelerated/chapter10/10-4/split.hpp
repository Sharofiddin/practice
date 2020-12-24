#include <algorithm>
#include <cctype>
#include <string>
#include "String_list.hpp"
#include <iostream>

using std::find_if;
using std::string;

#ifndef _MSC_VER
using std::isspace;
#endif

inline bool space(char c)
{
	return isspace(c);
}

inline bool not_space(char c)
{
	return !isspace(c);
}

String_list split(const string &str)
{ 
	String_list slist;
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end()){
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in `[i,' `j)'
		if (i != str.end()){
			slist.push_back(string(i, j));
		}

		i = j;
	}
	return slist;
}

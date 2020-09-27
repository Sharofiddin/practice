#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../chapter06/urls.h"

using std::cin;            using std::cout;
using std::endl;           using std::getline;
using std::istream;        using std::string;
using std::vector;         using std::map;


const int string_break_lim = 5;
// find all the lines that refer to each word in the input
map<string, vector<int>::iterator >
	xref(istream& in,
	     vector<string> find_words(const string&) = find_urls)
{
	string line;
	int line_number = 0;
	map<string, vector<int>::iterator > ret;

	// read the next line
	while (getline(in, line)) {
		++line_number;

		// break the input line into words
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line
#ifdef _MSC_VER
		for (std::vector<string>::const_iterator it = words.begin();
#else
		for (vector<string>::const_iterator it = words.begin();
#endif
		     it != words.end(); ++it)
			 if(find(ret[*it].begin(),ret[*it].end(),line_number) == ret[*it].end())//7-4
				ret[*it].push_back(line_number);
	}
	return ret;
}

int main()
{
	// call `xref' using `split' by default
	map<string, vector<int> > ret = xref(cin);

	// write the results
#ifdef _MSC_VER
	for (std::map<string, vector<int> >::const_iterator it = ret.begin();
#else
	for (map<string, vector<int> >::const_iterator it = ret.begin();
#endif
	     it != ret.end(); ++it) {
		cout << it->first;
		// write the word
		cout	<< " occurs on " 
				<< ((it->second.size() == 1 ) ? "line: " : "line(s): ") << endl;

		// followed by one or more line numbers
#ifdef _MSC_VER
		std::vector<int>::const_iterator line_it = it->second.begin();
#else
		vector<int>::const_iterator line_it = it->second.begin();
#endif
		cout << *line_it;	// write the first line number

		++line_it;
		int occ_count = 1;
		// write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			occ_count++;
			if( occ_count > string_break_lim ){
				cout << endl;
				cout << *line_it;
				occ_count = 1;	
			 } else {
				cout << ", " << *line_it;
			 }
			++line_it;
		}
		// write a new line to separate each word from the next
		cout << endl;
	}

	return 0;
}


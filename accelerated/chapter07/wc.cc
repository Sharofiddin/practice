#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::stringstream;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::istringstream;
using std::istream_iterator;
using std::back_inserter;
using std::copy;
using std::vector;
int main()
{
	map<string, int> words_table;
	vector<string> words;
	string line;
	while( getline(cin, line) ){
		istringstream iss(line);
  		copy(istream_iterator<string>(iss), 
                	istream_iterator<string>(),
                	back_inserter(words));
	}
	for( auto it = words.begin(); it != words.end(); it++ ){
			words_table[*it]++;
		}
	for( auto it = words_table.begin(); it != words_table.end(); it++ ){
		cout << it->first <<" "<<it->second <<"\n";
	}
	return 0;

}

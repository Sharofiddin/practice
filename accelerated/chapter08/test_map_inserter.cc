#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector> 
#include <utility>

using std::copy;
using std::map;
using std::cout;
using std::back_inserter;
using std::string;
using std::vector;
using std::pair;

int main()
{
	map<int , string> m ={{1,"s"}, {2,"a"}, {3,"l"}};
	vector<pair<int,string>> x = {{8,"sasasas"},{90,"asasasasa"}};
	copy(m.begin(), m.end(), back_inserter(x));
	for(vector<pair<int, string>>::const_iterator it = x.begin(); it != x.end(); it++){
		cout << it->first <<" " <<it->second <<  '\n';
	}
	/*copy(x.begin(), x.end(), back_inserter(m));
	for(map<int, string>::const_iterator it = m.begin(); it != m.end(); it++){
		cout << it->first <<" " <<it->second <<  '\n';
	} does not support push_back*/
	return 0;
}

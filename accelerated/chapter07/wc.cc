#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::sort;
using std::pair;

int main()
{
	string s;
	map<string, int> counters; // store each word and an associated counter
	map<int, vector<string>> wordsByFreq;

	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];
	// write the words and associated counts
#ifdef _MSC_VER
	for (std::map<string, int>::const_iterator it = counters.begin();
#else
	for (map<string, int>::const_iterator it = counters.begin();
#endif
	     it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}

	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++)
	{
		wordsByFreq[it->second].push_back(it->first);
	}

	for(map<int,vector<string>>::const_iterator it = wordsByFreq.begin(); it != wordsByFreq.end(); it++){
		cout << "freq " << it->first <<":\n";
		for(vector<string>::const_iterator iter = it->second.begin(); iter != it->second.end(); iter++){
			cout << *iter <<" ";
		}
		cout << endl;
	}
	
	return 0;
}


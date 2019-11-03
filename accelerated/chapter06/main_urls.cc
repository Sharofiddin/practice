#include <iostream>
#include <vector>
#include <string>
#include "urls.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string text;
	for (string word; getline(cin,word);){
		text += word;
	}

	vector<string> urls = find_urls(text);
	cout << "found " << urls.size() << " urls" << endl;
	for(vector<string>::const_iterator it = urls.begin();
			it != urls.end(); it++)
		cout << *it << endl;
	return 0;
}

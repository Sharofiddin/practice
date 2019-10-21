#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::equal;
using std::cin;
using std::cout;
using std::string;using std::vector;
using std::endl;
int main()
{
	vector<string> pals;
	string text;
	string::size_type maxlen = 0;
	while(cin >> text){
		if(equal(text.begin(),text.end(),text.rbegin())){
				if(text.size() > maxlen){
				maxlen = text.size();
				pals.insert(pals.begin(), text);} else {
				pals.push_back(text);
				}
				}
				}
				for( vector<string>::const_iterator it= pals.begin(); it != pals.end(); it++){
				cout <<*it << endl;}
				return 0;
				}
				


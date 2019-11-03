#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::equal;
using std::cin;
using std::cout;
using std::string;using std::list;
using std::endl;
int main()
{
	list<string> pals;
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
				for( list<string>::const_iterator it= pals.begin(); it != pals.end(); it++){
				cout <<*it << endl;}
				cout << "longest is: " << *pals.begin()<<endl;
				return 0;
				}
				


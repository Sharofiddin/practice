#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;
using std::string;
using std::vector;
using std::endl;
bool compare(const string& s1,const string& s2)
{
       	return s1 > s2; 
}
int main()
{
        list<string> strs;
	string str;
	while(cin>>str){
		strs.push_back(str);
	}
	sort(strs.begin(),strs.end(),compare);
	for(vector<string>::const_iterator it= strs.begin();it!= strs.end();it++)
		cout << *it << endl;
	return 0;}


	

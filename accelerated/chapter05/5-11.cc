#include <iostream>
#include <algorithm>
#include <list>
#include <algorithm>
#include <string>

using std::find;
using std::cin;
using std::cout;
using std::string;using std::list;
using std::endl;
bool is_as_or_desc( char c)
{
	const string asc_desc = "qypgjbdfhklt";
	return find(asc_desc.begin(), asc_desc.end(), c)!=asc_desc.end();
}
bool has_asc_or_desc(const string& word)
{
	typedef string::size_type str_sz;
	str_sz size = word.size();
	for(str_sz i=0;i!=size;i++){
		if(is_as_or_desc(word[i]))
				return true;
			}
		return false;
		}

int main()
{
	list<string> cleans;
	string text;
	string::size_type maxlen = 0;
	while(cin >> text){if(!has_asc_or_desc(text)){
			cleans.push_back(text);
				}
				}
				
				for( list<string>::const_iterator it= cleans.begin(); it != cleans.end(); it++){
				cout <<*it << endl;}
				return 0;
				}
				


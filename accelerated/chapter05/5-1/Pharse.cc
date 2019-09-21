#include <string>
#include <vector>
#include "Pharse.h"
#include <iomanip>
#include <cctype>
using std::vector;	using std::string;
using std::cout;	using std::setw;
using std::endl;	using std::tolower;
typedef vector<string>::size_type vec_sz;

string low_case(const string &str)
{
	typedef string::size_type str_sz;
	string ret;
	str_sz size = str.size();
	for( str_sz i = 0; i != size; i++)
		ret.push_back(tolower(str[i]));
	return ret;
}

string join_words(const vector<string> &words)
{
	string ret;
	vec_sz size = words.size();
	for( vec_sz i = 0; i < size; i++ ){
		ret.append(words[i]);
	}
	return ret;
}


bool compare( const Pharse& p1, const Pharse& p2 )
{
	return low_case(join_words(p1.words)) <  low_case(join_words(p2.words));
}



void printPharse( const Pharse& pharse, string::size_type width)
{
	string leftPart = "";
	vec_sz size = pharse.words.size();
	for( vec_sz i = pharse.separator+1; i < size; i++)
		leftPart +=pharse.words[i] + " ";
	cout << setw(width) << leftPart;
	cout << "    ";
	for(vec_sz i = 0; i <= pharse.separator; i++)
		cout << pharse.words[i] + " ";
	cout << endl;
}

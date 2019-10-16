#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using std::cin;		using std::cout;
using std::string; 	using std::vector;
using std::isspace;	using std::find_if;
using std::max;		using std::endl;
bool space( char c )
{
	return isspace(c);
}

bool not_space( char c )
{
	return !isspace(c);
}
vector<string> split(const string& text)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = text.begin();
	iter e = text.end();
	while( b != e ){
		b = find_if( b, e, not_space);
		iter word_end  = find_if(b, e , space);
		if( b != word_end)
			ret.push_back(string(b, word_end));
		b= word_end;
				
	}

	return ret;
}

string center( string& word, string::size_type pad )
{
	typedef string::size_type str_sz;
	str_sz r_pad = (pad - word.size())/2;
	str_sz l_pad = pad-word.size()-r_pad;
	word = string('*'+ string(l_pad, ' ') + word + string(r_pad, ' ')+'*');
	return word;
}
vector<string> center(const string& text)
{
	vector<string> words = split(text);
	typedef vector<string>::iterator iter;
	typedef string::size_type str_sz;
	str_sz maxlen = 0;
	for(iter it = words.begin(); it != words.end(); ++it)
		maxlen = max( maxlen, (*it).size());

	string bot_top_frame = string(maxlen + 2, '*');
	for(iter it = words.begin(); it != words.end(); ++it)
		*it = center(*it, maxlen);
	words.push_back(bot_top_frame);
	words.insert(words.begin(), bot_top_frame);
	return words;
}
int main()
{
	string text;
	getline(cin, text);
	cout << text << endl;
	vector<string> centered_framed_words = center(text);
	typedef vector<string>::const_iterator iter;
	for(iter it = centered_framed_words.begin(); it != centered_framed_words.end(); ++it){
		cout << *it <<endl;
	}
	return 0;
}


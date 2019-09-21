#include "util.h"
#include <algorithm>
#include <iostream>
#include "../split.h"
using std::vector; 	using std::string;
using std::cout; 	using std::endl;
using std::rotate;	
typedef vector<string>::size_type vec_sz;
typedef string::size_type str_s;
vector<Pharse> get_pharses( const string &s)
{
	vector<string> splitted = split(s);
	vec_sz size = splitted.size();
	vector<Pharse> pharses;
	Pharse pharse;
	pharse.words = splitted;
	pharse.separator = size - 1;
	pharses.push_back(pharse);
	for ( vec_sz i = 1; i < size; i++ ){
		pharse.separator = size - 1 -i;
		pharse.words = rotate(splitted);
		pharses.push_back(pharse);
	}

	return pharses;
}

vector<string> rotate(vector<string> &vec)
{
	vec_sz size = vec.size();
	string first = vec[0];
	for( vec_sz i = 0; i < size -1; i++ ){
		vec[i] = vec[i+1];
	}	

	vec[size -1] = first;
	return vec;
}

str_s left_part_length(const vector<string> &words)
{
	str_s ret = 0;
	vec_sz size = words.size();
	for( vec_sz i = 0; i < size - 1; i++)
		ret += words[i].size() + 1;
	
	return ret;
}

#include "util.h"

#include <iostream>
#include "../split.h"
using std::vector; 	using std::string;
using std::cout; 	using std::endl;
typedef vector<string>::size_type vec_sz;

vector<Pharse> get_pharses( const string &s)
{
	vector<string> splitted = split(s);
	string separator = *(splitted.end());
	vector<Pharse> pharses;
	/*vec_sz size = splitted.size();
	
	for ( vec_sz i = 0; i < size; i++ ){
		Pharse pharse;
		pharse.separator = separator;
		pharse.words = rotate(splitted);
	}*/

	return pharses;
}

vector<string> rotate(vector<string> &vec)
{
	vec_sz size = vec.size();
	string last = vec[size - 1];
	for( vec_sz i = size -1; i > 0; i-- ){
		vec[i] = vec[i-1];
	}	

	vec[0] = last;
	return vec;
}
				

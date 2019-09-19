#include "util.h"
#include "../split.h"
using std::vector; 	using std::string;

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
	for( vec_sz i = 0; i < size; size+=2 ){
		string temp;
		if(i > 0){
			temp = vec[i];
			vec[i] = vec[i-1];
			vec[i-1] = temp;
		} else {
			temp = vec[size - 1];
			vec[size-1] = vec[i];
			vec[i] = temp;
		}
	}

	return vec;
}
				

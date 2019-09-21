#include "util.h"
#include <iostream>
#include <algorithm>
using std::cout;	using std::cin;
using std::sort;	using std::vector;
using std::string;	using std::endl;
using std::max;

typedef vector<Pharse>::size_type vec_sz; 
typedef string::size_type str_s;
int main()
{
	string str;
	vector<Pharse> pharses;
	cout << "Enter words: " << endl;
	str_s max_width = 0;
	while(getline(cin, str)){
	if( str == "")
		break;
	vector<Pharse> temp = get_pharses(str);
	max_width = max(max_width, left_part_length(temp[0].words));
	pharses.insert(pharses.end(), temp.begin(), temp.end());
	}
	vec_sz size = pharses.size();
	sort(pharses.begin(), pharses.end(), compare);

	for( vec_sz i = 0; i < size; i++ ){
		
		printPharse(pharses[i], max_width);
	}

}

#include "util.h"
#include <iostream>

using std::cout;	using std::cin;
using std::string;	using std::vector;
typedef string::size_type str_s;

int main()
{
	vector<string> vec;
	vec.push_back("salom");
	vec.push_back("qalay");
	cout <<"size: "<< left_part_length(vec);
	return 0;
}


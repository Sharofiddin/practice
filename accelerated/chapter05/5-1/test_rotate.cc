#include <iostream>
#include <vector>
#include <string>
#include "util.h"

using std::cout;  	using std::cin;
using std::string; 	using std::endl;
using std::vector;
typedef vector<string>::size_type vec_sz;

void print_vec(const vector<string> &vec)
{
	vec_sz size = vec.size();
	for( vec_sz i = 0 ; i != size; i++ )
		cout << vec[i] << " ";
	cout << endl;	
}	

int main()
{
	vector<string> str;
	str.push_back("salom");
	str.push_back("qalay");
	str.push_back("do'stim");

	vec_sz size = str.size();
	for( vec_sz i = 0; i != size; i++)
	{
		print_vec(rotate(str));
	}
	return 0;
}


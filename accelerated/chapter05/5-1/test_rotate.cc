#include <iostream>
#include <vector>
#include <string>
#include "util.h"
#include "../split.h"
#include <algorithm>
using std::cout;  	using std::cin;
using std::string; 	using std::endl;
using std::vector;	using std::sort;
typedef vector<string>::size_type vec_sz;
typedef vector<Pharse>::size_type ph_vec_sz;
void print_vec(const vector<string> &vec)
{
	vec_sz size = vec.size();
	for( vec_sz i = 0 ; i != size; i++ )
		cout << vec[i] << " ";
	cout << endl;	
}	

int main()
{
	string str;
        cout << "Enter words: ";
        getline(cin, str);
        cout << "Words are read: " << str << endl;
        vector<Pharse> pharses = get_pharses(str);
        ph_vec_sz size = pharses.size();
        cout << size  << " Pharses are generated." << endl;
        sort(pharses.begin(), pharses.end(), compare);
	 for( ph_vec_sz i = 0; i < size; i++ ){
		 print_vec(pharses[i].words);
	 }
	return 0;
}


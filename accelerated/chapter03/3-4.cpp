#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin;		using std::string;
using std::cout;	using std::sort;
using std::vector;
using std::endl;

int main()
{
	vector<int> sizes;
	cout << "Enter words: ";
	string str;
	while (cin >> str){
		sizes.push_back(str.size());
	}
	cout << endl;
	typedef vector<int>::size_type vec_sz;

	vec_sz size = sizes.size();
	if( size == 0)
	{
		cout << "Please, enter some words."<<endl;
		return 1;
	}

	sort(sizes.begin(), sizes.end());
	cout << "longest word length is: " << sizes[size - 1] << endl <<"shortest word length is: " << sizes[0] << endl;
	return 0;
}		

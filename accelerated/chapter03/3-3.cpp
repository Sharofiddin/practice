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
	vector<string> words;
	cout << "Enter words: ";
	string str;
	while (cin >> str){
		words.push_back(str);
	}
	cout << endl;
	typedef vector<string>::size_type vec_sz;

	vec_sz size = words.size();
	if( size == 0)
	{
		cout << "Please, enter some words."<<endl;
		return 1;
	}

	sort(words.begin(), words.end());
	int count = 1;
	for( int i = 0; i < size; i++ ){
		if( i > 0 && words[i] == words[i-1]){
			count++;
		} else if( i != 0 ){
			cout << "count of " << words[i-1] << " = " << count << endl;
			count = 1;
		}
	}

	cout << "count of " << words[size -1] << " = " << count << endl;
	return 0;
}		

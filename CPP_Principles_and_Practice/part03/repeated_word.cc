#include "../std_lib_facilities.h"

int main()
{
	string current;
	string pervious =" ";
	int count_of_words = 0;
	while( cin >> current ){
		count_of_words++;
		if( current == pervious )
			cout << "number of word: " << count_of_words << " repeated : " << current << '\n';
		 pervious = current;
	}
	return 0;
}

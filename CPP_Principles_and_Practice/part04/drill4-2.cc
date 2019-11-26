#include "../std_lib_facilities.h" 

int main()
{
	char c;
	int a;
	int b;
	while( cin >>a && cin >> b){
		if( a == b )
			cout << "the numbers are equal\n";
		else if( a > b)
			cout << "the smaller value is " << b << "\nthe larger value is " << a;
		else cout << "the smaller value is " << a << "\nthe larger value is " << b;
			
	}

	return 0;
}


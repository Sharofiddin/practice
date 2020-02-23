#include "../std_lib_facilities.h" 

int main()
{
	double a;
	double b;
	while( cin >>a && cin >> b){
		if( abs(a - b) < (1.0/100) )
			cout << "the numbers are almost equal\n";
		else
			cout << "the smaller value is " << min(a,b) << "\nthe larger value is " << max(a,b);
			
	}

	return 0;
}


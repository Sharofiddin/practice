
#include "../std_lib_facilities.h"

const double epsilon = 0.01;
int main()
{
    double a; 
    double b;
    while( cin >> a && cin >> b){
        if(a == b){
            cout << "Numbers are equal\n";
            continue;
        } else if( a > b ){
            cout << "the smaller value is " << b << ", the larger values is " << a <<endl;
        } else{
            cout << "the smaller value is " << a << ", the larger values is " << b <<endl;
        }

        if( abs(a- b) < epsilon ){
            cout << "the numbers are almost equal\n";
        }
    }

    return 0;
}
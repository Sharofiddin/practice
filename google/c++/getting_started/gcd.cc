#include <iostream>

using namespace std;
void swap( int& num1, int& num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
}
int gcd( int num1 , int num2){
    while( (num1 % num2) != 0){
        num1 %= num2;
        swap(num1, num2);
    }  
    return num2;  
}

int main()
{
    cout << "gcd( 10, 12) = " << gcd( 10, 12) << endl;
    cout << "gcd(-16, 8) = "<< gcd(-16, 8) << endl;
    cout << "gcd(4,4) = " << gcd(4,4) << endl;
}
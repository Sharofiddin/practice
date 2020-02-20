#include "../std_lib_facilities.h"

int main()
{   
    double smallest = numeric_limits<double>::max();
    double largest = numeric_limits<double>::lowest();

    for( double x; cin >> x;){
        cout << "Enetered "<< x << endl;
        if(x < smallest){
            smallest = x;
            cout << "the smallest so far\n";
        }

        if( x > largest ){
            largest = x;
            cout << "the largest so far\n";
        }

    }

    return 0;
}
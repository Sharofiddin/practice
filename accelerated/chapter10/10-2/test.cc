#include "median.h"
#include <iostream>

using std::cout;
int main()
{
    int int_arr[] = {45,1,2,45,80};
    double db_arr[]= {1.1, 2.2, 3.6, 7.8};
    vector<int> int_vec = {1,2,3,4,5,6,7};
    vector<double> db_vec = {11.6,2.5,33,14.3,5,6,7};
    cout << median(int_arr,5) << '\n';
    cout <<median(db_arr,5) << '\n';
    cout <<median(&int_vec[0],5) << '\n';
    cout <<median(&db_vec[0],5) << '\n';
    return 0;
}
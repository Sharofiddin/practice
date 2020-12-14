#include "median.h"
#include <iostream>

using std::cout;
template <class T>
void print(T p, size_t size)
{
    for(size_t i = 0; i < size; i++)
        cout << *(p +i) << '\t';
    cout << '\n';
}
int main()
{
    int int_arr[] = {45,1,2,45,80};
    double db_arr[]= {1.1, 12.2, 3.6, 7.8};
    vector<int> int_vec = {1,22,3,4,15,6,7};
    vector<double> db_vec = {11.6,2.5,33,14.3,5,6,7};
    cout << "before ";
    print(int_arr,5);
    cout << median(int_arr,int_arr+5, int_arr[0]) << '\n';
    cout << "after ";
    print(int_arr,5);
    cout << "before ";
    print(db_arr,5);
    cout <<median(db_arr,db_arr+5, db_arr[0]) << '\n';
    cout << "after ";
    print(db_arr,5);
    cout << "before ";
    print(&int_vec[0],5);
    cout << median(int_vec.begin(), int_vec.end(), int_vec[0]) << '\n';
    cout << "after ";
    print(&int_vec[0],5);
    cout << "before ";
    print(&db_vec[0],5);
    cout <<median(db_vec.begin(),db_vec.end(), db_vec[0]) << '\n';
    cout << "after ";
    print(&db_vec[0],5);
 
    return 0;
}
#include "Vec.h"
#include <iostream>
void print(int i)
{
    std::cout << i << " ";
}
int main()
{
    int arr[] = {1,2,6};

    Vec<int> v;
    v.assign(arr, arr+3);
    std::for_each(v.begin(), v.end(), print);
    return 0;

}

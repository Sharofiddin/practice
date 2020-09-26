#include "stl_algs.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    reverse_v(vec.begin(),vec.end() );
    {
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    }
    return 0;
}
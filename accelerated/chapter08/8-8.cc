#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <class Ran , class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin != end )
    {
        /* Ran mid = (begin + end)/2
        is error, because iterator + iterator is not defined
        Ran mid = begin + (end -  begin)/2; is correct, ebacuse end - begin returns int, iterator + int is acceptable
        */
        Ran mid = begin + (end -  begin)/2;
        if(x < *mid)
            end = mid - 1;
        else if( x > *mid )
            begin = mid + 1;
        else 
            return true;
    }

    return false;
}

int main()
{
    vector<int> nums = {1,11,21,51,101};
    cout << binary_search(nums.begin(), nums.end(), 21);
    return 0;
}
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
    //12-12
    v.assign(arr, arr+3);
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;
    //12-13
    v.insert(v.begin()+1, v.begin(), v.end());
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;
    std::string s = "salom qalaysan";
    //12-14
    Vec<char> str_inited(s.begin(), s.end());
    for(auto it = str_inited.begin(); it != str_inited.end(); it++)
    {
        std::cout << *it; 
    }
    std::cout << std::endl;

    return 0;

}

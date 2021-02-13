#include "List.hpp"
#include <iostream>
#include <algorithm>
bool is_odd(int i)
{
    return i % 2;
}
int main()
{
    List<int> l;
    l.push_back(10);
    l.push_back(50);
    l.push_back(51);
    l.push_back(80);
    for(List<int>::iterator it = l.begin(); it != l.end(); it++){
        std::cout << *it << std::endl;
    }
    List<int>::iterator odd = std::find_if(l.begin(), l.end(), is_odd);
    std::cout << *odd; 
    return 0;
}
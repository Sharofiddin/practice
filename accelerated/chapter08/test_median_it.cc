#include "median.h"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(8);

    
    std::cout << median(vec.begin(), vec.end(), vec.size());
    return 0;
}

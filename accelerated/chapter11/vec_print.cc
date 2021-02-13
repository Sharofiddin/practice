#include "Vec.h"
#include <iostream>
#include <algorithm>
bool is_odd(int x){
    return x%2;
}
int main()
{
    Vec<int> values;
    values.push_back(11);
    values.push_back(100);
    for (Vec<int>::iterator it = values.begin(); it != values.end();it++){
        std::cout <<*it << std::endl;
    }
    Vec<int>::const_iterator it = std::find_if(values.begin(), values.end(), is_odd);
    std::cout << *it;
    return 0;
}
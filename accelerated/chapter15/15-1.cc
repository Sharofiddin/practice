#include "Pic.h"
#include <iostream>

int main()
{
    std::vector<std::string> v;
    while(std::cin)
    {
        std::string temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    Picture p = v;
    Picture q = frame(p);
    Picture r = hcat(p,q);
    Picture s = vcat(q,r);
    std::cout << frame(hcat(s, vcat(r,q)));
    return 0;
}
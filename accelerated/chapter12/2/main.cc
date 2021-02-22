#include "Str.h"
#include <iostream>

int main()
{
    Str str(10,'n');
    std::cout << str << std::endl;
    Str str2 = "1qazxsw2";
    std::cout << str2 << std::endl;
    Str str3 = str2;
    std::cout << str3 << std::endl;
    return 0;
}
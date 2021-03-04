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
    char c[5];
    Str::size_type copied = str2.copy(c,4,0);
    c[4] = '\0';
    std::cout <<"Copied " << copied << " " << c << std::endl;
    copied = str2.copy(c,4,10);
    std::cout <<"Copied " << copied << " " << c << std::endl;
    char c2[25];
    copied = str2.copy(c2,24,0);
    c2[copied] = '\0';
    std::cout <<"Copied " << copied << " " << c2 << std::endl;
    return 0;
}
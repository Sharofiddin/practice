#include "Str.h"
#include <iostream>
#include <algorithm>
#include <vector>
void println(const Str& s){
    std::cout << s << std::endl;
}
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
    std::vector<Str> arr;
    arr.push_back("abc");
    arr.push_back("ghi");
    arr.push_back("def");
    std::cout << "before sorting .. " << std::endl;
    std::for_each(arr.begin(), arr.end(), println);
    std::sort(arr.begin(),arr.end());
    std::cout << "after sorting .. " << std::endl;
    std::for_each(arr.begin(), arr.end(), println);
    std::cout <<str2 << " == " << str3 << " is " << (str2 == str3) << std::endl; 
    std::cout <<str2 << " != " << str3 << " is " << (str2 != str3) << std::endl; 
    std::cout <<str2 << " >= " << str3 << " is " << (str2 >= str3) << std::endl; 
    std::cout <<str2 << " <= " << str3 << " is " << (str2 <= str3) << std::endl; 
    std::cout <<str2 << " > " << str3 << " is " << (str2 > str3) << std::endl; 
    std::cout <<str2 << " < " << str3 << " is " << (str2 < str3) << std::endl; 
    std::cout <<str << " > " << str2 << " is " << (str > str2) << std::endl; 
    std::cout <<str << " < " << str2 << " is " << (str < str2) << std::endl; 
    std::cout <<str << " == " << str2 << " is " << (str == str2) << std::endl; 
    std::cout <<str << " != " << str2 << " is " << (str != str2) << std::endl; 
    std::cout << str << " + " << str2 << " = " << str + str2 << std::endl;
    std::cout << str2.append(str) << " " << str2 << std::endl;
    str2+=str;
    std::cout << str2 <<  " " << str2.size() << std::endl;

    std::cout << str.append("salom").append("a").append(str2) << std::endl;
    std::cout << str << std::endl;
    std::cout << "str.empty() = " << str.empty() << std::endl;
    str = "";
    std::cout << "str.empty() = " << str.empty() << std::endl;
    if(str){
        std::cout << "str is true\n";
    } else {
        std::cout << "str is false\n";
    }
    str.append("salom");
    str ? std::cout << "str is true\n" : std::cout << "str is false\n";
    std::cin >> str;
    std::cout << str << std::endl;
    return 0;
}
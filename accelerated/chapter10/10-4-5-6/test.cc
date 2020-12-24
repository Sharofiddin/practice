#include "String_list.hpp"
#include <iostream>
#include "split.hpp"
using std::cout;
int main()
{
    std::string str;
    getline(std::cin, str);
    String_list s = split(str);
    for (String_list::iterator it = s.begin(); it != s.end(); it = it->next){
       cout << it->val << '\n';
    }
    
    return 0;
}
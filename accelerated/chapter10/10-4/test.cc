#include "String_list.hpp"
#include <iostream>

using std::cout;
int main()
{
    String_list *s = new String_list;
    s->push_back("salom");
    s->push_back("qalay");
    s->push_back("bo'loptimi");
    s->print();
    return 0;
}
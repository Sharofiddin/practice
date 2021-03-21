/**
* If self-assigment removed from Student_info copy constructor,
* then firstly cp pointer is uninitialized, after that takes this uninitialized pointer
* Finally we got dumped core ))
*/

#include "Student_info.h"

int main()
{
    Student_info s;
    s.read(std::cin);
    s = s;
    std::cout << s.name();
    return 0;
}
//if compiled by -> make CPPFLAGS='-DEX_13_9'  13-9 
//Segmentation fault (core dumped)

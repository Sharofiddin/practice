#include "Student_info.h"

int main()
{
    Student_info s;
    s.read(std::cin);
    s = s;
    std::cout << s.name();
    return 0;
}
#include "Student_info.h"
#include <iostream>
#include <stdexcept>

using std::domain_error;
using std::cin;
using std::cout;
int main()
{
    Student_info student;
    student.read(cin);
    if(!student.valid()){
        std::cerr <<"Invalid student info\n";
        return 1;
    }
    cout <<"Total grade is: " << student.grade() << std::endl;
    return 0;
        
}
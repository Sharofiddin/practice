#include "Student_info.h"
#include <iostream>
#include <stdexcept>

using std::domain_error;
using std::cin;
using std::cout;
int main()
{
    Student_info student;
    try{
        student.read(cin);
        student.valid();
        cout << student.grade();
    } catch(domain_error){
        std::cerr <<"Invalid student info\n";
    }
    return 0;
        
}
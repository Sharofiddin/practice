#include "../Student_info.h"
#include "grade.h"
#include "List.hpp"
#include <iostream>

bool failed(const Student_info& s){
    return grade(s) < 60;
    }
int main()
{
    List<Student_info> students;
    Student_info student;
    while(read(std::cin, student)){
        students.push_back(student);
    }
    List<Student_info>::iterator pos = std::remove_if(students.begin(), students.end(), failed);
    students.erase(pos, students.end());
    for(List<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
            std::cout << it->name << " " << grade(*it) << std::endl;
    } 
    return 0;
}
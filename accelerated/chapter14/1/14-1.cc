#include "../Ptr.h"
#include <iomanip>
#include "../Core.h"
#include <iostream>
#include <vector>
#include <algorithm>
bool compare_ptr(Ptr<Core> &p1, Ptr<Core> &p2){
    return p1->name() > p2->name();
}
int main()
{
 std::vector<Ptr<Core>> students;
 Ptr<Core> student;
 std::string::size_type max_len = 0;
 char type;
 while(std::cin >> type){
     student = type == 'U'? new Core : new Grad;
     student->read(std::cin);
     max_len = std::max(student->name().size(), max_len);
     students.push_back(student);
 }

 std::sort(students.begin(), students.end(), compare_ptr);
 for(std::vector<Ptr<Core>>::const_iterator it= students.begin(); it != students.end(); it++){
     std::cout << (*it)->name() << std::string(max_len + 1 - (*it)->name().size(), ' ') << "| ";
     try{
         std::streamsize stsize = std::cout.precision();
         double final = (*it)->grade();
         std::cout << std::setprecision(3) << final << std::setprecision(stsize) << std::endl;
     } catch(const std::domain_error &de){
         std::clog << de.what() << std::endl; 
     }
 }
 return 0;
}
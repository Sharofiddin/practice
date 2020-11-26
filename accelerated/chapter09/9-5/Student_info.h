#ifndef STUDENT_INFO_9_5_GUARD
#define STUDENT_INFO_9_5_GUARD
#include <iostream>
class Student_info{
    public:
     Student_info();
     ~Student_info();
     std::string get_name() const;
     std::istream& read(std::istream &in);
     std::string grade() const;

    private:
    double midterm;
    double final_grade;
    std::string name;
};
     bool compare(const Student_info&, const Student_info&);
#endif
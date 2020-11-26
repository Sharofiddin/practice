#include "Student_info.h"
using std::istream;
using std::string;
Student_info::Student_info(){}
Student_info::~Student_info(){}
istream& Student_info::read(istream &in)
{
    in >> name >> midterm >> final_grade;
    return in;
}

string Student_info::get_name() const
{
    return name;
}

std::string Student_info::grade() const
{
    return (midterm + final_grade) / 2 > 60 ? "P":"F";
}

bool compare(const Student_info& s1,const Student_info& s2)
{
  return  s1.get_name() < s2.get_name();
}
#include "Student_info.h"
#include <algorithm>
#include <iostream>
#include "grade.h"

using std::cout;
using std::vector; using std::stable_partition;

vector<Student_info> extract_by_creteria(vector<Student_info>& students, bool creteria(const Student_info&))
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), creteria);
    vector<Student_info> extracted(iter, students.end());
    students.erase(iter, students.end());
    return extracted;
}


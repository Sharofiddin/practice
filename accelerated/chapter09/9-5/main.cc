#include "Student_info.h"
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;
using std::cin;
using std::cout;

int main()
{
    vector<Student_info> students;
    while(true){
        Student_info student;
        student.read(cin);
        if(cin)
            students.push_back(student);
        else 
            break;
    }
    sort(students.begin(), students.end(), compare);
    for(vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
        cout << it->get_name() << " | " << it->grade() << std::endl;
    }

    return 0;
}
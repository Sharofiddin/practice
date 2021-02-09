#include "Student_info.h"
#include <vector>
#include <algorithm>
#include <list>

using std::list;
using std::sort;
using std::string;
using std::max;
using std::vector;
using std::cin;
using std::cout;
int main()
{
    vector<Student_info> students;
    Student_info student;
    while(student.read(cin)){
        students.push_back(student);
        //cout << student.name() << " | " << student.grade() << std::endl;
    }
   // cout <<"count " << students.size() << '\n';
    //sort(students.begin(), students.end(), compare);
    // for(vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
    //     cout << it->name() << " | " << it->grade() << std::endl;
    // }
    cout    <<  "Created : "    <<Student_info::created 
            <<  "\nCopied : "   << Student_info::copied
            <<  "\nAssigned : " << Student_info::assigned
            <<  "\nDestroyed : " << Student_info::destroyed << '\n';
    return 0;

}

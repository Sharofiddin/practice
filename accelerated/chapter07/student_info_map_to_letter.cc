#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"
using std::cin; using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::domain_error;
int main()
{
    map<char,vector<Student_info>> students;
    for(Student_info student; read( cin , student);){
        double gr = grade(student);
        if(gr <= 100 && gr >= 90 ){
            students['A'].push_back(student);
        } else if( gr < 90 && gr >= 80){
            students['B'].push_back(student);
        } else if( gr < 80 && gr >= 70){
            students['C'].push_back(student);
        } else if( gr < 70 && gr >= 60){
            students['D'].push_back(student);
        } else if( gr < 60 && gr >= 0){
            students['F'].push_back(student);
        } else {
            throw domain_error("Grade of student must be in [0,100] interval");
        }
    } 

    for(map<char, vector<Student_info>>::const_iterator iter = students.begin(); iter != students.end(); iter++){
        cout << iter->first <<" category students: " << endl;
        for(vector<Student_info>::const_iterator it = iter->second.begin(); it != iter->second.end(); it++){
            cout <<"\t" << it->name <<" "<<grade(*it) << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include "analysis.h"

using std::cin;
using std::cout;
using std::vector;
using std::stable_partition;

vector<Student_info> extract_didnt(vector<Student_info>& students){
    vector<Student_info>::iterator iter= stable_partition(students.begin(), students.end(), did_all_hw);
    vector<Student_info> didnt(iter, students.end());
    students.erase(iter, students.end());
    return didnt;
}

int main()
{
    vector <Student_info> students;
    for(Student_info student; read(cin, student);){
        students.push_back(student);
    }

    vector<Student_info> didnt = extract_didnt(students);
    cout << "did:\n";
    for(vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
        cout <<"\t"<< it->name << "\n";
    }
    cout << "didn't:\n";
    for(vector<Student_info>::const_iterator it = didnt.begin(); it != didnt.end(); it++){
        cout << "\t" << it->name <<"\n";
    }

}
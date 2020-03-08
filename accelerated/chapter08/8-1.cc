#include "analysis.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include "Student_info.h"
#include <iostream>
#include "median.h"

using std::cin;
using std::cout;
using std::ostream;
using std::transform;
using std::back_inserter;
using std::vector;
using std::endl;

template <class T>
double template_analysis( const vector<Student_info> &students, T analysis)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
	          back_inserter(grades), analysis);
	return median(grades);
}

void write_analysis(
    ostream& out, 
    const vector<Student_info>& did, const vector<Student_info>& didnt
 ){
     out << "avarage" << " median(did) = " << template_analysis(did, average_grade) 
                << ", median(didnt)" << template_analysis(didnt,average_grade) 
                << endl;
	out << "median" << " median(did) = " << template_analysis(did, grade_aux) 
                << ", median(didnt)" << template_analysis(didnt, grade_aux) 
                << endl;
	out << "optimistic median" << " median(did) = " << template_analysis(did, optimistic_median) 
                << ", median(didnt)" << template_analysis(didnt,optimistic_median) 
                << endl;
 }

int main(int argc, char const *argv[])
{
    vector<Student_info> did;
    vector<Student_info> didnt;
    
    for( Student_info student; read(cin, student);){
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if(did.empty()){
        cout <<"No student did all homework!\n";
        return 1;
    } 
    if(didnt.empty()){
        cout << "Every student did all homework\n";
        return 1;
    }

    write_analysis(cout, did, didnt);

    return 0;
}

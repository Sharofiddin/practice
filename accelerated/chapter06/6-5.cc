#include <iostream>
#include "analysis.h"

using std::cin;
using std::vector;
using std::cout;
using std::endl;
int main()
{
    vector<Student_info> did;
    vector<Student_info> did_not;
    Student_info student;
    while(read(cin, student)){
        if(did_all_hw(student)){
            did.push_back(student);
        }
        else
        {
            did_not.push_back(student);
        }
    }
        if(did.empty())
        {
            cout << "No student did all homework!";
            return 1;
        } 
        
        if(did_not.empty()){
            cout << "Every student did all homework!";
            return 1;
        }
        
        write_analysis(cout, "optimistic_median_analysis", optimistic_median_analysis, did, did_not );

}
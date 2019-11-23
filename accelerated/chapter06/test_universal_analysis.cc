//universal analysis implemented inside of analysis.h
#include "analysis.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;

int main()
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

    universal_write_analysis(cout, did, didnt);

}
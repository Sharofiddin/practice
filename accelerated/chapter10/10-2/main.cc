/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description: accelerated cpp ch10 exercise 02 
 *
 *        Version:  1.0
 *        Created:  11/30/2020 11:54:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sharofiddin Pardayev (p.sh.t), pardayev.sharofddin@gmail.com
 *        Company:  BIS, Tashkent
 *
 * =====================================================================================
 */

#include "Student_info.h"
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::string;
int main()
{
	vector<Student_info> students;
	Student_info student;
	unsigned int max_name_len = 0;
	while(student.read(cin)){
		if(max_name_len < student.name().size())
			max_name_len = student.name().size();
		students.push_back(student);
	}

	for(vector<Student_info>::const_iterator it = students.begin(); it!= students.end(); it++){
		cout <<it->name() <<string(max_name_len - it->name().size(), ' ') << " | " << it->letter_grade() << '\n';
	}
	return 0;
}

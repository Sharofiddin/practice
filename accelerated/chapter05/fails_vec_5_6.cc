#include <vector>
#include "Student_info.h"
#include "grade.h"
#include <iostream>

using std::cout; using std::endl;
using std::vector;

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info>::size_type initial_size = students.size();
	vector<Student_info>::iterator it = students.begin();
	vector<Student_info>::iterator end = students.end();
	vector<Student_info> fails;
	while (it <  students.end()) {
		if (!fgrade(*it)) {
			students.insert(students.begin(),*it);
			it++;
	} else {
		fails.push_back(*it);
	}
		it++;
	}
	students.resize(initial_size-fails.size());
	return fails;
}


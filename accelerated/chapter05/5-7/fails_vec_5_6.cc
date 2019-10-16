#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

// second try: correct but potentially slow
vector<Student_info> extract_fails(vector<Student_info>& students)
{
#ifdef _MSC_VER
	std::vector<Student_info>::size_type i = 0;
#else
	vector<Student_info>::size_type i = 0;
#endif

	// invariant: elements `[0,' `i)' of `students' represent passing grades
	vector<Student_info>::size_type initial_size = students.size();
	while (i != initial_size) {
		if (grade(students[i])>60.0) {
			students.insert(students.begin(),students[i]);
		
	}
			++i;}
	students.resize(initial_size);
	return students;
}


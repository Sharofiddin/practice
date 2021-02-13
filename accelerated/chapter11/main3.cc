#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <stdexcept>
#include <string>
#include "Vec.h"
#include "grade.h"
#include "Student_info.h"
#include <chrono>
using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;
using std::chrono::steady_clock; 	using std::string;
#ifndef _MSC_VER
using std::max;
#else


#include "../minmax.h"
#endif

long long  test(bool doubled)
{
	long long res = 0;
	Vec<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name

	// read and store all the students' data.
	// Invariant:	`students' contains all the student records read so far
	//			`maxlen' contains the length of the longest name in `students'
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record,doubled);
		res++;
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
#ifdef _MSC_VER
	for (Vec<Student_info>::size_type i = 0;
#else
	for (Vec<Student_info>::size_type i = 0;
#endif
	     i != students.size(); ++i) {

		// write the name, padded on the right to `maxlen' `+' `1' characters
		cout << students[i].name
		     << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return res;
}

int main()
{
	bool doubled;
	cin >> doubled;
	steady_clock::time_point begin = std::chrono::steady_clock::now();
  	long long pushes = test(doubled);
  	steady_clock::time_point end = std::chrono::steady_clock::now();
  	std::cout << "Microseconds to add " << pushes << " to vector " <<((!doubled) ? " without ":"") 
	  << "using double memory method = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "microseconds" << endl;
	
}


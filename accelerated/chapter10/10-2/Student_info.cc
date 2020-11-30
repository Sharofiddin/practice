#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"
#include <stdexcept>

using std::domain_error;
using std::istream;
using std::vector;
using std::string;
double Student_info::grade() const
{
	return ::grade(midterm, final, homework); 
}
string Student_info::letter_grade() const
{
	// range posts for numeric grades
	static const double numbers[] = {
	97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};
	// names for the letter grades
	static const char* const letters[] = {
	"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};
	// compute the number of grades given the size of the array
	// and the size of a single element
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
	// given a numeric grade, find and return the associated letter grade
	double grade = this->grade();
	for (size_t i = 0; i < ngrades; ++i) {
		if (grade >= numbers[i])
			return letters[i];
		}
	return "???";
}
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }	

// read homework grades from an input stream into a `vector<double>'
istream& Student_info::read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}


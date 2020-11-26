#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"
#include <stdexcept>

using std::domain_error;
using std::istream;
using std::vector;

double Student_info::grade() const
{
	//return total; for 9-1 uncomment this
	return ::grade(midterm, final, homework); 
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
	//total = ::grade(midterm, final, homework); for 9-1 uncomment this  
	return in;
}


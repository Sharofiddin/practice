#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"
#include <stdexcept>
#include <sstream>

using std::domain_error;
using std::istream;
using std::vector;

int Student_info::created = 0;
int Student_info::copied = 0;
int Student_info::assigned = 0;
int Student_info::destroyed = 0;
double Student_info::grade() const
{
  if(!valid()){
		std::stringstream ss;
		ss << "student <"<< n << "> has done none homework\n";
		throw domain_error(ss.str());
	}
	return ::grade(midterm, final, homework);
}

bool compare(const Student_info &x, const Student_info &y)
{
	return x.name() < y.name();
}

Student_info::Student_info() : midterm(0), final(0)
{
	Student_info::created++;
}

Student_info::Student_info(istream &is)
{
	Student_info::created++;
	read(is);
}

Student_info::~Student_info()
{
	Student_info::destroyed++;
}

Student_info::Student_info(const Student_info &info)
{
	Student_info::copied++;
}
Student_info Student_info::operator=(const Student_info &info)
{
	Student_info::assigned++;
	return *this;
}
// read homework grades from an input stream into a `vector<double>'
istream& Student_info::read_hw(istream &in)
{
	if (in)
	{
		// get rid of previous contents
		homework.clear();

		// read homework grades
		double x;
		while (in >> x)
			homework.push_back(x);
		// clear the stream so that input will work for the next student
		in.clear();
	} else{
		std::cout << "in false\n";
	}	
	return in;
}

istream& Student_info::read(istream &in)
{
	in >> n >> midterm >> final;
	return read_hw(in);
}

#include <algorithm>

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::min;
#endif

#include "Core.h"
#include "grade.h"
using std::istream;
using std::string;
using std::vector;
std::istream &read_hw(std::istream &in, std::vector<double> &hw);

string Core::name() const
{
	// std::cerr << "Core::name()\n"; //13-1
	return n;
}

double Core::grade() const
{
	// std::cerr << "Core::grade()\n"; //13-1
	return ::grade(midterm, final, homework);
}

istream &Core::read_common(istream &in)
{
	// read and store the student's name and exam grades
	in >> n >> midterm >> final;
	return in;
}

istream &Core::read(istream &in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

bool Core::valid() const
{
	return !homework.empty();
}

std::string Core::letter_grade() const
{
	// range posts for numeric grades
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
	// names for the letter grades
	static const char *const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
	// compute the number of grades given the size of the array
	// and the size of a single element
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
	// given a numeric grade, find and return the associated letter grade
	double grade_val = grade();
	for (size_t i = 0; i < ngrades; ++i)
	{
		if ( grade_val >= numbers[i])
			return letters[i];
	}
	return "?\?\?";
}

istream &Grad::read(istream &in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const
{
	// std::cout << "Grad::grade()\n"; //13-2
	return min(Core::grade(), thesis);
}
bool Grad::valid() const 
{
	return Core::valid() && thesis > 0;
}

double Credit::grade() const
{
	if(homework.empty())
		return (midterm + final) / 2.0;
	return Core::grade();
}

bool Credit::valid() const
{
	return true;
}

std::istream& Credit::read(std::istream& is)
{
	return Core::read(is);
}

std::istream& Audit::read(std::istream& is)
{
	is >> n;
	return is;
}

bool Audit::valid() const
{
	return true;
}

double Audit::grade() const
{
	return 0;
}

std::string Audit::letter_grade() const
{
	throw std::domain_error("Audit student");
}
bool compare(const Core &c1, const Core &c2)
{
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core *cp1, const Core *cp2)
{
	return compare(*cp1, *cp2);
}

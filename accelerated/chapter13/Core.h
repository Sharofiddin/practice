#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Core {
public:
	Core(): midterm(0), final(0) {
		 std::cerr << "Core()" << std::endl;
		 }
	Core(std::istream& is) { 
		std::cerr << "Core(std::istream&)" << std::endl;
		read(is);
		 }

	std::string name() const;
	bool valid() const; //13-3
	std::string letter_grade() const; //13-4
	// as defined in 13.1.2/230
	virtual std::istream& read(std::istream&);
	virtual double grade() const;

	virtual ~Core() { }

protected:
	// accessible to derived classes
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

	virtual Core* clone() const { return new Core(*this); }

private:
	// accessible only to `Core'
	std::string n;
	friend class Student_info;
};

class Grad: public Core {
public:
	Grad(): thesis(0) { std::cerr << "Grade()" <<std::endl; }
	Grad(std::istream& is) { read(is);std::cerr << "Grade(std::istream &)" <<std::endl; }

	// as defined in 13.1.2/230; Note: `grade' and `read' are `virtual' by inheritance
	double grade() const;
	std::istream& read(std::istream&);
private:
	double thesis;
#ifdef _MSC_VER
	Core* clone() const { return new Grad(*this); }
#else
	Grad* clone() const { return new Grad(*this); }
#endif
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core* cp1, const Core* cp2);

#endif


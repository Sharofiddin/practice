#include <iostream>

#include "Core.h"
#include "Student_info.h"

using std::istream;

istream& Student_info::read(istream& is)
{
	delete cp;          // delete previous object, if any

	char ch;
	is >> ch;           // get record type

	switch(ch){
		case 'U': cp = new Core(is); break;
		case 'G': cp = new Grad(is); break;
		case 'C': cp = new Credit(is); break;
		case 'A': cp = new Audit(is); break;
		default: std::cerr << "Invalid student type\n";break;
	}
	
	return is;
}

Student_info::Student_info(const Student_info& s): cp(0)
{
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}


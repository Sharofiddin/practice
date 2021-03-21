#include <iostream>

#include "Core.h"
#include "Student_info.h"

using std::istream;

istream& Student_info::read(istream& is)
{
	delete cp;          // delete previous object, if any

	char ch;
	is >> ch;           // get record type

	// if (ch == 'U') {
	// 	cp = new Core(is);
	// } else {
	// 	cp = new Grad(is);
	// }

	switch(ch){
		case 'U': cp = new Core(is); break;
		case 'G': cp = new Grad(is); break;
		case 'C': cp = new Credit(is); break;
		case 'A': cp = new Audit(is); break;
		default: 
			cp = 0; //there is pitfall, if you don't do this segmentation fault will occur,
					// caused by uninitialzed pointer
			break;
	}
	
	return is;
}

Student_info::Student_info(const Student_info& s): cp(0)
{
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
	#ifndef EX_13_9
		if (&s != this) { // for 13-9 checking comment this condition 
	#endif
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	#ifndef EX_13_9
		}
	#endif
	return *this;
}


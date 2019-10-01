#include <iomanip>
#include <algorithm>
#include "Student_info.h"
#include "grade.h"
#include <list>

using std::cin;		using std::cout;
using std::max;		using std::vector; 
using std::sort;	using std::string;
using std::endl;	using std::setw;
using std::list;
list<Student_info> extract_fails( list<Student_info>& );
void print(const list<Student_info> &, string::size_type);
int main()
{
	list<Student_info> vs;
	Student_info s;
	string::size_type maxlen = 0;
	while(read( cin, s)){
		maxlen = max( maxlen, s.name.size());
		vs.push_back(s);
		}
	list<Student_info> fails = extract_fails(vs);
	fails.sort(compare);
	print(fails, maxlen);
	return 0;
}


list<Student_info> extract_fails( list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while( iter != students.end()){
		if( fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			iter++;
	}
	return fail;
}

void print(const list<Student_info>& ls, string::size_type maxlen)
{
	cout << endl;
	for(list<Student_info>::const_iterator iter = ls.begin(); iter != ls.end(); iter++){
		cout << setw(maxlen) << iter->name <<' '<< grade(*iter) << endl;
	}
}

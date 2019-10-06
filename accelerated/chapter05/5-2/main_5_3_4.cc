//this solution for 5-3 and 5-4
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
vector<Student_info> extract_fail( vector<Student_info>& );
vector<Student_info> extract_fail( list<Student_info>&);
void print(const vector<Student_info> &, string::size_type);
int main()
{
	string type;
	cin >> type;
	typedef list<Student_info> my_collection ;
	if( type == "0")
		typedef vector<Student_info> my_collection;
	my_collection studentInfos;
	Student_info student;
	string::size_type maxlen = 0; 
	while( read(cin, student)){
		maxlen = max(maxlen, student.name.size());
		studentInfos.push_back(student);
	}
	cout << endl;
	vector<Student_info>fails = extract_fail(studentInfos);
	for(vector<Student_info>::const_iterator iter = fails.begin(); iter != fails.end(); iter++){
		cout << setw(maxlen) << iter->name <<' '<< grade(*iter) << endl;
	}
	return 0;
}


vector<Student_info> extract_fail( list<Student_info>& students)
{
	vector<Student_info> fail;
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


vector<Student_info> extract_fail( vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	while( iter != students.end()){
		if( fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			iter++;
	}
	return fail;
}
